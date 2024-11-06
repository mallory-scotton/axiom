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
#include <axiom/utility.hpp>

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

///////////////////////////////////////////////////////////////////////////////
void ConstReverseIterator::_increment(void)
{
    if (m_myBase::current.pos == 0)
    {
        m_myBase::current.pos = *m_myBase::current.size;
        return;
    }
    CHECK(current.pos != *current.size);
    m_myBase::_decrement();
}

///////////////////////////////////////////////////////////////////////////////
void ConstReverseIterator::_decrement(void)
{
    if (current.pos == *m_myBase::current.size)
    {
        m_myBase::current.pos = 0;
        return;
    }
    CHECK(current.pos + 1 != *m_myBase::current.size);
    m_myBase::_increment();
}

///////////////////////////////////////////////////////////////////////////////
void ConstReverseIterator::_add(ConstReverseIterator& toReturn,
    Uint64 addition)
{
    CHECK(current.pos != *m_myBase::current.size && addition);
    if (current.pos == addition - 1)
    {
        m_myBase::current.pos = *m_myBase::current.size;
        return;
    }
    CHECK(current.pos >= addition - 1);
    toReturn = *this;
    toReturn.current.pos -= addition;
}

///////////////////////////////////////////////////////////////////////////////
void ConstReverseIterator::_subtract(ConstReverseIterator& toReturn,
    Uint64 subtraction)
{
    CHECK(*m_myBase::current.size > m_myBase::current.pos + subtraction);
    toReturn = *this;
    toReturn.current.pos += subtraction;
}

///////////////////////////////////////////////////////////////////////////////
ReverseIterator::ReverseIterator(void) : m_myBase() {}

///////////////////////////////////////////////////////////////////////////////
ReverseIterator::ReverseIterator(String::StringIterator iterator)
    : m_myBase(iterator) {}

///////////////////////////////////////////////////////////////////////////////
char& ReverseIterator::operator[](Uint64 index)
{
    return (m_myBase::_randomAccess(index));
}

///////////////////////////////////////////////////////////////////////////////
const char& ReverseIterator::operator[](Uint64 index) const
{
    return (m_myBase::operator[](index));
}

///////////////////////////////////////////////////////////////////////////////
char& ReverseIterator::operator*(void)
{
    return (m_myBase::retrieve());
}

///////////////////////////////////////////////////////////////////////////////
const char& ReverseIterator::operator*(void) const
{
    return (m_myBase::operator*());
}

///////////////////////////////////////////////////////////////////////////////
ReverseIterator ReverseIterator::operator+(Uint64 rhs)
{
    ReverseIterator toReturn;
    m_myBase::_add(toReturn, rhs);
    return (toReturn);
}

///////////////////////////////////////////////////////////////////////////////
ReverseIterator ReverseIterator::operator-(Uint64 rhs)
{
    ReverseIterator toReturn;
    m_myBase::_subtract(toReturn, rhs);
    return (toReturn);
}

///////////////////////////////////////////////////////////////////////////////
ReverseIterator& ReverseIterator::operator++(void)
{
    m_myBase::_increment();
    return (*this);
}

///////////////////////////////////////////////////////////////////////////////
ReverseIterator& ReverseIterator::operator++(void)
{
    ReverseIterator old = *this;
    m_myBase::_increment();
    return (old);
}

///////////////////////////////////////////////////////////////////////////////
ReverseIterator& ReverseIterator::operator--(void)
{
    m_myBase::_decrement();
    return (*this);
}

///////////////////////////////////////////////////////////////////////////////
ReverseIterator& ReverseIterator::operator--(void)
{
    ReverseIterator old = *this;
    m_myBase::_decrement();
    return (old);
}

///////////////////////////////////////////////////////////////////////////////
String::String(void)
{
    _setCapacity(0);
    _setLength(0);
}

///////////////////////////////////////////////////////////////////////////////
String::String(const String& other)
{
    _append(other.m_str, other.m_length);
}

///////////////////////////////////////////////////////////////////////////////
String::String(const String& other, Uint64 position, Uint64 length)
{
    append(other.m_str, position, length);
}

