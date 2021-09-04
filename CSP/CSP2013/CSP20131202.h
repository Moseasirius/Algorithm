//
// Created by mozhenhai on 2021/9/4.
//

#ifndef CSP2013_CSP20131202_H
#define CSP2013_CSP20131202_H
#include <iostream>
using namespace std;
void testCSP20131202(){
    string str;
    cin>>str;
    int sum=0;
    int num=1;
    for(int i=0;i<str.size()-1;i++){
        if(str[i]>='0'&&str[i]<='9'){
            sum+=(str[i]-'0')*num;
            num++;

        }
    }
    int identify_code;
    identify_code=sum%11;
    char mantissa;
    if(identify_code==10){
        mantissa='X';
    }
    else{
        mantissa=identify_code+'0';
    }
    if(mantissa==str[str.size()-1]){
        cout<<"Right";
    }
    else{
        str[str.size()-1]=mantissa;
        cout<<str;
    }
}
#endif //CSP2013_CSP20131202_H
