//Tyler Morgan
//Word.cpp

#include "Word.h"

namespace Binary
{
  Word::Word(unsigned short value =0)
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
}

