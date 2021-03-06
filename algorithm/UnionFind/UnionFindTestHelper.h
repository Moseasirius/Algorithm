//
// Created by mozhenhai on 2021/7/30.
//

#ifndef UNIONFIND_UNIONFINDTESTHELPER_H
#define UNIONFIND_UNIONFINDTESTHELPER_H

#include <iostream>
#include <ctime>
#include <vector>
#include "UnionFind.h"

using namespace std;

// 测试并查集的辅助函数

namespace UnionFindTestHelper {
    // 测试第一版本的并查集, 测试元素个数为n
    void testUF1(int n) {

        srand(time(NULL));
        UF1::UnionFind uf = UF1::UnionFind(n);
        time_t startTime = clock();
        // 进行n次操作, 每次随机选择两个元素进行合并操作
        for (int i = 0; i < n; i++) {
            int a = rand() % n;
            int b = rand() % n;
            uf.unionSet(a, b);
        }
        // 再进行n次操作, 每次随机选择两个元素, 查询他们是否同属一个集合
        for (int i = 0; i < n; i++) {
            int a = rand() % n;
            int b = rand() % n;
            uf.isConnected(a, b);
        }
        time_t endTime = clock();

        // 打印输出对这2n个操作的耗时
        cout << "UF1, " << 2 * n << "  ops, " << double(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    }

    // 测试第二版本的并查集, 测试元素个数为n
    void testUF2(int n) {

        srand(time(NULL));
        UF2::UnionFind uf = UF2::UnionFind(n);
        time_t startTime = clock();
        // 进行n次操作, 每次随机选择两个元素进行合并操作
        for (int i = 0; i < n; i++) {
            int a = rand() % n;
            int b = rand() % n;
            uf.unionSet(a, b);
        }
        // 再进行n次操作, 每次随机选择两个元素, 查询他们是否同属一个集合
        for (int i = 0; i < n; i++) {
            int a = rand() % n;
            int b = rand() % n;
            uf.isConnected(a, b);
        }
        time_t endTime = clock();

        // 打印输出对这2n个操作的耗时
        cout << "UF2, " << 2 * n << "  ops, " << double(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    }

    // 测试第三版本的并查集, 测试元素个数为n
    void testUF3(int n) {
        srand(time(NULL));
        UF3::UnionFind uf = UF3::UnionFind(n);

        time_t startTime = clock();

        for (int i = 0; i < n; i++) {
            int a = rand() % n;
            int b = rand() % n;
            uf.unionSet(a, b);
        }
        for (int i = 0; i < n; i++) {
            int a = rand() % n;
            int b = rand() % n;
            uf.isConnected(a, b);
        }
        time_t endTime = clock();

        cout << "UF3, " << 2 * n << "  ops, " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
    }

    // 测试第四版本的并查集, 测试元素个数为n
    void testUF4(int n) {

        srand(time(NULL));
        UF4::UnionFind uf = UF4::UnionFind(n);

        time_t startTime = clock();

        for (int i = 0; i < n; i++) {
            int a = rand() % n;
            int b = rand() % n;
            uf.unionSet(a, b);
        }
        for (int i = 0; i < n; i++) {
            int a = rand() % n;
            int b = rand() % n;
            uf.isConnected(a, b);
        }
        time_t endTime = clock();

        cout << "UF4, " << 2 * n << "  ops, " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
    }

    // 测试第五版本的并查集, 测试元素个数为n
    void testUF5(int n) {

        srand(time(NULL));
        UF5::UnionFind uf = UF5::UnionFind(n);

        time_t startTime = clock();

        for (int i = 0; i < n; i++) {
            int a = rand() % n;
            int b = rand() % n;
            uf.unionSet(a, b);
        }
        for (int i = 0; i < n; i++) {
            int a = rand() % n;
            int b = rand() % n;
            uf.isConnected(a, b);
        }
        time_t endTime = clock();

        cout << "UF5, " << 2 * n << "  ops, " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
    }
    // 测试第六版本的并查集, 测试元素个数为n

    void testUF6(int n) {

        srand(time(NULL));
        UF6::UnionFind uf = UF6::UnionFind(n);

        time_t startTime = clock();

        for (int i = 0; i < n; i++) {
            int a = rand() % n;
            int b = rand() % n;
            uf.unionSet(a, b);
        }
        for (int i = 0; i < n; i++) {
            int a = rand() % n;
            int b = rand() % n;
            uf.isConnected(a, b);
        }
        time_t endTime = clock();

        cout << "UF6, " << 2 * n << "  ops, " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
    }

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
}

#endif //UNIONFIND_UNIONFINDTESTHELPER_H
