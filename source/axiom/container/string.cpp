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
#include <axiom/container/string.hpp>

///////////////////////////////////////////////////////////////////////////////
// Forward String from ax::container
///////////////////////////////////////////////////////////////////////////////
using ax::container::String;

///////////////////////////////////////////////////////////////////////////////
// Forward Iterators from ax::container::String
///////////////////////////////////////////////////////////////////////////////
using ConstIterator = String::ConstIterator;
using Iterator = String::Iterator;
using ConstReverseIterator = String::ConstReverseIterator;
using ReverseIterator = String::ReverseIterator;

///////////////////////////////////////////////////////////////////////////////
String::StringIterator::StringIterator(char* first, const Uint64* size,
    Uint64 pos) : first(first), size(size), pos(pos) {}

///////////////////////////////////////////////////////////////////////////////
ConstIterator::ConstIterator(void) {}

///////////////////////////////////////////////////////////////////////////////
ConstIterator::ConstIterator(String::StringIterator iterator)
    : current(iterator) {}

///////////////////////////////////////////////////////////////////////////////
const char& ConstIterator::operator[](Int64 index) const
{
    return (_randomAccess(index));
}

///////////////////////////////////////////////////////////////////////////////
const char& ConstIterator::operator*(void) const
{
    return (retrieve());
}

///////////////////////////////////////////////////////////////////////////////
ConstIterator ConstIterator::operator+(Uint64 rhs)
{
    ConstIterator toReturn;
    _add(toReturn, rhs);
    return (toReturn);
}

///////////////////////////////////////////////////////////////////////////////
ConstIterator ConstIterator::operator-(Uint64 rhs)
{
    ConstIterator toReturn;
    _subtract(toReturn, rhs);
    return (toReturn);
}

///////////////////////////////////////////////////////////////////////////////
ConstIterator& ConstIterator::operator++(void)
{
    _increment();
    return (*this);
}

///////////////////////////////////////////////////////////////////////////////
ConstIterator ConstIterator::operator++(int)
{
    ConstIterator old = *this;
    _increment();
    return (old);
}

///////////////////////////////////////////////////////////////////////////////
ConstIterator& ConstIterator::operator--(void)
{
    _decrement();
    return (*this);
}

///////////////////////////////////////////////////////////////////////////////
ConstIterator ConstIterator::operator--(int)
{
    ConstIterator old = *this;
    _decrement();
    return (old);
}

///////////////////////////////////////////////////////////////////////////////
bool ConstIterator::operator==(const ConstIterator& rhs)
{
    return (
        (current.first == rhs.current.first) &&
        (current.pos == rhs.current.pos)
    );
}

