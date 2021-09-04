//
// Created by mozhenhai on 2021/9/3.
//

#ifndef ONEQUESTIONPERDAY_TEST_H
#define ONEQUESTIONPERDAY_TEST_H
#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

void testUnorderedMap(){
    unordered_map<char,vector<int>>myunorderedmap;
    unordered_map<char,vector<int>>::iterator it;
    myunorderedmap['a']=vector<int>{1,2,3,4};
    myunorderedmap['b']=vector<int>{7,8,9,10};
    vector<vector<int>> ans;

    for(it=myunorderedmap.begin();it!=myunorderedmap.end();it++){
        ans.push_back(it->second);
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        for(int j=0;j< ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}

#endif //ONEQUESTIONPERDAY_TEST_H
