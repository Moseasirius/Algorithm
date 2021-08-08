//
// Created by mozhenhai on 2021/8/6.
//

#ifndef STLUSAGETEST_TESTQUEUE_H
#define STLUSAGETEST_TESTQUEUE_H

#include <deque>
#include<iostream>

using namespace std;

namespace TestQueue {
    void testQueue() {
        //queue::queue()函数 创建queue
        deque<int> myDeque(3, 1999);//deque with 3 elements
        list<int> myList(2, 1998);//list with 2 elements
        queue<int> first;//empty queue
        queue<int> second(myDeque);//queue initialized to copy of deque
        queue<int, list<int>> third;
        //empty queue with list as underlying container

        queue<int, list<int>> fourth(myList);

        cout << "size of first:" << (int) first.size() << endl;
        cout << "size of second:" << (int) second.size() << endl;
        cout << "size of third:" << (int) third.size() << endl;
        cout << "size of fourth:" << (int) fourth.size() << endl;
        //queue::size()函数 功能：返回队列中元素的个数
        //queue::push()函数 功能：在队列末尾加入一个元素
        //queue::pop()函数 功能：删除队列第一个元素
        //queue::front()函数 功能:返回第一个元素
        //queue::back()函数 功能：返回最后一个元素
        //queue::empty()函数 功能：如果队列为空则返回真

        queue<int> myInts;
        cout << "0.size:" << (int) myInts.size() << endl;
        for (int i = 0; i < 10; i++) {
            myInts.push(i);
        }
        cout << "1.size:" << (int) myInts.size() << endl;
        cout << myInts.front() << endl;
        myInts.pop();

        cout << myInts.front() << endl;
        cout << myInts.back() << endl;
        int sum(0);
        while (!myInts.empty()) {
            sum += myInts.front();
            myInts.pop();
        }
        cout << sum << endl;
        cout << "------------------------------------------" << endl;

    }

}
#endif //STLUSAGETEST_TESTQUEUE_H
