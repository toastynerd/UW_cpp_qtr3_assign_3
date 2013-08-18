//Tyler Morgan
//Word.h

namespace Binary
{
  class Byte
  {
  public:
    Byte(unsigned char value = 'a');
    operator unsigned char () const;
    Byte& operator =(Byte const& original);
    Byte& operator =(unsigned char value);
  private:
    unsigned char my_value;
  };

  class Word
  {
  public:
    Word(unsigned short value = 0);
    operator unsigned short () const;
    Word& operator =(Word const& original);
    Word& operator =(unsigned short value);
  private:
    unsigned short my_value; 
  };

  class DoubleWord
  {
  public:
    DoubleWord(unsigned long value = 0);
    operator unsigned long () const;
    DoubleWord& operator =(DoubleWord const& original);
    DoubleWord& operator =(unsigned long value);
  private:
    unsigned long my_value;
  };

}
