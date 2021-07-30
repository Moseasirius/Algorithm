#include <iostream>
#include "UnionFindTestHelper.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    int n = 100000;
    UnionFindTestHelper::testUF1(n);
    UnionFindTestHelper::testUF2(n);
    UnionFindTestHelper::testUF3(n);

    return 0;
}
