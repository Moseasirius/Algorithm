//
// Created by mozhenhai on 2021/8/4.
//

#ifndef SHORTESTPATH_TEST_H
#define SHORTESTPATH_TEST_H

#include "DenseGraph.h"
#include "SparseGraph.h"
#include "ReadGraph.h"
#include "Dijkstra.h"
#include "BellmanFord.h"


// 测试我们的Dijkstra最短路径算法
void testDijkstra() {
    string filename = "testG1.txt";
    int V = 5;

    SparseGraph<int> g = SparseGraph<int>(V, true);
    // Dijkstra最短路径算法同样适用于有向图
    //SparseGraph<int> g = SparseGraph<int>(V, false);
    ReadGraph<SparseGraph<int>, int> readGraph(g, filename);

    cout << "Test Dijkstra:" << endl << endl;
    Dijkstra<SparseGraph<int>, int> dij(g, 0);
    for (int i = 1; i < V; i++) {
        if (dij.hasPathTo(i)) {
            cout << "Shortest Path to " << i << " : " << dij.shortestPathTo(i) << endl;
            dij.showPath(i);
        } else
            cout << "No Path to " << i << endl;

        cout << "----------" << endl;
    }
}

// 测试Bellman-Ford算法
void testBellmanFord() {
    string filename = "testG2.txt";
//    string filename = "testG_negative_circle.txt";
    int V = 5;

    SparseGraph<int> g = SparseGraph<int>(V, true);
    ReadGraph<SparseGraph<int>, int> readGraph(g, filename);

    cout << "Test Bellman-Ford:" << endl << endl;

    int s = 0;
    BellmanFord<SparseGraph<int>, int> bellmanFord(g, s);
    if (bellmanFord.negativeCycle())
        cout << "The graph contain negative cycle!" << endl;
    else
        for (int i = 0; i < V; i++) {
            if (i == s)
                continue;

            if (bellmanFord.hasPathTo(i)) {
                cout << "Shortest Path to " << i << " : " << bellmanFord.shortestPathTo(i) << endl;
                bellmanFord.showPath(i);
            } else
                cout << "No Path to " << i << endl;

            cout << "----------" << endl;
        }


}

#endif //SHORTESTPATH_TEST_H