///////////////////////////////////////////////////////////////////////////////
String::String(String&& other)
{
    *this = axu::move(other);
}

///////////////////////////////////////////////////////////////////////////////
String::String(const std::string& other)
{
    _append(other.c_str());
}

///////////////////////////////////////////////////////////////////////////////
String::String(const char* other)
{
    _append(other);
}

///////////////////////////////////////////////////////////////////////////////
String::String(const char* other, Uint64 length)
{
    append(other, 0, length);
}

///////////////////////////////////////////////////////////////////////////////
String::String(Uint64 length, char filler)
{
    append(length, filler);
}

///////////////////////////////////////////////////////////////////////////////
String::String(const ConstIterator first, const ConstIterator second)
{
    append(first, second);
}

///////////////////////////////////////////////////////////////////////////////
String::~String(void)
{
    SAFE_DELETE_ARRAY(m_str);
    m_length = 0;
    m_capacity = 0;
    m_increaseBy = 0;
}

///////////////////////////////////////////////////////////////////////////////
String& String::operator=(const String& other)
{
    if (this != &other)
    {
        _setLength(0);
        _append(other.m_str, other.m_length);
    }
    return (*this);
}

///////////////////////////////////////////////////////////////////////////////
String& String::operator=(String&& other)
{
    if (this != &other)
    {
        SAFE_DELETE_ARRAY(m_str);
        m_str = other.m_str;
        m_length = other.m_length;
        m_capacity = other.m_capacity;
        other.m_str = nullptr;
        other.m_length = 0;
        other.m_capacity = 0;
    }
    return (*this);
}

///////////////////////////////////////////////////////////////////////////////
const char& String::operator[](Uint64 index) const
{
    return (*(m_str + index));
}

///////////////////////////////////////////////////////////////////////////////
char& String::operator[](Uint64 index)
{
    return (*(m_str + index));
}

///////////////////////////////////////////////////////////////////////////////
bool String::operator==(const String& rhs)
{
    return (_compare(rhs) == 0);
}

///////////////////////////////////////////////////////////////////////////////
bool String::operator!=(const String& rhs)
{
    return (_compare(rhs) != 0);
}

///////////////////////////////////////////////////////////////////////////////
bool String::operator<(const String& rhs)
{
    return (_compare(rhs) < 0);
}

///////////////////////////////////////////////////////////////////////////////
bool String::operator<=(const String& rhs)
{
    return (_compare(rhs) <= 0);
}

///////////////////////////////////////////////////////////////////////////////
bool String::operator>(const String& rhs)
{
    return (_compare(rhs) > 0);
}

///////////////////////////////////////////////////////////////////////////////
bool String::operator>=(const String& rhs)
{
    return (_compare(rhs) >= 0);
}

///////////////////////////////////////////////////////////////////////////////
String::operator std::string(void) const
{
    return (std::string(cstr()));
}

///////////////////////////////////////////////////////////////////////////////
String::operator const char*(void) const
{
    return (cstr());
}

///////////////////////////////////////////////////////////////////////////////
Iterator String::begin(void)
{
    return (_ibegin());
}

///////////////////////////////////////////////////////////////////////////////
ConstIterator String::begin(void) const
{
    return (_ibegin());
}

///////////////////////////////////////////////////////////////////////////////
ConstIterator String::cbegin(void) const
{
    return (_ibegin());
}

///////////////////////////////////////////////////////////////////////////////
ReverseIterator String::rbegin(void)
{
    return (_rbegin());
}

///////////////////////////////////////////////////////////////////////////////
ConstReverseIterator String::rbegin(void) const
{
    return (_rbegin());
}

///////////////////////////////////////////////////////////////////////////////
ConstReverseIterator String::crbegin(void) const
{
    return (_rbegin());
}

///////////////////////////////////////////////////////////////////////////////
Iterator String::end(void)
{
    return (_end());
}

///////////////////////////////////////////////////////////////////////////////
ConstIterator String::end(void) const
{
    return (_end());
}

///////////////////////////////////////////////////////////////////////////////
ConstIterator String::cend(void) const
{
    return (_end());
}

