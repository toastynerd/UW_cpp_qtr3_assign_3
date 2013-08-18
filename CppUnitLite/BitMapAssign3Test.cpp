#include <iostream>
#include "TestHarness.h"
#include "../Binary.h"
#include <sstream>


TEST(Byte_Functionality, Byte)
{
  Binary::Byte byte1;
  CHECK_EQUAL(byte1, 'a');

  Binary::Byte byte2(byte1);
  CHECK_EQUAL(byte1, byte2);

  Binary::Byte byte3('b');
  byte1 = byte3;

  CHECK_EQUAL(byte1, byte3);
}


TEST(Word_Functionality, Word)
{
  Binary::Word word1(0);
  CHECK_EQUAL(word1, 0);
  Binary::Word word2(4);
  CHECK_EQUAL(word2, 4);

  Binary::Word word3(word2);
  CHECK_EQUAL(word3, word2);

  word1 = word3;

  CHECK_EQUAL(word1, word3);

  Binary::Word word4;
  CHECK_EQUAL(word4, 0);
}

TEST(DoubleWord_Functionality, Doubleword)
{
  Binary::DoubleWord doubleword1(0);
  CHECK_EQUAL(doubleword1, 0);
  Binary::DoubleWord doubleword2(4);
  CHECK_EQUAL(doubleword2, 4);

  Binary::DoubleWord doubleword3(doubleword2);
  CHECK_EQUAL(doubleword3, doubleword2);

  doubleword1 = doubleword3;

  CHECK_EQUAL(doubleword1, doubleword3);

  Binary::DoubleWord doubleword4;
  CHECK_EQUAL(doubleword4, 0);
}

TEST(ReadByte, Byte)
{
  std::stringstream ss("cde");
  Binary::Byte byte1;
  Binary::Byte byte2(byte1.read(ss));
  CHECK_EQUAL('c', byte2);
}

TEST(WriteByte, Byte)
{
  std::stringstream ss;
  Binary::Byte byte1('b');
  byte1.write(ss);
  CHECK_EQUAL("b", ss.str());
}

TEST(ReadWord, Word)
{
  unsigned char carray[] = {0xb1, 0xb2, 0};
  std::stringstream ss(reinterpret_cast<char*>(carray));

  Binary::Word expected(0xb2b1);
  Binary::Word actual = Binary::Word::readLittleEndian(ss);
  CHECK_EQUAL(expected, actual);

  ss.seekg(0);

  expected = 0xb1b2;
  actual = Binary::Word::readBigEndian(ss);
  CHECK_EQUAL(expected, actual);
}

TEST(WriteWord, Word)
{
  Binary::Word expected(0xb2b1);
  std::stringstream ss;

  expected.writeLittleEndian(ss);

  Binary::Word actual = Binary::Word::readLittleEndian(ss);
  CHECK_EQUAL(expected, actual);

  std::stringstream ss2;
  expected.writeBigEndian(ss2);

  actual = Binary::Word::readBigEndian(ss2);
  CHECK_EQUAL(expected, actual);
}

TEST(ReadDoubleWord, DoubleWord)
{
  unsigned char carray[] = {0xb1, 0xb2, 0xb3, 0xb4, 0};
  std::stringstream ss(reinterpret_cast<char*>(carray));

  Binary::DoubleWord expected(0xb4b3b2b1);
  Binary::DoubleWord actual = Binary::DoubleWord::readLittleEndian(ss);
  CHECK_EQUAL(expected,actual);

  ss.seekg(0);
  
  expected = 0xb1b2b3b4;
  actual = Binary::DoubleWord::readBigEndian(ss);
  CHECK_EQUAL(expected, actual);
}

TEST(WriteDoubleWord, DoubleWord)
{
  Binary::DoubleWord expected(0xb4b3b2b1);
  std::stringstream ss;

  expected.writeLittleEndian(ss);

  Binary::DoubleWord actual = Binary::DoubleWord::readLittleEndian(ss);
  CHECK_EQUAL(expected,actual);

  std::stringstream ss2;
  expected.writeBigEndian(ss2);

  actual = Binary::DoubleWord::readBigEndian(ss2);
  CHECK_EQUAL(expected, actual);


}
