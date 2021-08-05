//
// Created by mo on 2021/7/26.
//

#ifndef BINARYSEARCHTREE_TEST_H
#define BINARYSEARCHTREE_TEST_H

#include <iostream>
#include <cassert>
#include <ctime>
#include <vector>
#include <fstream>
#include <algorithm>

#include "BinarySearch.h"
#include "SequenceST.h"
#include "FileOps.h"
#include "BST.h"

using namespace std;

void testBinarySearch() {
    int n = 1000000;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        a[i] = i;

    // 测试非递归二分查找法
    clock_t startTime = clock();

    // 对于我们的待查找数组[0...N)
    // 对[0...N)区间的数值使用二分查找，最终结果应该就是数字本身
    // 对[N...2*N)区间的数值使用二分查找，因为这些数字不在arr中，结果为-1
    for (int i = 0; i < 2 * n; i++) {
        int v = binarySearch2(a, n, i);
        if (i < n)
            assert(v == i);
        else
            assert(v == -1);
    }
    clock_t endTime = clock();
    cout << "Binary Search (Without Recursion): " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;


    // 测试递归的二分查找法
    startTime = clock();

    // 对于我们的待查找数组[0...N)
    // 对[0...N)区间的数值使用二分查找，最终结果应该就是数字本身
    // 对[N...2*N)区间的数值使用二分查找，因为这些数字不在arr中，结果为-1
    for (int i = 0; i < 2 * n; i++) {
        int v = binarySearch2(a, n, i);
        if (i < n)
            assert(v == i);
        else
            assert(v == -1);
    }
    endTime = clock();
    cout << "Binary Search (Recursion): " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;

    delete[] a;
}

// 测试我们用二分查找法实现的floor和ceil两个函数
// 请仔细观察在我们的测试用例中，有若干的重复元素，对于这些重复元素，floor和ceil计算结果的区别：）
void testFloorAndCeil() {
    int a[] = {1, 1, 1, 2, 2, 2, 2, 2, 4, 4, 5, 5, 5, 6, 6, 6};
    int n = sizeof(a) / sizeof(int);
    for (int i = 0; i <= 8; i++) {

        int floorIndex = floor(a, n, i);
        cout << "the floor index of " << i << " is " << floorIndex << ".";
        if (floorIndex >= 0 && floorIndex < n)
            cout << "The value is " << a[floorIndex] << ".";
        cout << endl;

        int ceilIndex = ceil(a, sizeof(a) / sizeof(int), i);
        cout << "the ceil index of " << i << " is " << ceilIndex << ".";
        if (ceilIndex >= 0 && ceilIndex < n)
            cout << "The value is " << a[ceilIndex] << ".";
        cout << endl;

        cout << endl;
    }


}

// 测试二分搜索树和顺序查找表之间的性能差距
// 二分搜索树的性能远远优于顺序查找表
void testBSTvsSequenceST() {

    // 使用圣经作为我们的测试用例
    string filename = "../bible.txt";

    vector<string> words;
    if (FileOps::readFile(filename, words)) {

        cout << "There are totally " << words.size() << " words in " << filename << endl;
        cout << endl;


        // 测试 BST
        time_t startTime = clock();

        // 统计圣经中所有词的词频
        // 注: 这个词频统计法相对简陋, 没有考虑很多文本处理中的特殊问题
        // 在这里只做性能测试用
        BST<string, int> bst = BST<string, int>();
        for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
            int *res = bst.search(*iter);
            if (res == NULL)
                bst.insert(*iter, 1);
            else
                (*res)++;
        }

        // 输出圣经中god一词出现的频率
        if (bst.contain("god"))
            cout << "'god' : " << *bst.search("god") << endl;
        else
            cout << "No word 'god' in " << filename << endl;

        time_t endTime = clock();

        cout << "BST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
        cout << endl;


        // 测试顺序查找表 SST
        startTime = clock();

        // 统计圣经中所有词的词频
        // 注: 这个词频统计法相对简陋, 没有考虑很多文本处理中的特殊问题
        // 在这里只做性能测试用
        SequenceST<string, int> sst = SequenceST<string, int>();
        for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
            int *res = sst.search(*iter);
            if (res == NULL)
                sst.insert(*iter, 1);
            else
                (*res)++;
        }

        // 输出圣经中god一词出现的频率
        if (sst.contain("god"))
            cout << "'god' : " << *sst.search("god") << endl;
        else
            cout << "No word 'god' in " << filename << endl;

        endTime = clock();

        cout << "SST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
    }
    return;
}
// 测试二分搜索树的前中后序遍历

