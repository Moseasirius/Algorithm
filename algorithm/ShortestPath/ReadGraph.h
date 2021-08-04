//
// Created by mozhenhai on 2021/8/4.
//

#ifndef SHORTESTPATH_READGRAPH_H
#define SHORTESTPATH_READGRAPH_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cassert>

using namespace std;

template <typename Graph,typename Weight>


// 读取图算法
class ReadGraph{

public:
    // 从文件filename中读取图的信息, 存储进图graph中
    ReadGraph(Graph &graph,const string &filename){
        ifstream file(filename);
        string line;
        int V,E;

        assert(file.is_open());

        // 第一行读取图中的节点个数和边的个数
        assert( getline(file,line));


        stringstream ss(line);
        ss>>V>>E;

        // 读取每一条边的信息
        for(int i=0;i<E;i++){
            assert(getline(file,line));
            stringstream ss(line);
            int a,b;
            Weight w;
            ss>>a>>b>>w;
            assert(a>=0 && a<V);
            assert(b>=0 && b<V);
            graph.addEdge(a,b,w);
        }

    }
};
#endif //SHORTESTPATH_READGRAPH_H
