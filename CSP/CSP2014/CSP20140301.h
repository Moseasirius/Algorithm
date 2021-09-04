//
// Created by mozhenhai on 2021/9/4.
//

#ifndef CSP2014_CSP20140301_H
#define CSP2014_CSP20140301_H

void testCSP20140301(){
    int n;
    cin>>n;
    int num[1000];
    int count=0;
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(num[i]+num[j]==0){
                count++;
            }
        }
    }
    cout<<count;
}
#endif //CSP2014_CSP20140301_H
