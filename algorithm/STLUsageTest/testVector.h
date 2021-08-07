//
// Created by mozhenhai on 2021/8/5.
//

#ifndef STLUSAGETEST_TESTVECTOR_H
#define STLUSAGETEST_TESTVECTOR_H

#include <vector>
#include <iostream>
#include <ctime>

using namespace std;

namespace TestVector {
    void testVector() {
        //vector::vector()函数 功能 构造函数
        //constructors used in the same order as described above:
        vector<int> first;//empty vector of ints
        vector<int> second(4, 11);//four ints with value 100
        vector<int> third(second.begin(), second.end());
        //iterating through second
        vector<int> fourth(third);//copy of third
        //the iterator constructor can also be used to construct from arrays
        int myInts[] = {1998, 11, 3, 5, 2, 0, 13, 14};
        vector<int> fifth(myInts, myInts + sizeof(myInts) / sizeof(int));

        cout << "The contents of first are:";
        for (int i : first) {
            cout << " " << i;
        }
        cout << endl;
        cout << "The contents of second are:";
        for (int i : second) {
            cout << " " << i;
        }
        cout << endl;

        cout << "The contents of third are:";
        for (int i : third) cout << " " << i;
        cout << endl;

        cout << "The contents of fourth are:";
        for (int i : fourth) {
            cout << " " << i;
        }
        cout << endl;
        cout << "The contents of fifth are:";
        for (int i : fifth) {
            cout << " " << i;
        }
        cout << endl;
        cout << "------------------------------------------" << endl;
    }

    void testOperator() {
        vector<int> first(3, 1);
        vector<int> second(5, 0);
        cout << "first contains:";
        for (int i : first) cout << " " << i;
        cout << endl;

        first = vector<int>(6, 2);
        cout << "first contains:";
        for (int i : first) cout << " " << i;
        cout << endl;
        cout << "Size of first:" << int(first.size()) << endl;
        second = first;
        first = vector<int>();
        cout << "Size of first:" << int(first.size()) << endl;
        cout << "Size of second:" << int(second.size()) << endl;
        cout << "------------------------------------------" << endl;
    }

    void testOperator1() {
        //vector::operator[]()函数 功能：获取指定位置
        vector<int> myVector(10);//10 zero-initialized elements

        vector<int>::size_type sz = myVector.size();
        for (int i = 0; i < sz; i++) myVector[i] = i;

        cout << "myVector contains:";

        for (int i : myVector) cout << " " << i;
        cout << endl;

        for (int i = 0; i < sz / 2; i++) {
            int temp;
            temp = myVector[sz - 1 - i];
            myVector[sz - 1 - i] = myVector[i];
            myVector[i] = temp;
        }
        cout << "myVector contains:";

        for (int i : myVector) cout << " " << i;
        cout << endl;
        cout << "------------------------------------------" << endl;
    }

    void testAssign() {
        //vector::assign()函数
        //功能：对vector容器中的元素赋值
        //定义：template<class InputIterator>
        //void assign(InputIterator first ,InputIterator last);
        //void assign(size_type n,const T&u);
        //头文件<vector>
        //vector assign
        //vector::assign()功能：对vector中的元素赋值
        vector<int> first;
        vector<int> second;
        vector<int> third;
        first.assign(7, 100);//a repetition 7 times of value 100
        vector<int>::iterator it;
        it = first.begin() + 1;
        second.assign(it, first.end() - 1);//the 5 central values of first
        int myInts[] = {1949, 10, 1};
        third.assign(myInts, myInts + 3);//assigning from array
        cout << "Size of first:" << int(first.size()) << endl;
        cout << "Size of second:" << int(second.size()) << endl;
        cout << "Size of third:" << int(third.size()) << endl;
        cout << "------------------------------------------" << endl;
    }

    void testBeginEnd() {
        //vector::begin()函数 功能：返回第一个元素的迭代器
        //vector::end()函数 功能：返回最末元素的迭代器(注：实指向最末元素的下一个位置）
        vector<int> myVector;
        for (int i = 1; i <= 5; i++) {
            myVector.push_back(i);
        }
        vector<int>::iterator it;
        cout << "myVector contains:";
        for (it = myVector.begin(); it < myVector.end(); it++) {
            cout << " " << *it;
        }
        cout << endl;
        cout << "------------------------------------------" << endl;
    }

