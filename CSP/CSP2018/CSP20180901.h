//
// Created by mozhenhai on 2021/9/4.
//

#ifndef CSP2018_CSP20180901_H
#define CSP2018_CSP20180901_H

//注意空格，少空格零分
void testCSP20180901(){
    int n;
    cin>>n;
    int first_dayp[1008]={0};
    int second_dayp[1008]={0};
    for(int i=1;i<=n;i++){
        cin>>first_dayp[i];
    }
    for(int i=2;i<n;i++){

        second_dayp[i]=(first_dayp[i-1]+first_dayp[i]+first_dayp[i+1])/3;
    }
    second_dayp[1]=(first_dayp[1]+first_dayp[2])/2;
    second_dayp[n]=(first_dayp[n]+first_dayp[n-1])/2;
    cout<<second_dayp[1]<<" ";
    for(int i=2;i<n;i++){
        cout<<second_dayp[i]<<" ";
    }
    cout<<second_dayp[n];

}
#endif //CSP2018_CSP20180901_H
