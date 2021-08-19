#include <iostream>
#include "TextFileIO.h"

#include "TextFile.h"
#include "BinaryOutput.h"
#include "RandomAccessFile.h"
#include "UpdateFile.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
//    testTextFileOutput();
//    testTextFileInput();
//    testEndOfFile();
//    testCheckFile();
//    testWriteFormattedData();
//    testReadCity();
//    testAppendFile();
//    testShowStreamState();
//    testBinaryIntOutput();
//    testBinaryIntInput();
//    testBinaryCharOutput();
//    testBinaryCharInput();
//    testBinaryArray();
    testBinaryObjectIO();
    testRandomAccessFile();
    testUpdateFile();


    return 0;
}
