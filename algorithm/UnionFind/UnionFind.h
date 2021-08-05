//
// Created by mo on 2021/7/29.
//

#ifndef UNIONFIND_UNIONFIND_H
#define UNIONFIND_UNIONFIND_H

#include <iostream>
#include <cassert>

using namespace std;
//第一版Union-Find
namespace UF1 {
    class UnionFind {

    private:
        int *id;//Union-Find本质就是一个数组
        int count; // 数据个数

    public:
        // 构造函数
        UnionFind(int n) {
            count = n;
            id = new int[n];
            // 初始化, 每一个id[i]指向自己, 没有合并的元素
            for (int i = 0; i < n; i++)
                id[i] = i;
        }

        //析构函数
        ~UnionFind() {
            delete[] id;
        }

        // 查找过程, 查找元素p所对应的集合编号
        int find(int p) {
            assert(p >= 0 && p <= count);
            return id[p];
        }

        // 查看元素p和元素q是否所属一个集合
        // O(1)复杂度
        bool isConnected(int p, int q) {
            return find(p) == find(q);
        }

        // 合并元素p和元素q所属的集合
        // O(n) 复杂度
        void unionSet(int p, int q) {
            int pId = find(p);
            int qId = find(q);
            if (pId == qId)
                return;
            // 合并过程需要遍历一遍所有元素, 将两个元素的所属集合编号合并，就是合并两个集合
            for (int i = 0; i < count; i++) {
                if (id[i] == pId)
                    id[i] = qId;
            }
        }
    };
}
//第二版Union-Find
namespace UF2 {
    class UnionFind {
    private:
        int *parent;
        int count;

    public:
        UnionFind(int count) {
            parent = new int[count];
            this->count = count;
            for (int i = 0; i < count; i++) {
                parent[i] = i;
            }
        }

        ~UnionFind() {
            delete[] parent;
        }

        int find(int p) {
            assert(p >= 0 && p <= count);
            while (p != parent[p])
                p = parent[p];
            return p;
        }

        bool isConnected(int p, int q) {
            return find(p) == find(q);
        }

        void unionSet(int p, int q) {
            int pRoot = find(p);
            int qRoot = find(q);
            if (pRoot == qRoot)
                return;
            parent[pRoot] = qRoot;
        }
    };
}
//第三版Union-Find
namespace UF3 {
    class UnionFind {
    private:
        int *parent; // parent[i]表示第i个元素所指向的父节点
        int *sz;// sz[i]表示以i为根的集合中元素个数
        int count;// 数据个数
    public:
        //构造函数
        UnionFind(int count) {
            parent = new int[count];
            sz = new int[count];
            this->count = count;
            for (int i = 0; i < count; i++) {
                parent[i] = i;
                sz[i] = 1;

            }

        }

        //析构函数
        ~UnionFind() {
            delete[] parent;
            delete[] sz;
        }

        // 查找过程, 查找元素p所对应的集合编号
        // O(h)复杂度, h为树的高度
        int find(int p) {
            assert(p >= 0 && p <= count);
            // 不断去查询自己的父亲节点, 直到到达根节点
            // 根节点的特点: parent[p] == p
            while (p != parent[p]) {
                p = parent[p];
            }
            return p;
        }

        // 查看元素p和元素q是否所属一个集合
        // O(h)复杂度, h为树的高度
        bool isConnected(int p, int q) {
            return find(p) == find(q);
        }

        // 合并元素p和元素q所属的集合
        // O(h)复杂度, h为树的高度
        void unionSet(int p, int q) {
            int pRoot = find(p);
            int qRoot = find(q);

            if (pRoot == qRoot)
                return;

            // 根据两个元素所在树的元素个数不同判断合并方向
            // 将元素个数少的集合合并到元素个数多的集合上

            if (sz[pRoot] < sz[qRoot]) {
                parent[pRoot] = qRoot;
                sz[qRoot] += sz[pRoot];
            } else {
                parent[qRoot] = pRoot;
                sz[pRoot] += sz[qRoot];
            }
        }
    };
}
//第四版Union-Find
namespace UF4 {
    class UnionFind {
    private:
        int *rank; // rank[i]表示以i为根的集合所表示的树的层数
        int *parent;// parent[i]表示第i个元素所指向的父节点
        int count; // 数据个数
    public:
        //构造函数
        UnionFind(int count) {
            parent = new int[count];
            rank = new int[count];
            this->count = count;
            for (int i = 0; i < count; i++) {
                parent[i] = i;
                rank[i] = 1;
            }
        }

        ~UnionFind() {
            delete[] parent;
            delete[] rank;
        }

        int find(int p) {
            assert(p >= 0 && p <= count);
            // 不断去查询自己的父亲节点, 直到到达根节点
            // 根节点的特点: parent[p] == p
            while (p != parent[p]) {
                p = parent[p];
            }
            return p;
        }

        // 查看元素p和元素q是否所属一个集合
        // O(h)复杂度, h为树的高度
        bool isConnected(int p, int q) {
            return find(p) == find(q);
        }
        // 合并元素p和元素q所属的集合
        // O(h)复杂度, h为树的高度

