//
// Created by mozhenhai on 2021/9/4.
//

#ifndef CSP2019_CSP20191201_H
#define CSP2019_CSP20191201_H

namespace CSP20191201{

    int judge(int n){
            while(n){
                if(n%10==7)return 0;
                n=n/10;
            }
            return 1;
        }
    void testCSP20191201(){
            int n,num,res[5]={0};
            cin>>n;
            for(int i=1;num!=n;i++){
                if(i%7==0||judge(i)==0){
                    int index=i%4;//为了与数组下标对应
                    if(index==0)index=4;
                    res[index]++;
                }else num++;

            }
            for(int i=1;i<=4;i++)cout<<res[i]<<endl;
        }
    }
}

#endif //CSP2019_CSP20191201_H
