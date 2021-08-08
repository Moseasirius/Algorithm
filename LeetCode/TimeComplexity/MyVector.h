//
// Created by mozhenhai on 2021/8/8.
//

#ifndef TIMECOMPLEXITY_MYVECTOR_H
#define TIMECOMPLEXITY_MYVECTOR_H
#include <cassert>
template <typename T>
class MyVector{

private:
    T* data;
    int size;       // 存储数组中的元素个数
    int capacity;   // 存储数组中可以容纳的最大的元素个数

    // 复杂度为 O(n)
    void resize(int newCapacity){

        assert(newCapacity >= size);
        T *newData = new T[newCapacity];
        for(int i = 0 ; i < size ; i ++)
            newData[i] = data[i];
        delete[] data;

        data = newData;
        capacity = newCapacity;
    }

public:
    MyVector(){

        data = new T[100];
        size = 0;
        capacity = 100;
    }

    ~MyVector(){

        delete[] data;
    }

    // 平均复杂度为 O(1)
    void push_back(T e){

        if( size == capacity )
            resize( 2* capacity );

        data[size++] = e;
    }

    // 平均复杂度为 O(1)
    T pop_back(){

        assert(size > 0);
        T ret = data[size-1];
        size --;

        // 在size达到静态数组最大容量的1/4时才进行resize
        // resize的容量是当前最大容量的1/2
        // 防止复杂度的震荡
        if(size == capacity / 4)
            resize(capacity / 2);

        return ret;
    }

};

__attribute__((unused)) void amortizedTime();

__attribute__((unused)) void amortizedTime1();
#endif //TIMECOMPLEXITY_MYVECTOR_H
