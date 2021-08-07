//
// Created by mozhenhai on 2021/8/6.
//

#ifndef STLUSAGETEST_TESTDEQUE_H
#define STLUSAGETEST_TESTDEQUE_H

#include <deque>
#include <iostream>

using namespace std;

namespace TestDeque {
    void testDeque() {
        //deque::deque()函数 功能：创建一个新双向队列
        deque<int> first;//empty deque if ints
        deque<int> second(5, 20);//five ints with values 20
        deque<int> third(second.begin(), second.end());//iterating through second
        deque<int> fourth(third);//a copy of third
        //the iterator constructor can also be used to construct from arrays
        int myInts[] = {1998, 11, 3, 520, 13, 14};

        deque<int> fifth(myInts, myInts + sizeof(myInts) / sizeof(int));
        cout << "the contents of first are:";
        for (int i : first) {
            cout << " " << i;
        }
        cout << endl;
        cout << "the contents of second are:";
        for (int i : second) {
            cout << " " << i;
        }
        cout << endl;
        cout << "the contents of third are:";
        for (int i : third) {
            cout << " " << i;
        }
        cout << endl;
        cout << "the contents of fourth are:";
        for (int i : fourth) {
            cout << " " << i;
        }

        cout << endl;
        cout << "the contents of fifth are:";
        for (int i : fifth) {
            cout << " " << i;
        }
        cout << endl;
        cout << "------------------------------------------" << endl;
    }

    void testOperator() {
        ///deque::operator=()函数 功能赋值双向队列
        deque<int> first(3);//deque with 3 zero-initialized ints
        deque<int> second(5);//deque with 5 zero-initialized ints
        second = first;
        first = deque<int>(6);
        cout << "size of fist " << int(first.size()) << endl;
        cout << "size of second " << int(second.size()) << endl;
        // deque::operator[]()函数 功能：Access element
        deque<int> myDeque(10);//10 zero-initialized elements
        deque<int>::size_type sz = myDeque.size();
        for (int i = 0; i < sz; i++)myDeque[i] = 2 * i;
        //reverse order of elements using operator[]:
        for (int i = 0; i < sz / 2; i++) {
            int temp;
            temp = myDeque[sz - 1 - i];
            myDeque[sz - 1 - i] = myDeque[i];
            myDeque[i] = temp;
        }
        cout << "myDeque contains:" << endl;
        for (int i = 0; i < sz; i++) {
            cout << " " << myDeque[i];
        }
        cout << endl;
        cout << "------------------------------------------" << endl;

    }

    void testAssign() {
        //deque::assign函数 功能：设置双向队列的值
        deque<int> first;
        deque<int> second;
        deque<int> third;
        first.assign(6, 11);//a repetition 6 times of value 11
        deque<int>::iterator it;
        it = first.begin() + 1;
        second.assign(it, first.end());//the 5 values of first
        int myInts[] = {1998, 11, 3};
        third.assign(myInts, myInts + 3);//assigning from array
        cout << "size of first: " << int(first.size()) << endl;
        cout << "size of second: " << int(second.size()) << endl;
        cout << "size of third: " << int(third.size()) << endl;
        cout << "------------------------------------------" << endl;

    }

    void testBeginEnd() {
        //deque::begin()函数 功能：返回指向第一个元素的迭代器
        //deque::end()函数 功能：返回指向尾部的迭代器
        //deque::rbegin()函数 功能：返回指向尾部的逆向迭代器
        //deque::rend()函数 功能：返回指向头部的逆向迭代器

        deque<int> myDeque;
        deque<int>::iterator it;
        deque<int>::reverse_iterator rit;
        for (int i = 0; i < 9; i++) {
            myDeque.push_back(i);
        }
        cout << "myDeque contains:";

        for (it = myDeque.begin(); it != myDeque.end(); it++) {
            cout << " " << *it;
        }
        cout << endl;
        it = myDeque.begin();
        cout << "begin to end";
        while (it != myDeque.end()) {
            cout << " " << *it++;
        }

        rit = myDeque.rbegin();
        cout << endl;
        cout << "myDeque contains:";
        cout << "rbegin to rend";
        while (rit != myDeque.rend()) {
            cout << " " << *rit++;
        }
        cout << "------------------------------------------" << endl;
    }

