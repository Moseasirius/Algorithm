//
// Created by mozhenhai on 2021/8/1.
//

#ifndef GRAPHBASICS_TEST_H
#define GRAPHBASICS_TEST_H

#include "DenseGraph.h"
#include "SparseGraph.h"
#include "ReadGraph.h"
#include "Component.h"
#include "Path.h"
#include "ShortestPath.h"
#include <ctime>

void test() {

    int N = 20;
    int M = 120;

    srand(time(NULL));

    // Sparse Graph
    SparseGraph g1(N, false);
    for (int i = 0; i < M; i++) {
        int a = rand() % N;
        int b = rand() % N;
        g1.addEdge(a, b);
    }
    // O(E)
    cout << "Sparse Graph" << endl;
    for (int v = 0; v < N; v++) {
        cout << v << ":";
        SparseGraph::adjIterator adj(g1, v);
        for (int w = adj.begin(); !adj.end(); w = adj.next()) {
            cout << w << " ";
        }
        cout << endl;
    }
    cout << endl;
    // Dense Graph
    DenseGraph g2(N, false);
    for (int i = 0; i < M; i++) {
        int a = rand() % N;
        int b = rand() % N;
        g2.addEdge(a, b);
    }
    // O(V^2)
    cout << "Dense Graph" << endl;
    for (int v = 0; v < N; v++) {
        cout << v << ":";
        DenseGraph::adjIterator adj(g2, v);
        for (int w = adj.begin(); !adj.end(); w = adj.next())
            cout << w << " ";
        cout << endl;
    }
    cout << endl;
}

void test1() {
    string filename = "test1G1.txt";
    SparseGraph g1(13, false);
    ReadGraph<SparseGraph> readGraph1(g1, filename);
    g1.show();

    cout << endl;

    DenseGraph g2(13, false);
    ReadGraph<DenseGraph> readGraph2(g2, filename);
    g2.show();
    // 使用两种图的存储方式读取testG2.txt文件
    filename = "test1G2.txt";
    SparseGraph g3(6, false);
    ReadGraph<SparseGraph> readGraph3(g3, filename);
    cout << "test G2 in Sparse Graph:" << endl;
    g3.show();

    cout << endl;

    DenseGraph g4(6, false);
    ReadGraph<DenseGraph> readGraph4(g4, filename);
    cout << "test G2 in Dense Graph:" << endl;
    g4.show();
}

void test2() {
    string filename1 = "testG1.txt";
    SparseGraph g1 = SparseGraph(13, false);
    ReadGraph<SparseGraph> readGraph1(g1, filename1);
    Component<SparseGraph> component1(g1);
    cout << "testG1.txt, Component Count: " << component1.count() << endl;


    cout << endl;
    string filename2 = "testG2.txt";
    SparseGraph g2 = SparseGraph(7, false);
    ReadGraph<SparseGraph> readGraph2(g2, filename2);
    Component<SparseGraph> component2(g2);
    cout << "testG2.txt, Component Count: " << component2.count() << endl;

}

// 测试寻路算法
void testPathDFS() {
    string filename = "testG.txt";
    SparseGraph g = SparseGraph(7, false);
    ReadGraph<SparseGraph> readGraph(g, filename);
    g.show();
    cout << endl;

    Path<SparseGraph> path(g, 0);
    cout << "Path from 0 to 6 : " << endl;
    path.showPath(6);
}

// 测试无权图最短路径算法
void testShortestPath() {
    string filename = "testG.txt";
    SparseGraph g = SparseGraph(7, false);
    ReadGraph<SparseGraph> readGraph(g, filename);
    g.show();

    // 比较使用深度优先遍历和广度优先遍历获得路径的不同
    // 广度优先遍历获得的是无权图的最短路径
    Path<SparseGraph> dfs(g, 0);
    cout << "DFS : ";
    dfs.showPath(6);

    ShortestPath<SparseGraph> bfs(g, 0);
    cout << "BFS : ";
    bfs.showPath(6);

    cout << endl;

    filename = "testG1.txt";
    SparseGraph g2 = SparseGraph(13, false);
    ReadGraph<SparseGraph> readGraph2(g2, filename);
    g2.show();

    // 比较使用深度优先遍历和广度优先遍历获得路径的不同
    // 广度优先遍历获得的是无权图的最短路径
    Path<SparseGraph> dfs2(g2, 0);
    cout << "DFS : ";
    dfs2.showPath(3);

    ShortestPath<SparseGraph> bfs2(g, 0);
    cout << "BFS : ";
    bfs2.showPath(3);


}

#endif //GRAPHBASICS_TEST_H
