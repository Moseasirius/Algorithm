//
// Created by mozhenhai on 2021/9/4.
//

#ifndef CSP2018_CSP20180301_H
#define CSP2018_CSP20180301_H

void testCSP201803(){
    int n;
    int count=0;
    int point=0;
    int grade=0;
    cin>>n;
    while(n!=0){
        if(n==1){
            point=1;
            grade+=point;
        }else{
            if(point==1)point=2;
            else point+=2;
            grade+=point;
        }
        cin>>n;
    }
    cout<<grade;
}
#endif //CSP2018_CSP20180301_H