        void unionSet(int p, int q) {

            int pRoot = find(p);
            int qRoot = find(q);

            if (pRoot == qRoot)
                return;
            // 根据两个元素所在树的元素个数不同判断合并方向
            // 将元素个数少的集合合并到元素个数多的集合上
            if (rank[pRoot] < rank[qRoot]) {
                parent[pRoot] = qRoot;
            } else if (rank[pRoot] > rank[qRoot]) {
                parent[qRoot] = pRoot;
            } else {// rank[pRoot] == rank[qRoot]
                parent[pRoot] = qRoot;
                rank[qRoot] += 1;   // 此时, 我维护rank的值
            }
        }
    };
}
namespace UF5 {
    // rank[i]表示以i为根的集合所表示的树的层数
    // 在后续的代码中, 我们并不会维护rank的语意, 也就是rank的值在路径压缩的过程中, 有可能不在是树的层数值
    // 这也是我们的rank不叫height或者depth的原因, 他只是作为比较的一个标准
    class UnionFind {

    public: // 后续, 我们要在外部操控并查集的数据, 在这里使用public
        int *parent; // parent[i]表示第i个元素所指向的父节点

    private:
        int *rank; // rank[i]表示以i为根的集合所表示的树的层数
//        int* parent;// parent[i]表示第i个元素所指向的父节点
        int count; // 数据个数
    public:
        //构造函数
        UnionFind(int count) {
            parent = new int[count];
            rank = new int[count];
            this->count = count;
            for (int i = 0; i < count; i++) {
                parent[i] = i;
                rank[i] = 1;
            }
        }

        ~UnionFind() {
            delete[] parent;
            delete[] rank;
        }

        int find(int p) {
            assert(p >= 0 && p < count);
            // 不断去查询自己的父亲节点, 直到到达根节点
            // 根节点的特点: parent[p] == p

            // path compression 1
            while (p != parent[p]) {
                parent[p] = parent[parent[p]];
                p = parent[p];
            }
            return p;

            // path compression 2, 递归算法
//            if (p != parent[p]){
//                parent[p] = find(parent[p]);
//            }
//            return parent[p];
        }

        // 查看元素p和元素q是否所属一个集合
        // O(h)复杂度, h为树的高度
        bool isConnected(int p, int q) {
            return find(p) == find(q);
        }
        // 合并元素p和元素q所属的集合
        // O(h)复杂度, h为树的高度

        void unionSet(int p, int q) {

            int pRoot = find(p);
            int qRoot = find(q);

            if (pRoot == qRoot)
                return;
            // 根据两个元素所在树的元素个数不同判断合并方向
            // 将元素个数少的集合合并到元素个数多的集合上
            if (rank[pRoot] < rank[qRoot]) {
                parent[pRoot] = qRoot;
            } else if (rank[pRoot] > rank[qRoot]) {
                parent[qRoot] = pRoot;
            } else {// rank[pRoot] == rank[qRoot]
                parent[pRoot] = qRoot;
                rank[qRoot] += 1;   // 此时, 我维护rank的值
            }
        }

        // 打印输出并查集中的parent数据
        void show() {
            for (int i = 0; i < count; i++)
                cout << parent[i] << " ";
            cout << endl;
        }
    };
}
namespace UF6 {
    // rank[i]表示以i为根的集合所表示的树的层数
    // 在后续的代码中, 我们并不会维护rank的语意, 也就是rank的值在路径压缩的过程中, 有可能不在是树的层数值
    // 这也是我们的rank不叫height或者depth的原因, 他只是作为比较的一个标准
    class UnionFind {

    public: // 后续, 我们要在外部操控并查集的数据, 在这里使用public
        int *parent; // parent[i]表示第i个元素所指向的父节点

    private:
        int *rank; // rank[i]表示以i为根的集合所表示的树的层数
//        int* parent;// parent[i]表示第i个元素所指向的父节点
        int count; // 数据个数
    public:
        //构造函数
        UnionFind(int count) {
            parent = new int[count];
            rank = new int[count];
            this->count = count;
            for (int i = 0; i < count; i++) {
                parent[i] = i;
                rank[i] = 1;
            }
        }

        ~UnionFind() {
            delete[] parent;
            delete[] rank;
        }

        int find(int p) {
            assert(p >= 0 && p < count);
            // 不断去查询自己的父亲节点, 直到到达根节点
            // 根节点的特点: parent[p] == p

            // path compression 1
//            while(p != parent[p]){
//                parent[p] = parent[parent[p]];
//                p = parent[p];
//            }
//            return p;

            // path compression 2, 递归算法
            if (p != parent[p]) {
                parent[p] = find(parent[p]);
            }
            return parent[p];
        }

        // 查看元素p和元素q是否所属一个集合
        // O(h)复杂度, h为树的高度
        bool isConnected(int p, int q) {
            return find(p) == find(q);
        }
        // 合并元素p和元素q所属的集合
        // O(h)复杂度, h为树的高度

        void unionSet(int p, int q) {

            int pRoot = find(p);
            int qRoot = find(q);

            if (pRoot == qRoot)
                return;
            // 根据两个元素所在树的元素个数不同判断合并方向
            // 将元素个数少的集合合并到元素个数多的集合上
            if (rank[pRoot] < rank[qRoot]) {
                parent[pRoot] = qRoot;
            } else if (rank[pRoot] > rank[qRoot]) {
                parent[qRoot] = pRoot;
            } else {// rank[pRoot] == rank[qRoot]
                parent[pRoot] = qRoot;
                rank[qRoot] += 1;   // 此时, 我维护rank的值
            }
        }

        // 打印输出并查集中的parent数据
        void show() {
            for (int i = 0; i < count; i++)
                cout << parent[i] << " ";
            cout << endl;
        }
    };

}
#endif //UNIONFIND_UNIONFIND_H
