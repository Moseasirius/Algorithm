//
// Created by mozhenhai on 2021/9/4.
//

#ifndef CSP2019_CSP20190901_H
#define CSP2019_CSP20190901_H

void testCSP20190901(){
    int n,m,remain,pick;
    int t=0,k=0,p=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>remain;
        t=t+remain;
        int total=0;
        for(int j=0;j<m;j++){
            cin>>pick;
            t=t+pick;
            total=total-pick;
        }
        if(total>p){
            p=total;
            k=i+1;
        }
    }
    cout<<t<<" "<<k<<" "<<p;
}
#endif //CSP2019_CSP20190901_H
