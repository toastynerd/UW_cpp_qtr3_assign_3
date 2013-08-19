//Tyler Morgan
//WindowsBitmapheader.h
#include "WindowsBitmapHeader.h"

namespace Bitmap
{
  Binary::Byte WindowsBitmapHeader::firstIdentifier('B');
  Binary::Byte WindowsBitmapHeader::secondIdentifier('M');
  Binary::DoubleWord WindowsBitmapHeader::reserved(0);
  Binary::DoubleWord WindowsBitmapHeader::rawImageByteOffset(54);
  Binary::DoubleWord WindowsBitmapHeader::infoHeaderBytes(40);
  Binary::Word WindowsBitmapHeader::numberOfPlanes(1);
  Binary::Word WindowsBitmapHeader::bitsPerPixel(24);
  Binary::DoubleWord WindowsBitmapHeader::compressionType(0);
  Binary::DoubleWord WindowsBitmapHeader::compressedImageSize(0);
  Binary::DoubleWord WindowsBitmapHeader::horizontalPixelsPerMeter(0);
  Binary::DoubleWord WindowsBitmapHeader::verticalPixelsPerMeter(0);
  Binary::DoubleWord WindowsBitmapHeader::numberOfColors(0);
  Binary::DoubleWord WindowsBitmapHeader::numberOfImportantColors(0);

  WindowsBitmapHeader::WindowsBitmapHeader(int width, int height)
    :bitmapWidth(width),
    bitmapHeight(height)
  {
    fileSize = 54 + (width * height) * 3; 
  }

  WindowsBitmapHeader::WindowsBitmapHeader(Binary::DoubleWord width, Binary::DoubleWord height, Binary::DoubleWord file_size)
    :bitmapWidth(width),
    bitmapHeight(height),
    fileSize(file_size)
  {

  }

  int WindowsBitmapHeader::size()
  {
    return fileSize;
  }

  void WindowsBitmapHeader::writeFileHeader(std::ostream& destinationStream) 
  {
    firstIdentifier.write(destinationStream);
    secondIdentifier.write(destinationStream);
    fileSize.writeLittleEndian(destinationStream);
    reserved.writeLittleEndian(destinationStream);
    rawImageByteOffset.writeLittleEndian(destinationStream);
    infoHeaderBytes.writeLittleEndian(destinationStream);
    bitmapWidth.writeLittleEndian(destinationStream);
    bitmapHeight.writeLittleEndian(destinationStream);
    numberOfPlanes.writeLittleEndian(destinationStream);
    bitsPerPixel.writeLittleEndian(destinationStream);
    compressionType.writeLittleEndian(destinationStream);
    compressedImageSize.writeLittleEndian(destinationStream);
    horizontalPixelsPerMeter.writeLittleEndian(destinationStream);
    verticalPixelsPerMeter.writeLittleEndian(destinationStream);
    numberOfColors.writeLittleEndian(destinationStream);
    numberOfImportantColors.writeLittleEndian(destinationStream);
  }

  WindowsBitmapHeader WindowsBitmapHeader::readFileHeader(std::istream& inputStream)
  {
    firstIdentifier.read(inputStream);
    secondIdentifier.read(inputStream);
    Binary::DoubleWord file_size = fileSize.readLittleEndian(inputStream);
    reserved.readLittleEndian(inputStream);
    rawImageByteOffset.readLittleEndian(inputStream);
    infoHeaderBytes.readLittleEndian(inputStream);
    Binary::DoubleWord width = bitmapWidth.readLittleEndian(inputStream);
    Binary::DoubleWord height = bitmapHeight.readLittleEndian(inputStream);
    numberOfPlanes.readLittleEndian(inputStream);
    bitsPerPixel.readLittleEndian(inputStream);
    compressionType.readLittleEndian(inputStream);
    compressedImageSize.readLittleEndian(inputStream);
    horizontalPixelsPerMeter.readLittleEndian(inputStream);
    verticalPixelsPerMeter.readLittleEndian(inputStream);
    numberOfColors.readLittleEndian(inputStream);
    numberOfImportantColors.readLittleEndian(inputStream);

    WindowsBitmapHeader header(width, height, file_size);
    return header;
  }

}
