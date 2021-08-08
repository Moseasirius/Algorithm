//
// Created by mozhenhai on 2021/8/6.
//

#ifndef STLUSAGETEST_TESTALL_H
#define STLUSAGETEST_TESTALL_H

#include "testVector.h"
#include "testDeque.h"
#include "testList.h"
#include "testMap.h"
#include "testString.h"
#include "testPriority_queue.h"
#include "testQueue.h"
#include "testStack.h"


void testVectorAll() {

    TestVector::testVector();
    TestVector::testOperator();
    TestVector::testOperator1();
    TestVector::testAssign();
    TestVector::testBeginEnd();
    TestVector::testRBeginREnd();
    TestVector::testBack();
    TestVector::testFront();
    TestVector::testPush_back();
    TestVector::testPop_back();
    TestVector::testInsert();
    TestVector::testErase();
    TestVector::testClear();
    TestVector::testEmpty();
    TestVector::testSize();
    TestVector::testResize();
    TestVector::testSwap();
    TestVector::testGetAllocator();
    TestVector::testAt();
    TestVector::testCapacity();
}

void testDequeAll() {
    TestDeque::testDeque();
    TestDeque::testOperator();
    TestDeque::testAssign();
    TestDeque::testBeginEnd();
    TestDeque::testBack();
    TestDeque::testFront();
    TestDeque::testPopPush();
    TestDeque::testInset();
    TestDeque::testErase();
    TestDeque::testClear();
    TestDeque::testEmpty();
    TestDeque::testSize();
    TestDeque::testSwap();
    TestDeque::testGetAllocator();
    TestDeque::testAt();
    TestDeque::testMaxSize();

}

void testListAll() {
    TestList::testList();
    TestList::testOperator();
    TestList::testAssign();
    TestList::testBeginEnd();
    TestList::testBack();
    TestList::testFront();
    TestList::testPopPush();
    TestList::testInsert();
    TestList::testErase();
    TestList::testClear();
    TestList::testEmpty();
    TestList::testSize();
    TestList::testResize();
    TestList::testSwap();
    TestList::testGetAllocator();
    TestList::testSort();

}

void testMapALl() {
    TestMap::testOperator();
    TestMap::testBeginEnd();
    TestMap::testInert();
    TestMap::testErase();
    TestMap::testClear();
    TestMap::testFind();
    TestMap::testCount();
    TestMap::testSizeAndSwap();
    TestMap::testGetAllocator();
    TestMap::testKeyComp();
    TestMap::testValueComp();
    TestMap::testBound();
    TestMap::testMaxSize();
    TestMap::testEqualRange();

}

void testStringAll() {

    TestString::testString();
    TestString::testAssign();
    TestString::testAppend();
    TestString::testBeginEnd();
    TestString::testPopPush();
    TestString::testInsert();
    TestString::testErase();
    TestString::testClear();
    TestString::testEmpty();
    TestString::testCStr();
    TestString::testCopy();
    TestString::testLength();
    TestString::testCapacity();
    TestString::testMaxSize();
    TestString::testSwap();
    TestString::testFind();
    TestString::testSubstr();
    TestString::testAt();
    TestString::testCompare();
}

void testPriorityQueue() {

    TestPriorityQueque::testPriorityQueque();

}

void testQueueAll() {

    TestQueue::testQueue();

}

void testStack() {
    TestStack::testStack();
}

#endif //STLUSAGETEST_TESTALL_H
