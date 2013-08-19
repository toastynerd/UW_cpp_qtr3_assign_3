//Tyler Morgan
//WindowsBitmapheader.h
#pragma once
#include <iostream>
#include "Binary.h"

namespace Bitmap
{
  class WindowsBitmapHeader
  {
  public:
    WindowsBitmapHeader(int width, int height);
    WindowsBitmapHeader(Binary::DoubleWord width, Binary::DoubleWord height, Binary::DoubleWord file_size);
    WindowsBitmapHeader& operator =(WindowsBitmapHeader const& original);
    WindowsBitmapHeader& operator =(int width, height, file_size);
    WindowsBitmapHeader& operator =(Binary::DoubleWord width, Binary::DoubleWord height, Binary::DoubleWord file_size);
    void writeFileHeader(std::ostream& destinationStream);
    WindowsBitmapHeader readFileHeader(std::istream& inputStream);
    int size();

  private:
    //file header
    static Binary::Byte firstIdentifier;
    static Binary::Byte secondIdentifier;
    Binary::DoubleWord fileSize;
    static Binary::DoubleWord reserved;
    static Binary::DoubleWord rawImageByteOffset;

    //info header
    static Binary::DoubleWord infoHeaderBytes;
    Binary::DoubleWord bitmapWidth;
    Binary::DoubleWord bitmapHeight;
    static Binary::Word numberOfPlanes;
    static Binary::Word bitsPerPixel;
    static Binary::DoubleWord compressionType;
    static Binary::DoubleWord compressedImageSize;
    static Binary::DoubleWord horizontalPixelsPerMeter;
    static Binary::DoubleWord verticalPixelsPerMeter;
    static Binary::DoubleWord numberOfColors;
    static Binary::DoubleWord numberOfImportantColors;
  };
}