    void testRBeginREnd() {
        //vector::rbegin()函数 功能：返回vector尾部的逆迭代器
        //vector::rend()函数 功能：返回vector起始的逆迭代器
        vector<int> myVector;
        for (int i = 1; i < 9; i++) {
            myVector.push_back(i);
        }
        cout << "myVector contains:";
        vector<int>::reverse_iterator rit;
        for (rit = myVector.rbegin(); rit < myVector.rend(); rit++) {
            cout << " " << *rit;
        }
        cout << endl;

        cout << "myVector contains:";
        vector<int>::iterator it;
        for (it = myVector.begin(); it < myVector.end(); it++) {
            cout << " " << *it;
        }
        cout << endl;
        cout << "------------------------------------------" << endl;

    }

    void testBack() {
        //vector::back()函数 功能：返回最末一个元素
        vector<int> myVector;
        myVector.push_back(10);
        while (myVector.back() != 0) {
            myVector.push_back(myVector.back() - 1);
        }
        cout << "myVector contains:";
        for (int i : myVector)
            cout << " " << i;
        cout << endl;
        cout << "------------------------------------------" << endl;
    }

    void testFront() {
        //vector::front()函数 功能：返回第一个元素
        vector<int> myVector;
        myVector.push_back(11);
        myVector.push_back(3);
        //now front equals 11,and back 3
        myVector.front() -= myVector.back();
        cout << "myVector.front() is now:" << myVector.front() << endl;
        cout << "------------------------------------------" << endl;
    }

    void testPush_back() {
        //vector::push_back()函数 功能：在vector最后添加一个元素
        vector<int> myVector;

        srand(time(NULL));

        for (int i = 0; i < 10; i++) {
            int myInt = rand() % 10;
            myVector.push_back(myInt);

        }

        cout << "myVector contains:";

        for (int i : myVector) {
            cout << " " << i;
        }
        cout << endl;
        cout << "myVector stores " << (int) myVector.size() << " numbers\n";
        cout << "------------------------------------------" << endl;

    }

    void testPop_back() {
        //vector::pop_back()函数 功能：移除最后一个元素
        vector<int> myVector;
        int sum(0);
        myVector.push_back(1);
        myVector.push_back(2);
        myVector.push_back(3);
        while (!myVector.empty()) {
            sum += myVector.back();
            myVector.pop_back();
        }
        cout << "The elements of myVector summed: " << sum << endl;
        cout << "------------------------------------------" << endl;
    }

    void testInsert() {
        //vector:insert()函数 功能：插入元素到vector中
        vector<int> myVector(3, 11);
        vector<int>::iterator it;
        it = myVector.begin();
        it = myVector.insert(it, 1998);
        myVector.insert(it, 2, 16);
        //it no longer valid ,get a new one
        it = myVector.begin();
        vector<int> anotherVector(3, 15);
        myVector.insert(it + 2, anotherVector.begin(), anotherVector.end());
        int myArray[] = {1999, 2, 13};
        myVector.insert(myVector.begin(), myArray, myArray + 3);
        cout << "myVector contains:  ";
        for (it = myVector.begin(); it != myVector.end(); it++) {
            cout << " " << *it;
        }
        cout << endl;
        cout << "------------------------------------------" << endl;
    }

    void testErase() {
        //vector::erase()函数 功能：删除指定元素
        vector<int> myVector;
        //set some values(from1 to 10)
        myVector.reserve(10);
        for (int i = 0; i < 10; i++) myVector.push_back(i);

        //erase the 6th element
        myVector.erase(myVector.begin() + 5);
        cout << "myVector contains:";
        vector<int>::iterator it;

        for (it = myVector.begin(); it < myVector.end(); it++)
            cout << " " << *it;

        cout << endl;
        myVector.erase(myVector.begin(), myVector.begin() + 3);
        cout << "myVector contains:";
        for (int i : myVector)
            cout << " " << i;

        cout << endl;
        cout << "------------------------------------------" << endl;

    }

    void testClear() {
        //vector::clear()函数 功能：清空所有元素
        unsigned int i;
        vector<int> myVector;
        myVector.push_back(1);
        myVector.push_back(2);
        myVector.push_back(3);
        cout << "myVector contains:";
        for (i = 0; i < myVector.size(); i++)
            cout << " " << myVector[i];

        cout << endl;
        myVector.clear();
        myVector.push_back(2000);
        myVector.push_back(3000);
        vector<int>::iterator it;
        cout << "myVector contains:";
        for (it = myVector.begin(); it < myVector.end(); it++)
            cout << " " << *it;
        cout << "------------------------------------------" << endl;

    }

