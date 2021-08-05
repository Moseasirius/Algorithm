//
// Created by mo on 2021/6/24.
//

#ifndef SORT_HEAPSORT_H
#define SORT_HEAPSORT_H

#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <cassert>

template<typename Item>

class MaxHeap {

private:
    Item *data;
    int count;
    int capacity;

    void shiftUp(int k) {
        while (k > 1 && data[k / 2] < data[k])//k>1防止越界父节点的元素值是否小于子节点
        {
            swap(data[k / 2], data[k]);
            k /= 2;//更新k

        }
    }

    void shiftDown(int k) {
        //判断k节点有孩子，这里判断左孩子，一棵完全二叉树中，可能只有左孩子而没有右孩子，不可能只有右孩子而没有左孩子
        while (2 * k <= count) {
            int j = 2 * k;//在此轮循环中，data[k]和data[j]交换位置
            if (j + 1 <= count && data[j + 1] > data[j])//说明有右孩子，而且右孩子的值比左孩子的值大
            {
                j = j + 1;
            }
            // data[j] 是 data[2*k]和data[2*k+1]中的最大值
            if (data[k] >= data[j])
                break;
            swap(data[k], data[j]);//可以优化，不用每一遍都swap，可以最后再交换(插入排序优化  思想）
            k = j;
        }
    }

public:
    //构造函数，构造一个空堆，可容纳capacity个元素
    MaxHeap(int capacity) {
        data = new Item[capacity + 1];//因为我们从数组下标索引1开始存数据
        count = 0;
        this->capacity = capacity;
    }

    //Heapify
    MaxHeap(Item array[], int n) {
        data = new Item[n + 1];
        capacity = n;
        for (int i = 0; i < n; i++) {
            data[i + 1] == array[i];

        }
        count = n;
        for (int i = count / 2; i >= 1; i--) {
            shiftDown(i);
        }
    }

    //析构函数
    ~MaxHeap() {
        delete[] data;

    }