///////////////////////////////////////////////////////////////////////////////
ReverseIterator String::rend(void)
{
    return (_end());
}

///////////////////////////////////////////////////////////////////////////////
ConstReverseIterator String::rend(void) const
{
    return (_end());
}

///////////////////////////////////////////////////////////////////////////////
ConstReverseIterator String::crend(void) const
{
    return (_end());
}

///////////////////////////////////////////////////////////////////////////////
const char& String::at(Uint64 index) const
{
    CHECK(m_length > index);
    return (operator[](index));
}

///////////////////////////////////////////////////////////////////////////////
char& String::at(Uint64 index)
{
    CHECK(m_length > index);
    return (operator[](index));
}

///////////////////////////////////////////////////////////////////////////////
const char& String::front(void) const
{
    return (operator[](0));
}

///////////////////////////////////////////////////////////////////////////////
char& String::front(void)
{
    return (operator[](0));
}

///////////////////////////////////////////////////////////////////////////////
const char& String::back(void) const
{
    return (operator[](m_length - 1));
}

///////////////////////////////////////////////////////////////////////////////
char& String::back(void)
{
    return (operator[](m_length - 1));
}

///////////////////////////////////////////////////////////////////////////////
String& String::append(const String& str)
{
    _append(str.m_str, str.m_length);
    return (*this);
}

///////////////////////////////////////////////////////////////////////////////
String& String::append(const String& str, Uint64 subPos, Uint64 subLen)
{
    char* buffer = nullptr;

    subLen = _getLength(str, subPos, subLen);
    _substr(buffer, str.m_str, subPos, subLen);
    _append(buffer, subLen);
    return (*this);
}

///////////////////////////////////////////////////////////////////////////////
String& String::append(const std::string& str)
{
    _append(str.c_str());
    return (*this);
}

///////////////////////////////////////////////////////////////////////////////
String& String::append(const char* str)
{
    _append(str);
    return (*this);
}

///////////////////////////////////////////////////////////////////////////////
String& String::append(const char* str, Uint64 length)
{
    char* buffer = nullptr;

    _substr(buffer, str, 0, length);
    _append(buffer, length);
    SAFE_DELETE(buffer);
    return (*this);
}

///////////////////////////////////////////////////////////////////////////////
String& String::append(Uint64 length, char filler)
{
    char* buffer = nullptr;

    _allocCString(buffer, length, filler);
    _append(buffer, length);
    SAFE_DELETE(buffer);
    return (*this);
}

///////////////////////////////////////////////////////////////////////////////
String& String::append(const ConstIterator first, const ConstIterator second)
{
    const Uint64 length = _getLength(first, second);

    if (length != 0)
    {
        char* buffer = nullptr;
        _allocCString(buffer, length, first, second);
        _append(buffer, length);
        SAFE_DELETE(buffer);
    }
    return (*this);
}

///////////////////////////////////////////////////////////////////////////////
String& String::append(char ch)
{
    _append(&ch, 1);
    return (*this);
}

///////////////////////////////////////////////////////////////////////////////
String& String::insert(Uint64 position, const String& other)
{
    _insertstr(position, other.m_str, other.m_length);
    return (*this);
}

///////////////////////////////////////////////////////////////////////////////
String& String::insert(Uint64 position, const String& other, Uint64 subPos,
    Uint64 subLen)
{
    char* buffer = nullptr;

    subLen = _getLength(other, subPos, subLen);
    _substr(buffer, other.m_str, subPos, subLen);
    _insertstr(position, buffer, subLen);
    SAFE_DELETE(buffer);
    return (*this);
}

///////////////////////////////////////////////////////////////////////////////
String& String::insert(Uint64 position, const std::string& other)
{
    _insertstr(position, other.c_str());
    return (*this);
}

///////////////////////////////////////////////////////////////////////////////
String& String::insert(Uint64 position, const char* other)
{
    _insertstr(position, other);
    return (*this);
}

