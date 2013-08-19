CC=g++

test: 
	${LITTLE_ENDIAN}
	$(CC) -o run_tests CppUnitLite/Main.cpp \
										 CppUnitLite/Failure.cpp \
										 CppUnitLite/Test.cpp \
										 CppUnitLite/TestRegistry.cpp \
										 CppUnitLite/TestResult.cpp \
										 CppUnitLite/BitMapAssign3Test.cpp \
										 Binary.cpp \
										 WindowsBitmapHeader.cpp \
										 Color.cpp \
										 Bitmap.cpp
	
	./run_tests
