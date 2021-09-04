//
// Created by mozhenhai on 2021/9/4.
//

#ifndef CSP2013_CSP20131201_H
#define CSP2013_CSP20131201_H

#include <iostream>
using namespace std;

void testCSP201301(){
    int n;
    int num[10001]={0};
    int t;
    cin>>n;
    while(n--){
        cin>>t;
        num[t]++;
    }
    int temp=0,tempId=0;
    for(int i=0;i<10001;i++){
        if(num[i]>temp)	{
            temp=num[i];
            tempId=i;
        }
    }
    cout<<tempId;
}
#endif //CSP2013_CSP20131201_H