///////////////////////////////////////////////////////////////////////////////
String& String::insert(Uint64 position, const char* other, Uint64 length)
{
    char* buffer = nullptr;

    _substr(buffer, other, 0, length);
    _insertstr(position, buffer, length);
    SAFE_DELETE(buffer);
    return (*this);
}

///////////////////////////////////////////////////////////////////////////////
String& String::insert(Uint64 position, char character)
{
    _insertstr(position, &character, 1);
    return (*this);
}

///////////////////////////////////////////////////////////////////////////////
String& String::insert(Uint64 position, Uint64 length, char filler)
{
    char* buffer = nullptr;

    _allocCString(buffer, length, filler);
    _insertstr(position, buffer, length);
    SAFE_DELETE(buffer);
    return (*this);
}

///////////////////////////////////////////////////////////////////////////////
void String::insert(Iterator pointer, Uint64 length, char filler)
{
    char* buffer = nullptr;

    _allocCString(buffer, length, filler);
    _insertstr(pointer.current.pos, buffer, length);
    SAFE_DELETE(buffer);
}

///////////////////////////////////////////////////////////////////////////////
Iterator String::insert(Iterator pointer, char character)
{
    _insertstr(pointer.current.pos, &character, 1);
    return (pointer);
}

///////////////////////////////////////////////////////////////////////////////
void String::insert(Iterator pointer, const ConstIterator first,
    const ConstIterator second)
{
    const Uint64 length = _getLength(first, second);

    if (length == 0)
    {
        return;
    }
    char* buffer = nullptr;
    _allocCString(buffer, length, first, second);
    _insertstr(pointer.current.pos, buffer, length);
    SAFE_DELETE(buffer);
}

///////////////////////////////////////////////////////////////////////////////
String& String::erase(Uint64 position, Uint64 length)
{
    _erase(position, length);
    return (*this);
}

///////////////////////////////////////////////////////////////////////////////
Iterator String::erase(ConstIterator pointer)
{
    _erase(pointer.current.pos, 1);
    return (pointer.current);
}

///////////////////////////////////////////////////////////////////////////////
Iterator String::erase(ConstIterator first, ConstIterator second)
{
    _erase(first.current.pos, _getLength(first, second));
    return (first.current);
}

///////////////////////////////////////////////////////////////////////////////
String& String::replace(Uint64 position, Uint64 length, const String& other)
{
    _replace(position, length, other.m_str, other.m_length);
    return (*this);
}

///////////////////////////////////////////////////////////////////////////////
String& String::replace(ConstIterator first, ConstIterator second,
    const String& other)
{
    replace(first.current.pos, _getLength(first, second), other.m_str,
        other.m_length);
    return (*this);
}

///////////////////////////////////////////////////////////////////////////////
String& String::replace(Uint64 position, Uint64 length, const String& other,
    Uint64 subPos, Uint64 subLen)
{
    char* buffer = nullptr;

    subLen = _getLength(other, subPos, subLen);
    _substr(buffer, other.m_str, subPos, subLen);
    _replace(position, length, buffer, ::strlen(buffer));
    SAFE_DELETE(buffer);
    return (*this);
}

///////////////////////////////////////////////////////////////////////////////
String& String::replace(Uint64 position, Uint64 length, const char* other)
{
    _replace(position, length, other, ::strlen(other));
    return (*this);
}

///////////////////////////////////////////////////////////////////////////////
String& String::replace(ConstIterator first, ConstIterator second,
    const char* other)
{
    _replace(first.current.pos, _getLength(first, second), other,
        ::strlen(other));
    return (*this);
}

///////////////////////////////////////////////////////////////////////////////
String& String::replace(Uint64 position, Uint64 length, const char* other,
    Uint64 n)
{
    _replace(position, length, other, n);
    return (*this);
}

///////////////////////////////////////////////////////////////////////////////
String& String::replace(ConstIterator first, ConstIterator second,
    const char* other, Uint64 n)
{
    _replace(first.current.pos, _getLength(first, second), other, n);
    return (*this);
}

///////////////////////////////////////////////////////////////////////////////
String& String::replace(Uint64 position, Uint64 length,
    const std::string& other)
{
    _replace(position, length, other.c_str(), other.length());
    return (*this);
}