///////////////////////////////////////////////////////////////////////////////
bool ConstIterator::operator!=(const ConstIterator& rhs)
{
    return (
        (current.first != rhs.current.first) ||
        (current.pos != rhs.current.pos)
    );
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD char& ConstIterator::retrieve(void) const
{
    return (*(current.first + current.pos));
}

///////////////////////////////////////////////////////////////////////////////
void ConstIterator::_increment(void)
{
    CHECK(current.pos <= *current.size);
    current.pos++;
}

///////////////////////////////////////////////////////////////////////////////
void ConstIterator::_decrement(void)
{
    CHECK(current.pos != 0);
    current.pos--;
}

///////////////////////////////////////////////////////////////////////////////
AXIOM_NODISCARD char& ConstIterator::_randomAccess(Uint64 index) const
{
    CHECK(index < *current.size);
    return (*(current.first + index));
}

///////////////////////////////////////////////////////////////////////////////
void ConstIterator::_add(ConstIterator& toReturn, Uint64 addition)
{
    CHECK(current.pos + addition <= *current.size);
    toReturn = *this;
    toReturn.current.pos += addition;
}

///////////////////////////////////////////////////////////////////////////////
void ConstIterator::_subtract(ConstIterator& toReturn, Uint64 substraction)
{
    CHECK(current.pos >= substraction);
    toReturn = *this;
    toReturn.current.pos -= substraction;
}

///////////////////////////////////////////////////////////////////////////////
Iterator::Iterator(void) : m_myBase() {}

///////////////////////////////////////////////////////////////////////////////
Iterator::Iterator(String::StringIterator iterator) : m_myBase(iterator) {}

///////////////////////////////////////////////////////////////////////////////
char& Iterator::operator[](Uint64 index)
{
    return (m_myBase::_randomAccess(index));
}

///////////////////////////////////////////////////////////////////////////////
const char& Iterator::operator[](Uint64 index) const
{
    return (m_myBase::operator[](index));
}

///////////////////////////////////////////////////////////////////////////////
char& Iterator::operator*(void)
{
    return (m_myBase::retrieve());
}

///////////////////////////////////////////////////////////////////////////////
const char& Iterator::operator*(void) const
{
    return (m_myBase::operator*());
}

///////////////////////////////////////////////////////////////////////////////
Iterator Iterator::operator+(Uint64 rhs)
{
    Iterator toReturn;
    _add(toReturn, rhs);
    return (toReturn);
}

///////////////////////////////////////////////////////////////////////////////
Iterator Iterator::operator-(Uint64 rhs)
{
    Iterator toReturn;
    _subtract(toReturn, rhs);
    return (toReturn);
}

///////////////////////////////////////////////////////////////////////////////
Iterator& Iterator::operator++(void)
{
    m_myBase::_increment();
    return (*this);
}

///////////////////////////////////////////////////////////////////////////////
Iterator Iterator::operator++(int)
{
    Iterator old = *this;
    m_myBase::_increment();
    return (old);
}

///////////////////////////////////////////////////////////////////////////////
Iterator& Iterator::operator--(void)
{
    m_myBase::_decrement();
    return (*this);
}

///////////////////////////////////////////////////////////////////////////////
Iterator Iterator::operator--(int)
{
    Iterator old = *this;
    m_myBase::_decrement();
    return (old);
}

///////////////////////////////////////////////////////////////////////////////
ConstReverseIterator::ConstReverseIterator(void) : m_myBase() {}

///////////////////////////////////////////////////////////////////////////////
ConstReverseIterator::ConstReverseIterator(String::StringIterator iterator)
    : m_myBase(iterator) {}

///////////////////////////////////////////////////////////////////////////////
const char& ConstReverseIterator::operator[](Uint64 index) const
{
    return (m_myBase::operator[](index));
}

///////////////////////////////////////////////////////////////////////////////
const char& ConstReverseIterator::operator*(void) const
{
    return (m_myBase::operator*());
}

///////////////////////////////////////////////////////////////////////////////
ConstReverseIterator ConstReverseIterator::operator+(Uint64 rhs)
{
    ConstReverseIterator toReturn;
    _add(toReturn, rhs);
    return (toReturn);
}

///////////////////////////////////////////////////////////////////////////////
ConstReverseIterator ConstReverseIterator::operator-(Uint64 rhs)
{
    ConstReverseIterator toReturn;
    _subtract(toReturn, rhs);
    return (toReturn);
}

///////////////////////////////////////////////////////////////////////////////
ConstReverseIterator& ConstReverseIterator::operator++(void)
{
    _increment();
    return (*this);
}

///////////////////////////////////////////////////////////////////////////////
ConstReverseIterator ConstReverseIterator::operator++(int)
{
    ConstReverseIterator old = *this;
    _increment();
    return (old);
}

///////////////////////////////////////////////////////////////////////////////
ConstReverseIterator& ConstReverseIterator::operator--(void)
{
    _decrement();
    return (*this);
}

///////////////////////////////////////////////////////////////////////////////
ConstReverseIterator ConstReverseIterator::operator--(int)
{
    ConstReverseIterator old = *this;
    _decrement();
    return (old);
}