void testOrder() {
    srand(time(NULL));
    BST<int, int> bst = BST<int, int>();

    // 取n个取值范围在[0...m)的随机整数放进二分搜索树中
    int N = 10;
    int M = 100;
    for (int i = 0; i < N; i++) {
        int key = rand() % M;
        // 为了后续测试方便,这里value值取和key值一样
        int value = key;
        cout << key << " ";
        bst.insert(key, value);
    }
    cout << endl;

    // 测试二分搜索树的size()
    cout << "size: " << bst.size() << endl << endl;

    // 测试二分搜索树的前序遍历 preOrder
    cout << "preOrder: " << endl;
    bst.preOrder();
    cout << endl;

    // 测试二分搜索树的中序遍历 inOrder
    cout << "inOrder: " << endl;
    bst.inOrder();
    cout << endl;

    // 测试二分搜索树的后序遍历 postOrder
    cout << "postOrder: " << endl;
    bst.postOrder();
    cout << endl;


}

// 测试二分搜索树的前中后序遍历以及层序遍历
void testOrderAndLevel() {
    srand(time(NULL));
    BST<int, int> bst = BST<int, int>();
    // 取n个取值范围在[0...m)的随机整数放进二分搜索树中
    int N = 10;
    int M = 100;
    for (int i = 0; i < N; i++) {
        int key = rand() % M;
        int value = key;
        cout << key << " ";
        bst.insert(key, value);
    }
    cout << endl;
    //测试二分搜索树的size()
    cout << "size: " << bst.size() << endl << endl;

    //测试二分搜索树的前序遍历
    cout << "preOrder" << endl;
    bst.preOrder();
    cout << endl;

    //测试二分搜索树的中序遍历
    cout << "inOrder" << endl;
    bst.inOrder();
    cout << endl;

    //测试二分搜索树的后序遍历
    cout << "postOrder" << endl;
    bst.postOrder();
    cout << endl;

    //测试二分搜索树的层序遍历
    cout << "levelOrder" << endl;
    bst.levelOrder();
    cout << endl;


}

// 测试二分搜索树中的removeMin和removeMax
void testRemoveMinMax() {
    srand(time(NULL));
    BST<int, int> bst = BST<int, int>();

    // 取n个取值范围在[0...m)的随机整数放进二分搜索树中
    int n = 100;
    int m = 100;
    for (int i = 0; i < n; i++) {
        int key = rand() % m;
        // 为了后续测试方便,这里value值取和key值一样
        int value = key;
        cout << key << " ";
        bst.insert(key, value);
    }
    // 注意, 由于随机生成的数据有重复, 所以bst中的数据数量大概率是小于n的

    // 测试 removeMin
    // 输出的元素应该是从小到大排列的
    cout << endl;
    cout << "Test removeMin: " << endl;
    while (!bst.isEmpty()) {
        cout << "min: " << bst.minimum() << " , ";
        bst.removeMin();
        cout << "After removeMin, size = " << bst.size() << endl;
    }
    cout << endl;


    for (int i = 0; i < n; i++) {
        int key = rand() % n;
        // 为了后续测试方便,这里value值取和key值一样
        int value = key;
        cout << key << " ";
        bst.insert(key, value);
    }
    // 注意, 由于随机生成的数据有重复, 所以bst中的数据数量大概率是小于n的

    // 测试 removeMax
    // 输出的元素应该是从大到小排列的
    cout << endl;
    cout << "Test removeMax: " << endl;
    while (!bst.isEmpty()) {
        cout << "max: " << bst.maximum() << " , ";
        bst.removeMax();
        cout << "After removeMax, size = " << bst.size() << endl;
    }
}

