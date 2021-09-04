//
// Created by mozhenhai on 2021/9/4.
//

#ifndef CSP2018_CSP20181202_H
#define CSP2018_CSP20181202_H

void testCSP20181202(){
    int r,y,g,k;
    int n;
    cin>>r>>y>>g;
    cin>>n;
    long long  t,temp,res=0;
    while(n--){
        cin>>k>>t;
        if(k==0){
            res+=t;
            continue;
        }
        temp=res%(r+y+g);
        while(temp>=t){
            temp-=t;
            if(k==1){
                t=g;k=3;
            }else if(k==2){
                t=r;k=1;
            } else if(k==3){
                t=y;k=2;
            }

        }
        t-=temp;
        if(k==1)res+=t;
        if(k==2)res+=t+r;
    }
    cout<<res;
}
#endif //CSP2018_CSP20181202_H
