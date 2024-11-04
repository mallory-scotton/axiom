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

///////////////////////////////////////////////////////////////////////////////
// Namespace ax::graphics
///////////////////////////////////////////////////////////////////////////////
namespace ax::graphics
{

///////////////////////////////////////////////////////////////////////////////
// Forward declarations
///////////////////////////////////////////////////////////////////////////////
typedef sf::Event Event;
typedef sf::Keyboard Keyboard;
typedef sf::Mouse Mouse;
typedef sf::Joystick Joystick;
typedef sf::Cursor Cursor;
typedef sf::Touch Touch;
typedef sf::Sensor Sensor;
typedef sf::Clipboard Clipboard;
typedef sf::ContextSettings ContextSettings;
typedef sf::VideoMode VideoMode;
typedef sf::RenderWindow Window;

///////////////////////////////////////////////////////////////////////////////
// Namespace forward
///////////////////////////////////////////////////////////////////////////////
namespace Style = sf::Style;

} // namespace ax::graphics
