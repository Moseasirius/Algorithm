//
// Created by mozhenhai on 2021/8/6.
//

#ifndef STLUSAGETEST_TESTSTACK_H
#define STLUSAGETEST_TESTSTACK_H

#include <stack>

namespace TestStack {
    void testStack() {
        //stack::empty()函数 功能：栈为空则返回真
        //stack::pop()函数 功能：移除栈顶元素
        //stack::push()函数 功能：在栈顶添加元素
        //stack::size()函数 功能：返回栈中元素数目
        //stack::top()函数 功能：返回栈顶元素
        stack<int> myStack;
        int sum(0);
        for (int i = 0; i < 11; i++) {
            myStack.push(i);
        }
        cout << "myStack size:" << myStack.size() << endl;
        cout << "myStack.top() is now :" << myStack.top() << endl;
        while (!myStack.empty()) {
            sum += myStack.top();
            myStack.pop();
        }
        cout << "total:" << sum << endl;
        // stack::stack()函数 功能: 构造stack
    }
}
#endif //STLUSAGETEST_TESTSTACK_H
