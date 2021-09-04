//
// Created by mozhenhai on 2021/9/4.
//

#ifndef CSP2019_CSP20190902_H
#define CSP2019_CSP20190902_H

void testCSP20190902(){
    int N;
    int m;
    int a;
    int total;
    int T=0,D=0,E=0;
    int tree[1009]={0};
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>m;
        cin>>total;

        for(int j=0;j<m-1;j++){
            cin>>a;
            if(a<=0){
                total=total+a;}
            else{
                if(a<total){
                    total=a;
//				D++;//?这样统计发生掉落的树的数目只能得五十分。
                    tree[i]=1;//记录发生苹果掉落的树，为了统计连续三棵树发生苹果掉落
                }
            }
        }
        T=T+total;
    }
    for(int i=0;i<N;i++){
        D+=tree[i];
        if(tree[i]==1&&tree[(i+1)%N]==1&&tree[(i+2)%N]==1)E++;
    }
    cout<<T<<" "<<D<<" "<<E;
}
#endif //CSP2019_CSP20190902_H
