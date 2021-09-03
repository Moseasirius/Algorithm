//
// Created by mozhenhai on 2021/8/26.
//

#ifndef CSP2021_CSP20210401_H
#define CSP2021_CSP20210401_H
#include<iostream>
using namespace std;


void TestCSP20210401()
{
    int n,m,l;
    cin>>n>>m>>l;
    int h[256]={0};
    int x;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>x;
            h[x]++;
        }
    }
    for(int i=0;i<l;i++){
        cout<<h[i]<<" ";
    }
    cout<<endl;
}
#endif //CSP2021_CSP20210401_H