// 实验二分搜索树的局限性
void testLimitationsBST() {
    // 我们使用文本量更小的共产主义宣言进行试验:)
    string filename = "../communist.txt";
    vector<string> words;

    if (FileOps::readFile(filename, words)) {

        cout << "There are totally " << words.size() << " words in " << filename << endl;
        cout << endl;


        // 测试1, 我们按照文本原有顺序插入进二分搜索树
        time_t startTime = clock();
        BST<string, int> *bst = new BST<string, int>();
        for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
            int *res = (*bst).search(*iter);
            if (res == NULL)
                (*bst).insert(*iter, 1);
            else
                (*res)++;
        }

        // 我们查看unite一词的词频
        if (bst->contain("unite"))
            cout << "'unite' : " << *(*bst).search("unite") << endl;
        else
            cout << "No word 'unite' in " + filename << endl;
        time_t endTime = clock();

        cout << "BST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
        cout << endl;

        delete bst;


        // 测试2, 我们按照文本原有顺序插入顺序查找表
        startTime = clock();
        SequenceST<string, int> *sst = new SequenceST<string, int>();
        for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
            int *res = (*sst).search(*iter);
            if (res == NULL)
                (*sst).insert(*iter, 1);
            else
                (*res)++;
        }

        // 我们查看unite一词的词频
        if (sst->contain("unite"))
            cout << "'unite' : " << *(*sst).search("unite") << endl;
        else
            cout << "No word 'unite' in " + filename << endl;
        endTime = clock();

        cout << "SST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
        cout << endl;

        delete sst;

        // 测试3, 我们将原文本排序后插入二分搜索树, 查看其效率
        BST<string, int> *bst2 = new BST<string, int>();

        time_t startTime1 = clock();

        sort(words.begin(), words.end());

        time_t endTime1 = clock();

        cout << "BST2 , Sort_time: " << endTime1 - startTime1 << " ms." << endl;

        startTime = clock();
        for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
            int *res = (*bst2).search(*iter);
            if (res == NULL)
                (*bst2).insert(*iter, 1);
            else
                (*res)++;
        }

        // 我们查看unite一词的词频
        cout << "'unite' : " << *(*bst2).search("unite") << endl;
        endTime = clock();

        cout << "BST2 , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
        cout << endl;

        delete bst2;
    }
}

// 测试二分搜索树中的predecessor和successor两个函数
void testPredecessorSuccessor() {

    // 生成 0 到 N-1 一共 N 个数字的数组
    int N = 1000;
    int *nums = new int[N];
    for (int i = 0; i < N; i++)
        nums[i] = i;

    // 将数组中的数组乱序
    shuffle(nums, N);

    // 将这个N个数插入到二叉树中
    BST<int, int> bst;
    for (int i = 0; i < N; i++)
        bst.insert(i, i);

    // 测试前驱算法, 除了数字0没有前驱, 每个数字x的前驱应该为x-1
    for (int i = 0; i < N; i++) {
        if (i == 0) {
            assert(bst.predecessor(i) == NULL);
            cout << "The Precursor of 0 is NULL" << endl;
        } else {
            assert(*bst.predecessor(i) == i - 1);
            cout << "The Precursor of " << i << " is " << i - 1 << endl;
        }
    }

    cout << endl;

    // 测试后继算法, 除了数字没有N-1后继, 每个数字x的后继应该为x+1
    for (int i = 0; i < N; i++) {
        if (i == N - 1) {
            assert(bst.successor(i) == NULL);
            cout << "The successor of " << i << " is NULL" << endl;
        } else {
            assert(*bst.successor(i) == i + 1);
            cout << "The successor of " << i << " is " << i + 1 << endl;
        }
    }
}

#endif //BINARYSEARCHTREE_TEST_H
