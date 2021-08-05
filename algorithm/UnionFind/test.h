//
// Created by mozhenhai on 2021/7/30.
//

#ifndef UNIONFIND_TEST_H
#define UNIONFIND_TEST_H

#include <iostream>
#include <cassert>
#include "UnionFindTestHelper.h"


// 使用相同的测试数据测试UF的执行效率
template<typename UF>

void testUF(const string &ufName, UF &uf, const vector<pair<int, int>> &unionTest,
            const vector<pair<int, int>> &connectTest) {

    time_t startTime = clock();
    for (int i = 0; i < unionTest.size(); i++) {
        int a = unionTest[i].first;
        int b = unionTest[i].second;
        uf.unionSet(a, b);
    }
    for (int i = 0; i < connectTest.size(); i++) {
        int a = connectTest[i].first;
        int b = connectTest[i].second;
        uf.isConnected(a, b);
    }
    time_t endTime = clock();

    cout << ufName << " with " << unionTest.size() << " unionElements ops, ";
    cout << connectTest.size() << " isConnected ops, ";
    cout << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
}

void testUF123456() {
    // 对比UF1, UF2, UF3, UF4, UF5和UF6的时间性能
    // 在这里, 我们对于不同的UnionFind的实现, 使用相同的测试用例, 让测试结果更加准确

    // 使用5,000,000的数据规模
    int n = 5000000;

    srand(time(NULL));

    // 生成unionElements的测试用例
    vector<pair<int, int>> unionTest;
    for (int i = 0; i < n; i++) {
        int a = rand() % n;
        int b = rand() % n;
        unionTest.push_back(make_pair(a, b));
    }

    // 生成isConnected的测试用例
    vector<pair<int, int>> connectTest;
    for (int i = 0; i < n; i++) {
        int a = rand() % n;
        int b = rand() % n;
        connectTest.push_back(make_pair(a, b));
    }
    // 测试我们的UF1 ~ UF6

    // 100万数据对于UF1和UF2来说太慢了, 不再测试
//    UF1::UnionFind uf1 = UF1::UnionFind(n);
//    UnionFindTestHelper::testUF("UF1", uf1, unionTest, connectTest);
//
//    UF2::UnionFind uf2 = UF2::UnionFind(n);
//    UnionFindTestHelper::testUF("UF2", uf2, unionTest, connectTest);

    UF3::UnionFind uf3 = UF3::UnionFind(n);
    testUF("UF3", uf3, unionTest, connectTest);

    UF4::UnionFind uf4 = UF4::UnionFind(n);
    testUF("UF4", uf4, unionTest, connectTest);

    UF5::UnionFind uf5 = UF5::UnionFind(n);
    testUF("UF5", uf5, unionTest, connectTest);

    UF6::UnionFind uf6 = UF6::UnionFind(n);
    testUF("UF6", uf6, unionTest, connectTest);
}

void test() {

    // 使用5,000,000的数据规模
    int n = 5000000;

    srand(time(NULL));

    // 生成unionElements的测试用例
    vector<pair<int, int>> unionTest;
    for (int i = 0; i < n; i++) {
        int a = rand() % n;
        int b = rand() % n;
        unionTest.push_back(make_pair(a, b));
    }

    // 生成isConnected的测试用例
    vector<pair<int, int>> connectTest;
    for (int i = 0; i < n; i++) {
        int a = rand() % n;
        int b = rand() % n;
        connectTest.push_back(make_pair(a, b));
    }

    // 测试我们的UF1 ~ UF6

    // 100万数据对于UF1和UF2来说太慢了, 不再测试
//    UF1::UnionFind uf1 = UF1::UnionFind(n);
//    UnionFindTestHelper::testUF("UF1", uf1, unionTest, connectTest);
//
//    UF2::UnionFind uf2 = UF2::UnionFind(n);
//    UnionFindTestHelper::testUF("UF2", uf2, unionTest, connectTest);

    UF3::UnionFind uf3 = UF3::UnionFind(n);
    UnionFindTestHelper::testUF("UF3", uf3, unionTest, connectTest);

    UF4::UnionFind uf4 = UF4::UnionFind(n);
    UnionFindTestHelper::testUF("UF4", uf4, unionTest, connectTest);

    UF5::UnionFind uf5 = UF5::UnionFind(n);
    UnionFindTestHelper::testUF("UF5", uf5, unionTest, connectTest);

    UF6::UnionFind uf6 = UF6::UnionFind(n);
    UnionFindTestHelper::testUF("UF6", uf6, unionTest, connectTest);
}

void testUF56() {

    // 为了能够方便地看出两种路径压缩算法的不同,我们只使用有5个元素的并查集进行试验
    int n = 5;

    UF5::UnionFind uf5 = UF5::UnionFind(n);
    UF6::UnionFind uf6 = UF6::UnionFind(n);

    // 我们将我们的并查集初始设置成如下的样子
    //            0
    //           /
    //          1
    //         /
    //        2
    //       /
    //      3
    //     /
    //    4
    for (int i = 1; i < n; i++) {
        uf5.parent[i] = i - 1;
        uf6.parent[i] = i - 1;
    }

    // 现在, 我们对两个并查集调用find(4)操作
    uf5.find(n - 1);
    uf6.find(n - 1);

    // 通过show, 我们可以看出, 使用迭代的路径压缩, 我们的并查集变成这个样子:
    //     0
    //    / \
    //   1   2
    //  / \
    // 3  4
    cout << "UF implements Path Compression by recursion:" << endl;
    uf5.show();

    cout << endl;

    // 使用递归的路径压缩, 我们的并查集变成这个样子:
    //     0
    //  / / \ \
    // 1 2   3 4
    cout << "UF implements Path Compression without recursion:" << endl;
    uf6.show();


    // 大家也可以调大n的值, 看看结果的不同:)

}


#endif //UNIONFIND_TEST_H