    void testBack() {
        //deque::back()函数 功能：返回最后一个元素
        deque<int> myDeque;
        myDeque.push_back(10);
        while (myDeque.back() != 0) {
            myDeque.push_back(myDeque.back() - 1);
        }
        cout << "myDeque contains: ";
        for (int i : myDeque) {
            cout << " " << i;
        }
        cout << endl;
        cout << "------------------------------------------" << endl;
    }

    void testFront() {
        //deque::front()函数 功能：返回第一个元素 
        deque<int> myDeque;
        myDeque.push_back(11);
        myDeque.push_back(3);
        myDeque.push_front(1998);
        myDeque.front() += myDeque.back();
        cout << "myDeque contains:";
        for (int i : myDeque) {
            cout << " " << i;
        }
        cout << "------------------------------------------" << endl;
    }

    void testPopPush() {
        //deque::pop_back()函数 功能: 删除尾部的元素
        //deque::push_back()函数 功能：在尾部加入一个元素

        //deque::pop_front()函数 功能：删除头部的元素 
        //deque::push_front()函数 功能：在头部加入一个元素

        //deque::back()函数 功能：返回最后一个元素
        //deque::front()函数 功能：返回第一个元素
        deque<int> myDeque;
        int sumBack(0);
        int sumFront(0);
        myDeque.push_back(1998);
        myDeque.push_back(11);
        myDeque.push_back(3);
        while (!myDeque.empty()) {
            sumBack += myDeque.back();
            myDeque.pop_back();
        }
        myDeque.push_front(1998);
        myDeque.push_front(11);
        myDeque.push_front(3);
        while (!myDeque.empty()) {
            sumFront += myDeque.front();
            myDeque.pop_front();
        }
        cout << "the elements of myDeque summed" << sumBack << "or" << sumFront << endl;
        cout << "------------------------------------------" << endl;
    }

    void testInset() {
        //deque::insert()函数 功能：插入 一个元素到双向队列中
        deque<int> myDeque;
        deque<int>::iterator it;
        //set some initial values
        for (int i = 1; i < 6; i++) {
            myDeque.push_back(i);//1 2 3 4 5
        }
        it = myDeque.begin();
        it = myDeque.insert(it, 1998);
        //it now points to the newly inserted 10
        myDeque.insert(it, 3, 11);
        //it no longer valid!!!!
        it = myDeque.end() - 3;
        vector<int> myVector(2, 23);
        myDeque.insert(it, myVector.begin(), myVector.end());
        cout << "myDeque contains: ";
        for (it = myDeque.begin(); it != myDeque.end(); it++) {
            cout << " " << *it;
        }
        cout << "------------------------------------------" << endl;
    }

    void testErase() {
        //deque::erase()函数 功能：删除一个元素
        deque<int> myDeque;
        //set some values (from 1 to 10)
        for (int i = 1; i < 11; i++) {
            myDeque.push_back(i);
        }
        //erase the 6th element
        myDeque.erase(myDeque.begin() + 5);
        cout << "myDeque contains: ";
        for (int i : myDeque) {
            cout << " " << i;
        }
        cout << endl;
        //erase the first 3 elements
        myDeque.erase(myDeque.begin(), myDeque.begin() + 3);
        cout << "myDeque contains: ";
        for (int i : myDeque) {
            cout << " " << i;
        }
        cout << endl;
        cout << "------------------------------------------" << endl;
    }

    void testClear() {
        //deque::clear()函数 功能：删除所有元素 
        deque<int> myDeque;
        myDeque.push_back(1998);
        myDeque.push_back(11);
        myDeque.push_back(3);
        cout << "myDeque contains: ";
        for (int i : myDeque) {
            cout << " " << i;
        }
        cout << endl;
        myDeque.clear();

        cout << "size of myDeque: " << myDeque.size() << endl;

        myDeque.push_back(2000);
        myDeque.push_back(2);
        cout << "myDeque contains: ";
        for (int i : myDeque) {
            cout << " " << i;
        }
        cout << endl;
        cout << "------------------------------------------" << endl;
    }

