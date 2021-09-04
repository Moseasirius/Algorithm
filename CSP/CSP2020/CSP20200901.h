//
// Created by mozhenhai on 2021/9/4.
//

#ifndef CSP2020_CSP20200901_H
#define CSP2020_CSP20200901_H
//2020.11.03
#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
namespace CSP20200901{
    typedef struct Node{
        int x;
        int y;
        int id;
        double distance;
    }Node;

    bool cmp (Node a,Node b){
        if(a.distance!=b.distance){
            return a.distance<b.distance;
        }
        return a.id<b.id;
    }
//编写sort的排序方法，如果没有，默认从小到大排血

    void testCSP20200901(){
        int n,x,y;
        Node node[500];
        cin>>n>>x>>y;
        for(int i=0;i<n;i++){
            cin>>node[i].x>>node[i].y;
            node[i].id=i+1;
            node[i].distance=sqrt((node[i].x-x)*(node[i].x-x)+(node[i].y-y)*(node[i].y-y));


        }
        sort(node,node+n,cmp);
        for(int i=0;i<3;i++){
            cout<<node[i].id<<endl;
        }
    }
//为什么要用c++标准库里的排序函数
//Sort（）函数是c++一种排序方法之一，
//因为它使用的排序方法是类似于快排的方法，
//时间复杂度为n*log2(n)，执行效率较高！
//c++标准库里的排序函数的使用方法
//
//I）Sort函数包含在头文件为#include<algorithm>的c++标准库中，
//调用标准库里的排序方法可以不必知道其内部是如何实现的，
//只要出现我们想要的结果即可！
//
//II）Sort函数有三个参数：
//
//（1）第一个是要排序的数组的起始地址。
//
//（2）第二个是结束的地址（最后一位要排序的地址）
//
//（3）第三个参数是排序的方法，可以是从大到小也可是从小到大，
//     还可以不写第三个参数，此时默认的排序方法是从小到大排序。
//Sort函数使用模板:
//Sort(start,end,,排序方法)
}
#endif //CSP2020_CSP20200901_H
