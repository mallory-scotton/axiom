///////////////////////////////////////////////////////////////////////////////
///
/// MIT License
///
/// Copyright(c) 2024 Mallory SCOTTON
///
/// Permission is hereby granted, free of charge, to any person obtaining a
/// copy of this software and associated documentation files (the "Software"),
/// to deal in the Software without restriction, including without limitation
/// the rights to use, copy, modify, merge, publish, distribute, sublicense,
/// and/or sell copies of the Software, and to permit persons to whom the
/// Software is furnished to do so, subject to the following coditions:
///
/// The above copyright notice and this permission notice shall be included
/// in all copies or substantial portions of the Software?
///
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
/// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
/// DEALINGS IN THE SOFTWARE.
///
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include <axiom/graphics/shader.hpp>
#include <fstream>
#include <iostream>
#include <string>

///////////////////////////////////////////////////////////////////////////////
// Forward Shader from ax::graphics
///////////////////////////////////////////////////////////////////////////////
using ax::graphics::Shader;

///////////////////////////////////////////////////////////////////////////////
Shader::Shader(std::string path, Uint32 shaderType)
{
    const Source source = Shader::loadSource(path);
    const char* src = (const char*)source.source.c_str();
    int success = 0;

    object = glCreateShader(shaderType);
    glShaderSource(object, 1, &src, 0);
    glCompileShader(object);
    glGetShaderiv(object, GL_COMPILE_STATUS, &success);

    if (success == GL_FALSE)
    {
        int logSize = 0;
        glGetShaderiv(object, GL_INFO_LOG_LENGTH, &logSize);
        char* info = new char[logSize + 1];
        glGetShaderInfoLog(object, logSize, NULL, info);
        std::string msg = source.path + '\n' + info;
        delete[] info;
        glDeleteShader(object);
        object = 0;
        throw std::runtime_error(msg.c_str());
    }
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD Uint32 Shader::getObject(void) const
{
    return (object);
}

///////////////////////////////////////////////////////////////////////////////
void Shader::getFilePath(const std::string& fullPath,
    std::string& pathWithoutFileName)
{
    size_t found = fullPath.find_last_of("/\\");
    pathWithoutFileName = fullPath.substr(0, found + 1);
}

///////////////////////////////////////////////////////////////////////////////
Shader::Source Shader::loadSource(std::string path)
{
    std::string identifier = "#include ";
    static bool isRecursiveCall = false;

    std::string fullSourceCode = "";
    std::ifstream file(path);

    if (!file.is_open())
    {
        std::cerr << "ERROR: couldn't open the shader at: ";
        std::cerr << path << '\n' << std::endl;
        return (Source{ fullSourceCode, path });
    }

    std::string buffer;
    while (std::getline(file, buffer))
    {
        if (buffer.find(identifier) != buffer.npos)
        {
            buffer.erase(0, identifier.size());

            std::string pathOfThisFile;
            getFilePath(path, pathOfThisFile);
            buffer.insert(0, pathOfThisFile);

            isRecursiveCall = true;
            fullSourceCode += loadSource(buffer).source;

            continue;
        }

        fullSourceCode += buffer + '\n';
    }

    if (!isRecursiveCall)
    {
        fullSourceCode += '\0';
    }

    file.close();

    return (Source{ fullSourceCode, path });
}
