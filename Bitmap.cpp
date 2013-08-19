//Tyler Morgan
//Bitmap.cpp
//

#include "Bitmap.h"

namespace Bitmap
{
  Bitmap::Bitmap(WindowsBitmapHeader& header)
    :my_header(header)
  {

  }

  Bitmap::Bitmap(std::istream& sourceStream)
    :my_header(WindowsBitmapHeader::readFileHeader(sourceStream))
  {
    for(int y = 0; y < my_header.getHeight(); y++)
    {    
      ScanLine temp_scanline;
      for(int x = 0; x < my_header.getWidth(); x++)
      {
        Color::Color temp_color;
        temp_color.read(sourceStream);
        temp_scanline.push_back(temp_color);
      }
      my_scanLines.push_back(temp_scanline);
    }
  }

  void Bitmap::write(std::ostream& destinationStream)
  {
    //I was having trouble using iterators and 
    //Have been working on this for the last 12 hours
    //So i converted it to vectors, much easier
    //but I'm sure there's some reason I wouldn't
    //want to do this
    my_header.writeFileHeader(destinationStream);
    for(int y = 0;y < my_header.getHeight(); y++)
    {
      for(int x = 0; x <my_header.getWidth(); x++)
      {
        my_scanLines[y][x].write(destinationStream);
      }
    }
  }

  int Bitmap::getWidth()
  {
    return my_header.getWidth();
  }

  int Bitmap::getHeight()
  {
    return my_header.getHeight();
  }
}