    void testEmpty() {
        //vector::empty()函数 功能判断vector是否为空,(返回true时为空）
        vector<int> myVector;
        int sum(0);
        for (int i = 1; i <= 10; i++)
            myVector.push_back(i);

        while (!myVector.empty()) {
            sum += myVector.back();
            myVector.pop_back();
        }
        cout << "total:" << sum << endl;
        cout << "------------------------------------------" << endl;
    }

    void testSize() {
        //vector::size()函数 功能：返回vector元素数量大小
        vector<int> myInts;
        cout << "0.size: " << int(myInts.size()) << endl;
        for (int i = 0; i < 11; i++)
            myInts.push_back(i);

        cout << "1.size: " << int(myInts.size()) << endl;

        myInts.insert(myInts.end(), 11, 3);
        cout << "2.size: " << int(myInts.size()) << endl;
        for (int myInt : myInts)
            cout << " " << myInt;

        cout << endl;
        myInts.pop_back();
        cout << "3.size: " << int(myInts.size()) << endl;
        cout << "------------------------------------------" << endl;
    }

    void testResize() {
        //vector::resize()函数 功能：改变vector元素数量的大小
        vector<int> myVector;
        myVector.reserve(10);
        for (int i = 0; i < 10; i++) myVector.push_back(i);

        cout << "myVector contains:";
        for (int i : myVector)
            cout << " " << i;
        cout << endl;
        myVector.resize(5);
        cout << "myVector contains:";
        for (int i : myVector)
            cout << " " << i;

        cout << endl;
        myVector.resize(11, 3);
        cout << "myVector contains:";
        for (int i : myVector)
            cout << " " << i;

        cout << endl;
        myVector.resize(16);
        cout << "myVector contains:";
        for (int i : myVector)
            cout << " " << i;

        cout << endl;
        cout << "------------------------------------------" << endl;
    }

    void testSwap() {
        //vector::swap()函数 功能：交换两个vector
        vector<int> first(3, 10);//three ints with a value of 10
        vector<int> second(5, 20);//five ints with a value of 20
        cout << "first contains:";
        for (int i : first)
            cout << " " << i;

        cout << endl;
        cout << "second contains:";
        for (int i : second)
            cout << " " << i;

        cout << endl;


        first.swap(second);
        cout << "first contains:";
        for (int i : first)
            cout << " " << i;

        cout << endl;
        cout << "second contains:";
        for (int i : second)
            cout << " " << i;

        cout << endl;
        cout << "------------------------------------------" << endl;
    }

    void testGetAllocator() {
        //vector::get_allocator()函数 功能：返回vector的内存分配器
        vector<int> myVector;
        int *p;
        //allocate an array of 10 elements using vector's allocator
        p = myVector.get_allocator().allocate(5);

        //assign some values to array
        for (int i = 0; i < 5; i++) {
            p[i] = i;
        }
        cout << "The allocated array contains:";
        for (int i = 0; i < 5; i++)
            cout << " " << p[i];

        cout << endl;
        vector<int> myVector1(3, 1);
        vector<int>::iterator it;

        it = myVector1.begin();
        it = myVector1.insert(it, 2);
        myVector1.insert(it, 3);
        //"it" no longer valid,get a new one;
        it = myVector1.begin();
        vector<int> antherVector(2, 4);

        myVector1.insert(it + 2, antherVector.begin(), antherVector.end());

        int myArray[] = {5, 2, 0};

        myVector1.insert(myVector1.begin(), myArray, myArray + 3);
        cout << "myVector contains:";
        for (it = myVector1.begin(); it < myVector1.end(); it++)
            cout << " " << *it;

        cout << "------------------------------------------" << endl;


    }

    void testAt() {
        //vector::at()函数 功能：返回指定位置的元素
        vector<int> myVector(10);//10 zero-initialized ints

        //assign some values;
        for (int i = 0; i < myVector.size(); i++) myVector.at(i) = i;

        cout << "myVector contains:";
        for (int i : myVector)
            cout << " " << i;

        cout << endl;
        cout << "------------------------------------------" << endl;

    }

    void testCapacity() {
        //vector::max_size()函数 功能：返回vector所能容纳元素的最大数量上限
        //vector::capacity()函数 功能：返回vector所能容纳的元素数量，在不重新分配内存的情况下
        vector<int> myVector;
        //set some content in the vector:
        for (int i = 1; i < 98; i++)
            myVector.push_back(i);

        cout << "size: " << (int) myVector.size() << endl;
        cout << "capacity: " << (int) myVector.capacity() << endl;
        cout << "max_size: " << (int) myVector.max_size() << endl;
        cout << "------------------------------------------" << endl;

    }
}


#endif //STLUSAGETEST_TESTVECTOR_H
