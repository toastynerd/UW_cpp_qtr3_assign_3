#include <iostream>
#include "TestHarness.h"
#include "../Binary.h"

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



