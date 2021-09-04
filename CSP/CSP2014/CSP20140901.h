//
// Created by mozhenhai on 2021/9/4.
//

#ifndef CSP2014_CSP20140901_H
#define CSP2014_CSP20140901_H

void testCSP20140901(){
    int n;
    cin>>n;
    int num[1001];
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(num[i]-num[j]==1||num[i]-num[j]==-1)
                count++;
        }
    }
    cout<<count;
}
#endif //CSP2014_CSP20140901_H
