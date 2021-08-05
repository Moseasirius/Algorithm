//
// Created by mozhenhai on 2021/8/1.
//

#ifndef GRAPHBASICS_COMPONENT_H
#define GRAPHBASICS_COMPONENT_H

#include <iostream>
#include <cassert>

template<typename Graph>
class Component {

private:
    Graph &G;// 图的引用  存储一份构造函数传进来的graph
    bool *visited;
    int cCount;//连通分量的个数
    int *id;

    void dfs(int v) {

        visited[v] = true;
        id[v] = cCount;

        typename Graph::adjIterator adj(G, v);
        for (int i = adj.begin(); !adj.end(); i = adj.next()) {
            if (!visited[i])
                dfs(i);
        }
    }


public:
    Component(Graph &graph) : G(graph) {
        visited = new bool[G.V()];
        id = new int[G.V()];
        cCount = 0;
        for (int i = 0; i < G.V(); i++) {
            visited[i] = false;
            id[i] = -1;
        }
        for (int i = 0; i < G.V(); i++) {
            if (!visited[i]) {
                dfs(i);
                cCount++;
            }
        }
    }

    ~Component() {
        delete[] visited;
        delete[] id;
    }

    int count() {
        return cCount;
    }

    bool isConnected(int v, int w) {
        assert(v >= 0 && v < G.V());
        assert(w >= 0 && w < G.V());
        return id[v] == id[w];
    }


};

#endif //GRAPHBASICS_COMPONENT_H
