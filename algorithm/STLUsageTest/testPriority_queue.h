//
// Created by mozhenhai on 2021/8/6.
//

#ifndef STLUSAGETEST_TESTPRIORITY_QUEUE_H
#define STLUSAGETEST_TESTPRIORITY_QUEUE_H

#include <iostream>
#include <queue>

namespace TestPriorityQueque {

    void testPriorityQueque() {
        //priority_queue::empty()函数 功能：如果优先队列为空，则返回真
        //priority_queue::pop()函数 功能：删除第一个元素
        //priority_queue::push()函数 功能：加入一个元素
        //priority_queue::size()函数 功能：返回优先队列中拥有的元素的个数
        //priority_queue::top()函数 功能：返回优先队列中有最高优先级的元素

        priority_queue<int> pq;
        int sum(0);
        for (int i = 0; i <= 11; i++) {
            pq.push(i);
        }
        cout << pq.top() << endl;
        while (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
        cout << "total:" << sum << endl;

        priority_queue<int> pq1;

        pq1.push(1999);
        pq1.push(2000);
        pq1.push(1998);
        pq1.push(2020);
        cout << "size of pq1 :" << pq1.size() << endl;
        cout << "popping out elements:";
        while (!pq1.empty()) {
            cout << " " << pq1.top();
            pq1.pop();
        }
        cout << endl;
        cout << "size of pq1 :" << pq1.size() << endl;
    }

}
#endif //STLUSAGETEST_TESTPRIORITY_QUEUE_H