    //返回堆中元素的个数
    int size() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }

    void insert(Item item) {
        assert(count + 1 <= capacity);
        data[count + 1] = item;//隐藏数组越界问题,可以先判断后开辟新的空间解决
        count++;
        shiftUp(count);
    }

    void print() {
        for (int i = 1; i <= size(); i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    Item extractMax() {
        assert(count > 0);
        Item ret = data[1];
        swap(data[1], data[count]);
        count--;
        shiftDown(1);
        return ret;

    }

public:
    // 以树状打印整个堆结构
    void testPrint() {

        // 我们的testPrint只能打印100个元素以内的堆的树状信息
        if (size() >= 100) {
            cout << "This print function can only work for less than 100 int";
            return;
        }

        // 我们的testPrint只能处理整数信息
        if (typeid(Item) != typeid(int)) {
            cout << "This print function can only work for int item";
            return;
        }

        cout << "The max heap size is: " << size() << endl;
        cout << "Data in the max heap: ";
        for (int i = 1; i <= size(); i++) {
            // 我们的testPrint要求堆中的所有整数在[0, 100)的范围内
            assert(data[i] >= 0 && data[i] < 100);
            cout << data[i] << " ";
        }
        cout << endl;
        cout << endl;

        int n = size();
        int max_level = 0;
        int number_per_level = 1;
        while (n > 0) {
            max_level += 1;
            n -= number_per_level;
            number_per_level *= 2;
        }

        int max_level_number = int(pow(2, max_level - 1));
        int cur_tree_max_level_number = max_level_number;
        int index = 1;
        for (int level = 0; level < max_level; level++) {
            string line1 = string(max_level_number * 3 - 1, ' ');

            int cur_level_number = min(count - int(pow(2, level)) + 1, int(pow(2, level)));
            bool isLeft = true;
            for (int index_cur_level = 0; index_cur_level < cur_level_number; index++, index_cur_level++) {
                putNumberInLine(data[index], line1, index_cur_level, cur_tree_max_level_number * 3 - 1, isLeft);
                isLeft = !isLeft;
            }
            cout << line1 << endl;

            if (level == max_level - 1)
                break;

            string line2 = string(max_level_number * 3 - 1, ' ');
            for (int index_cur_level = 0; index_cur_level < cur_level_number; index_cur_level++)
                putBranchInLine(line2, index_cur_level, cur_tree_max_level_number * 3 - 1);
            cout << line2 << endl;

            cur_tree_max_level_number /= 2;
        }
    }

private:
    void putNumberInLine(int num, string &line, int index_cur_level, int cur_tree_width, bool isLeft) {

        int sub_tree_width = (cur_tree_width - 1) / 2;
        int offset = index_cur_level * (cur_tree_width + 1) + sub_tree_width;
        assert(offset + 1 < line.size());
        if (num >= 10) {
            line[offset + 0] = '0' + num / 10;
            line[offset + 1] = '0' + num % 10;
        } else {
            if (isLeft)
                line[offset + 0] = '0' + num;
            else
                line[offset + 1] = '0' + num;
        }
    }

    void putBranchInLine(string &line, int index_cur_level, int cur_tree_width) {

        int sub_tree_width = (cur_tree_width - 1) / 2;
        int sub_sub_tree_width = (sub_tree_width - 1) / 2;
        int offset_left = index_cur_level * (cur_tree_width + 1) + sub_sub_tree_width;
        assert(offset_left + 1 < line.size());
        int offset_right = index_cur_level * (cur_tree_width + 1) + sub_tree_width + 1 + sub_sub_tree_width;
        assert(offset_right < line.size());

        line[offset_left + 1] = '/';
        line[offset_right + 0] = '\\';
    }

};

template<typename T>
void HeapSort1(T array[], int n) {
    MaxHeap<T> maxHeap = MaxHeap<T>(n);
    for (int i = 0; i < n; i++) {
        maxHeap.insert(array[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
        array[i] = maxHeap.extractMax();
    }
}

template<typename T>
void HeapSort2(T array[], int n) {
    MaxHeap<T> maxHeap = MaxHeap<T>(array, n);
    for (int i = n - 1; i >= 0; i--) {
        array[i] = maxHeap.extractMax();
    }
}

//原地堆排序，不开辟新空间
template<typename T>
void __shiftDown(T array[], int n, int k) {
    while (2 * k + 1 < n)//有左孩子，因为数组下标从零开始，所以不等等于。
    {
        int j = 2 * k + 1;//左孩子
        if (j + 1 < n && array[j] < array[j + 1]) {
            j++;
        }
        if (array[k] >= array[j]) break;//父节点大于孩子节点
        swap(array[k], array[j]);
        k = j;
    }
}

// 优化的shiftDown过程, 使用赋值的方式取代不断的swap,
// 该优化思想和我们之前对插入排序进行优化的思路是一致的
template<typename T>
void __shiftDown2(T array[], int n, int k) {
    T e = array[k];

    while (2 * k + 1 < n)//有左孩子，因为数组下标从零开始，所以不等等于。
    {
        int j = 2 * k + 1;//左孩子
        if (j + 1 < n && array[j] < array[j + 1]) {
            j++;
        }
        if (e >= array[j]) break;//父节点大于孩子节点

        array[k] = array[j];
        k = j;
    }
    array[k] = e;

}

template<typename T>
void HeapSort3(T array[], int n) {
    //数组下标从0开始，相应的二叉树父子节点就要变化
    // 从（最后一个元素的索引-1）/2开始
    //最后一个元素的索引=n-1
    //heapify过程
    for (int i = (n - 1 - 1) / 2; i >= 0; i--) {
        __shiftDown2(array, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(array[0], array[i]);
        __shiftDown2(array, i, 0);//i表示当前循环要排序的个数
    }

}

#endif //SORT_HEAPSORT_H
