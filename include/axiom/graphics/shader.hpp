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
// Pragma once
///////////////////////////////////////////////////////////////////////////////
#pragma once

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include <axiom/graphics/dependencies.hpp>
#include <axiom/config.hpp>
#include <axiom/math/types.hpp>

#include <axiom/container/string.hpp>
#include <axiom/math/vector2.hpp>
#include <axiom/math/vector3.hpp>
#include <axiom/math/vector4.hpp>

///////////////////////////////////////////////////////////////////////////////
// Namespace ax::graphics
///////////////////////////////////////////////////////////////////////////////
namespace ax::graphics
{

///////////////////////////////////////////////////////////////////////////////
/// \brief
///
///////////////////////////////////////////////////////////////////////////////
struct Shader
{
public:
    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    ///////////////////////////////////////////////////////////////////////////
    enum Type
    {
        Fragment,
        Vertex
    };

public:
    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    ///////////////////////////////////////////////////////////////////////////
    Uint32 object;              //<!

private:
    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    ///////////////////////////////////////////////////////////////////////////
    struct Source
    {
        axc::String source;     //<!
        axc::String path;       //<!
    };

public:
    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \param path
    /// \param type
    ///
    ///////////////////////////////////////////////////////////////////////////
    Shader(const axc::String& path, Shader::Type type);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \param vertexShaderPath
    /// \param fragmentShaderPath
    ///
    ///////////////////////////////////////////////////////////////////////////
    Shader(const axc::String& vertexShaderPath,
        const axc::String& fragmentShaderPath);

public:
    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \param name
    /// \param x
    ///
    ///////////////////////////////////////////////////////////////////////////
    void setUniform(const axc::String& name, float x);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \param name
    /// \param x
    ///
    ///////////////////////////////////////////////////////////////////////////
    void setUniform(const axc::String& name, int x);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \param name
    /// \param x
    ///
    ///////////////////////////////////////////////////////////////////////////
    void setUniform(const axc::String& name, const axm::Vector2& x);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \param name
    /// \param x
    ///
    ///////////////////////////////////////////////////////////////////////////
    void setUniform(const axc::String& name, const axm::Vector3& x);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \param name
    /// \param x
    ///
    ///////////////////////////////////////////////////////////////////////////
    void setUniform(const axc::String& name, const axm::Vector4& x);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \param name
    /// \param x
    ///
    ///////////////////////////////////////////////////////////////////////////
    void setUniform(const axc::String& name, bool x);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \return
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD GLuint getNativeHandle(void) const;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    ///////////////////////////////////////////////////////////////////////////
    void bind(void) const;

private:
    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \param name
    ///
    /// \return
    ///
    ///////////////////////////////////////////////////////////////////////////
    AXIOM_NODISCARD int getUniformLocation(const axc::String& name);

public:
    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \param shader
    ///
    ///////////////////////////////////////////////////////////////////////////
    static void bind(const Shader& shader);
};

} // namespace ax::graphics
