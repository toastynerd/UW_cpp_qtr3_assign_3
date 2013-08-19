//Tyler Morgan
//Bitmap.h

#pragma once
#include "Binary.h"
#include "WindowsBitmapHeader.h"
#include "Color.h"
#include <list>
#include <vector>

namespace Bitmap
{
  class Bitmap
  {
  public:
    Bitmap(int height, int width);
    Bitmap(WindowsBitmapHeader& header);
    Bitmap(std::istream& sourceStream);
    //I was having trouble using iterators and 
    //Have been working on this for the last 12 hours
    //So i converted it to vectors, much easier
    //but I'm sure there's some reason I wouldn't
    //want to do this
    typedef std::vector<Color> ScanLine;

    void write(std::ostream& destination_stream);

    int getWidth();
    int getHeight();

  private:
    typedef std::vector<ScanLine> ScanLineCollection;
    ScanLineCollection my_scanLines;
    WindowsBitmapHeader my_header;
  };
}

