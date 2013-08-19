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
    void writeFileHeader(std::ostream& destinationStream);
    static WindowsBitmapHeader readFileHeader(std::istream& inputStream);
    int size();
    int getWidth();
    int getHeight();

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