    void testEmpty() {
        //deque::empty()函数 功能：返回真如果双向队列为空
        deque<int> myDeque;
        int sum(0);
        for (int i = 0; i <= 10; i++) {
            myDeque.push_back(i);
        }
        while (!myDeque.empty()) {

            sum += myDeque.back();
            myDeque.pop_back();

        }

        cout << "total:--------------------------------" << sum << endl;
        cout << "------------------------------------------" << endl;
    }

    void testSize() {
        //deque::resize()函数 功能：改变双向队列的大小
        //deque::size()函数 功能：返回双向队列中元素的个数 
        deque<int> myDeque;
        deque<int>::iterator it;
        //set some initial content
        for (int i = 1; i < 11; i++) {

            myDeque.push_back(i);
        }

        myDeque.resize(5);
        deque<int>::iterator it1;

        cout << "myDeque contains:";

        for (it1 = myDeque.begin(); it1 != myDeque.end(); it1++)
            cout << " " << *it1;

        cout << endl;
        cout << "----------------------" << endl;

        cout << "size of myDeque:--------- " << myDeque.size() << endl;
        //记录一个debug ":"  写成 "：" 编译器输出乱码，所以一定要用英文标点

        myDeque.resize(8, 23);

        deque<int>::iterator it2;
        cout << "myDeque contains:";

        for (it2 = myDeque.begin(); it2 != myDeque.end(); it2++)
            cout << " " << *it2;

        cout << endl;

        cout << "size of myDeque: " << myDeque.size() << endl;

        cout << endl;

        myDeque.resize(11);

        deque<int>::iterator it3;

        cout << "myDeque contains:";
        for (it3 = myDeque.begin(); it3 != myDeque.end(); it3++)
            cout << " " << *it3;

        cout << " size of myDeque:" << myDeque.size();

        cout << endl;
        cout << "------------------------------------------" << endl;

    }

    void testSwap() {
        //deque::swap()函数 功能：和另一个双向队列交换元素
        deque<int> first(3, 1998);//three ints with a value of 1998
        deque<int> second(5, 20);//five ints with value of 20
        cout << "before first contains: ";
        for (int i : first) {
            cout << " " << i;
        }
        cout << endl;
        cout << "before second contains: ";
        for (int i : second) {
            cout << " " << i;
        }
        cout << endl;
        first.swap(second);
        cout << "after first contains: ";
        for (int i : first) {
            cout << " " << i;
        }
        cout << endl;
        cout << "after second contains: ";
        for (int i : second) {
            cout << " " << i;
        }
        cout << endl;
        cout << "------------------------------------------" << endl;
    }

    void testGetAllocator() {
        //deque::get_allocator()函数 功能：返回双向队列的配置器
        deque<int> myDeque;
        int *p;

        //allocate an array of 5 elements using deque's allocator
        p = myDeque.get_allocator().allocate(5);
        //assign some values to array
        for (int i = 0; i < 5; i++) {
            p[i] = i;
        }
        cout << "the allocated array contains:";
        for (int i = 0; i < 5; i++) {
            cout << " " << p[i];
        }
        cout << endl;
        myDeque.get_allocator().deallocate(p, 5);
        cout << "------------------------------------------" << endl;
    }

    void testAt() {
        //deque()::at()函数 功能：返回指定元素
        deque<int> myDeque(10);
        //10 zero-initialized ints
        //assign some values
        for (int i = 0; i < myDeque.size(); i++) {
            myDeque.at(i) = i;
        }

        cout << "myDeque contains: ";
        for (int i : myDeque) {
            cout << " " << i;
        }
        cout << endl;
        cout << "------------------------------------------" << endl;
    }

    void testMaxSize() {
        //deque::max_size()函数 功能：返回双向队列能容纳的最大元素个数
        deque<int> myDeque;
        int i = 10;
        cout << "enter number of elements:";

        if (i < myDeque.max_size()) {
            myDeque.resize(i);
            cout << myDeque.size() << endl;
        } else {
            cout << "that size exceeds the limit \n";
        }
        cout << "------------------------------------------" << endl;


    }
}
#endif //STLUSAGETEST_TESTDEQUE_H
