//
// Created by mozhenhai on 2021/9/4.
//

#ifndef CSP2020_CSP20200602_H
#define CSP2020_CSP20200602_H

namespace CSP20200602(){
    void testCSP202006021(){
        //	ios::sync_with_stdio(false);//提速，减少运算时间
        int n,a,b;
        cin>>n>>a>>b;
        map<int,int> mapa;
        int index,value;
        long long result=0;
        for(int i=0;i<a;i++){
            cin>>index>>value;
            mapa[index]=value;
        }
        for(int i=0 ;i<b;i++){
            cin>>index>>value;
            if(mapa[index]!=0){
                result+=(mapa[index]*value);
            }
        }
        cout<<result<<endl;
    }
    void testCSP202006022(){
        int n,a,b;
        cin>>n>>a>>b;
        int index,value;
        long long result=0;

        int *arraya=new int[n];
        int *arrayb=new int[n];

        for(int i=0;i<n;i++){
            arraya[i]=0;
            arrayb[i]=0;
        }
        for(int i=0;i<a;i++){
            cin>>index>>value;
            arraya[index]=value;
        }
        for(int j=0;j<b;j++){
            cin>>index>>value;
            arrayb[index]=value;
        }
        for(int k=0;k<n;k++){
            result+=arraya[k]*arrayb[k];
        }
        cout<<result<<endl;
        delete [] arraya;
        delete [] arrayb;
    }

}
#endif //CSP2020_CSP20200602_H
