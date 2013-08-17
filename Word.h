//Tyler Morgan
//Word.h

namespace Binary
{
  class Word
  {
  public:
    Word(unsigned short value);
    operator unsigned short () const;
    Word& operator =(Word const& original);
    Word& operator =(unsigned short value);
  private:
    unsigned short my_value; 
  };
}
