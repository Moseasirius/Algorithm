//
// Created by mozhenhai on 2021/9/4.
//

#ifndef CSP2017_CSP20171201_H
#define CSP2017_CSP20171201_H


void testCSP20171201(){
    int n;
    cin>>n;
    int num[1002];
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    int submin_abs=abs(num[0]-num[1]);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(abs(num[i]-num[j])<=submin_abs){
                submin_abs=abs(num[i]-num[j]);
            }
        }
    }
    cout<<submin_abs;
}
#endif //CSP2017_CSP20171201_H
