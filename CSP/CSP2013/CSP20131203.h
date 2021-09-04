//
// Created by mozhenhai on 2021/9/4.
//

#ifndef CSP2013_CSP20131203_H
#define CSP2013_CSP20131203_H

#include <iostream>
using namespace std;

void testCSP201303(){
    int n;
    int height[10001]={0};
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>height[i];
    }
    int max_area=0;
    for(int i=0;i<n;i++){
        int min_height=height[i];
        for(int j=i;j<n;j++){
            if(height[j]<min_height){
                min_height=height[j];
            }
            if(max_area<min_height*(j-i+1)){
                max_area=min_height*(j-i+1);
            }
        }
    }
    cout<<max_area;
}
#endif //CSP2013_CSP20131203_H
