//Tyler Morgan
//WindowsBitmapheader.h
#include "Binary.h"

namespace Bitmap
{
  class WindowsBitmapHeader
  {
  public:
    void WindosBitmapHeader(std::istream inputStream);
    void writeFileHeader(std::ostream destinationStream) const
  }

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
    static Binary::DbouleWord compressedImageSize;
    static Binary::DoubleWord horizontalPixelsPerMeter;
    static Binary::DoubleWord verticalPixelsPerMeter;
    static Binary::DoubleWord numberOfColors;
    static Binary::DoubleWord numberOfImportantColors;
}
