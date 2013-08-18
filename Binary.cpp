//Tyler Morgan
//Word.cpp

#include "Binary.h"

namespace Binary
{
  //definitions for Byte
  Byte::Byte(unsigned char value)
   :my_value(value) {}
  Byte::operator unsigned char() const
  {
    return my_value;
  }
Byte& Byte::operator =(Byte const& original)
  {
    this->my_value = original.my_value;
    return *this;
  }

  Byte& Byte::operator =(unsigned char value)
  {
    this->my_value = value;
    return *this;
  }




  //definitions for Word
  Word::Word(unsigned short value)
    :my_value(value) {}
  Word::operator unsigned short () const
  {
    return my_value;
  }

  Word& Word::operator =(Word const& original)
  {
    this->my_value = original.my_value;
    return *this;
  }

  Word& Word::operator =(unsigned short value)
  {
    this->my_value = value;
    return *this;
  }


  //definitnions for DoubleWord
  DoubleWord::DoubleWord(unsigned long value)
    :my_value(value) {}
  DoubleWord::operator unsigned long () const
  {
    return my_value;
  }

  DoubleWord& DoubleWord::operator = (DoubleWord const& original)
  {
    this->my_value = original.my_value;
    return *this;
  }

  DoubleWord& DoubleWord::operator =(unsigned long value)
  {
    this->my_value = value;
    return *this;
  }
}