///////////////////////////////////////////////////////////////////////////////
String& String::replace(ConstIterator first, ConstIterator second,
    const std::string& other)
{
    _replace(first.current.pos, _getLength(first, second), other.c_str(),
        other.length());
    return (*this);
}

///////////////////////////////////////////////////////////////////////////////
String& String::replace(Uint64 poisition, Uint64 length, Uint64 n, char filler)
{
    char* buffer = nullptr;

    _allocCString(buffer, n, filler);
    _replace(poisition, length, buffer, n);
    SAFE_DELETE(buffer);
    return (*this);
}

///////////////////////////////////////////////////////////////////////////////
String& String::replace(ConstIterator first, ConstIterator second,
    Uint64 length, char filler)
{
    char* buffer = nullptr;

    _allocCString(buffer, length, filler);
    _replace(first.current.pos, _getLength(first, second), buffer, length);
    SAFE_DELETE(buffer);
    return (*this);
}

///////////////////////////////////////////////////////////////////////////////
String& String::replace(ConstIterator first, ConstIterator second,
    ConstIterator third, ConstIterator four)
{
    const Uint64 length = _getLength(third, four);
    char* buffer = nullptr;

    _allocCString(buffer, length, third, four);
    _replace(first.current.pos, _getLength(first, second), buffer, length);
    SAFE_DELETE(buffer);
    return (*this);
}

///////////////////////////////////////////////////////////////////////////////
void String::swap(String& other)
{
    String temp = axu::move(*this);
    *this = axu::move(other);
    other = axu::move(temp);
}

///////////////////////////////////////////////////////////////////////////////
String& String::popBack(void)
{
    _erase((end() - 1).current.pos, 1);
    return (*this);
}

///////////////////////////////////////////////////////////////////////////////
const char* String::cstr(void) const
{
    return (m_str);
}

///////////////////////////////////////////////////////////////////////////////
Uint64 String::copy(char* str, Uint64 length, Uint64 position) const
{
    CHECK(str);
    length = _getLength(*this, position, length);
    for (Uint64 i = 0; i < length; ++i)
    {
        *(str + i) = operator[](position + i);
    }
    return (length);
}

///////////////////////////////////////////////////////////////////////////////
Uint64 String::find(const String& other, Uint64 position) const
{
    return (_find(other.m_str, other.m_length, position));
}

///////////////////////////////////////////////////////////////////////////////
Uint64 String::find(const std::string& other, Uint64 position) const
{
    return (_find(other.c_str(), other.length(), position));
}

///////////////////////////////////////////////////////////////////////////////
Uint64 String::find(const char* other, Uint64 position) const
{
    return (_find(other, ::strlen(other), position));
}

///////////////////////////////////////////////////////////////////////////////
Uint64 String::find(const char* other, Uint64 position, Uint64 length) const
{
    return (_find(other, length, position));
}

///////////////////////////////////////////////////////////////////////////////
Uint64 String::find(char ch, Uint64 position) const
{
    return (_find(&ch, 1, position));
}

///////////////////////////////////////////////////////////////////////////////
Uint64 String::rfind(const String& other, Uint64 position) const
{
    return (_rfind(other.m_str, other.m_length, position));
}

///////////////////////////////////////////////////////////////////////////////
Uint64 String::rfind(const std::string& other, Uint64 position) const
{
    return (_rfind(other.c_str(), other.length(), position));
}

///////////////////////////////////////////////////////////////////////////////
Uint64 String::rfind(const char* other, Uint64 position) const
{
    return (_rfind(other, ::strlen(other), position));
}

///////////////////////////////////////////////////////////////////////////////
Uint64 String::rfind(const char* other, Uint64 position, Uint64 length) const
{
    return (_rfind(other, length, position));
}

///////////////////////////////////////////////////////////////////////////////
Uint64 String::rfind(char ch, Uint64 position) const
{
    return (_rfind(&ch, 1, position));
}

///////////////////////////////////////////////////////////////////////////////
Uint64 String::findFirstOf(const String& other, Uint64 position) const
{

}

