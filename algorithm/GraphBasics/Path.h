//
// Created by mozhenhai on 2021/8/1.
//


#ifndef GRAPHBASICS_PATH_H
#define GRAPHBASICS_PATH_H

#include <iostream>
#include <vector>
#include <stack>
#include <cassert>

using namespace std;

template<typename Graph>
class Path {

private:
    Graph &G;
    int s;//起始点
    bool *visited;
    int *from;

    // 图的深度优先遍历
    void dfs(int v) {
        visited[v] = true;

        typename Graph::adjIterator adj(G, v);
        for (int i = adj.begin(); !adj.end(); i = adj.next()) {
            if (!visited[i]) {
                from[i] = v;
                dfs(i);
            }
        }
    }

public:
    // 构造函数, 寻路算法, 寻找图graph从s点到其他点的路径
    Path(Graph &graph, int s) : G(graph) {
        // 算法初始化

        assert(s >= 0 && s < G.V());
        visited = new bool[G.V()];
        from = new int[G.V()];

        for (int i = 0; i < G.V(); i++) {
            visited[i] = false;
            from[i] = -1;
        }
        this->s = s;
        // 寻路算法
        dfs(s);
    }

    //析构函数
    ~Path() {
        delete[] visited;
        delete[] from;
    }

    // 查询从s点到w点是否有路径
    bool hasPath(int w) {
        assert(w >= 0 && w < G.V());
        return visited[w];
    }

    void path(int w, vector<int> &vec) {
        assert(hasPath(w));

        stack<int> sStack;
        // 通过from数组逆向查找到从s到w的路径, 存放到栈中
        int p = w;
        while (p != -1) {
            sStack.push(p);
            p = from[p];
        }
        // 从栈中依次取出元素, 获得顺序的从s到w的路径

        vec.clear();
        while (!sStack.empty()) {
            vec.push_back(sStack.top());
            sStack.pop();
        }
    }

    // 打印出从s点到w点的路径
    void showPath(int w) {
        assert(hasPath(w));

        vector<int> vec;
        path(w, vec);
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i];
            if (i != vec.size() - 1)
                cout << " -> ";
            else
                cout << endl;
        }

    }


};

#endif //GRAPHBASICS_PATH_H