///////////////////////////////////////////////////////////////////////////////
Uint64 String::findFirstOf(const std::string& other, Uint64 position) const
{

}

///////////////////////////////////////////////////////////////////////////////
Uint64 String::findFirstOf(const char* other, Uint64 position) const
{

}

///////////////////////////////////////////////////////////////////////////////
Uint64 String::findFirstOf(const char* other, Uint64 position,
    Uint64 length) const
{

}

///////////////////////////////////////////////////////////////////////////////
Uint64 String::findFirstOf(char ch, Uint64 position) const
{

}

///////////////////////////////////////////////////////////////////////////////
Uint64 String::findLastOf(const String& other, Uint64 position) const
{

}

///////////////////////////////////////////////////////////////////////////////
Uint64 String::findLastOf(const std::string& other, Uint64 position) const
{

}

///////////////////////////////////////////////////////////////////////////////
Uint64 String::findLastOf(const char* other, Uint64 position) const
{

}

///////////////////////////////////////////////////////////////////////////////
Uint64 String::findLastOf(const char* other, Uint64 position,
    Uint64 length) const
{

}

///////////////////////////////////////////////////////////////////////////////
Uint64 String::findLastOf(char ch, Uint64 position) const
{

}

///////////////////////////////////////////////////////////////////////////////
Uint64 String::findFirstNotOf(const String& other, Uint64 position) const
{

}

///////////////////////////////////////////////////////////////////////////////
Uint64 String::findFirstNotOf(const std::string& other, Uint64 position) const
{

}

///////////////////////////////////////////////////////////////////////////////
Uint64 String::findFirstNotOf(const char* other, Uint64 position) const
{

}

///////////////////////////////////////////////////////////////////////////////
Uint64 String::findFirstNotOf(const char* other, Uint64 position,
    Uint64 length) const
{

}

///////////////////////////////////////////////////////////////////////////////
Uint64 String::findFirstNotOf(char ch, Uint64 position) const
{

}

///////////////////////////////////////////////////////////////////////////////
Uint64 String::findLastNotOf(const String& other, Uint64 position) const
{

}

///////////////////////////////////////////////////////////////////////////////
Uint64 String::findLastNotOf(const std::string& other, Uint64 position) const
{

}

///////////////////////////////////////////////////////////////////////////////
Uint64 String::findLastNotOf(const char* other, Uint64 position) const
{

}

///////////////////////////////////////////////////////////////////////////////
Uint64 String::findLastNotOf(const char* other, Uint64 position, Uint64 length)
    const
{

}

///////////////////////////////////////////////////////////////////////////////
Uint64 String::findLastNotOf(char ch, Uint64 position) const
{

}

///////////////////////////////////////////////////////////////////////////////
String String::substr(Uint64 position = 0, Uint64 length) const
{

}

///////////////////////////////////////////////////////////////////////////////
Uint64 String::length(void) const
{

}

///////////////////////////////////////////////////////////////////////////////
inline Uint64 String::size(void) const
{

}

///////////////////////////////////////////////////////////////////////////////
Uint64 String::maxSize(void) const
{

}

///////////////////////////////////////////////////////////////////////////////
void String::resize(Uint64 size)
{

}

///////////////////////////////////////////////////////////////////////////////
void String::resize(Uint64 size, char filler)
{

}

///////////////////////////////////////////////////////////////////////////////
Uint64 String::capacity(void) const
{

}

///////////////////////////////////////////////////////////////////////////////
void String::reserve(Uint64 n)
{

}

///////////////////////////////////////////////////////////////////////////////
void String::clear(void)
{

}

///////////////////////////////////////////////////////////////////////////////
void String::shrinkToFit(void)
{

}

///////////////////////////////////////////////////////////////////////////////
String& String::toLowerCase(void)
{

}

///////////////////////////////////////////////////////////////////////////////
String& String::toUpperCase(void)
{

}

///////////////////////////////////////////////////////////////////////////////
String& String::trim(void)
{

}

///////////////////////////////////////////////////////////////////////////////
bool String::isEmpty(void) const
{

}
