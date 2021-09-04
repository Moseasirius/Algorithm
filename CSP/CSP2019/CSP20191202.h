//
// Created by mozhenhai on 2021/9/4.
//

#ifndef CSP2019_CSP20191202_H
#define CSP2019_CSP20191202_H

namespace CSP20191202{
    typedef struct Node{
        int x,y;
        int around=0;
        int score=0;
    }Node;
    void testCSP20191202(){
            Node node[1400];
            int res[5]={0};
            int n;
            cin>>n;
            for(int i=0;i<n;i++){
                cin>>node[i].x>>node[i].y;
            }
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(node[k].x==node[j].x+1&&node[k].y==node[j].y){
                        node[j].around++;}
                    if(node[k].x==node[j].x-1&&node[k].y==node[j].y){
                        node[j].around++;}
                    if(node[k].x==node[j].x&&node[k].y==node[j].y+1){
                        node[j].around++;}
                    if(node[k].x==node[j].x&&node[k].y==node[j].y-1){
                        node[j].around++;
                    }
                    if(node[k].x==node[j].x+1&&node[k].y==node[j].y+1){
                        node[j].score++;}
                    if(node[k].x==node[j].x+1&&node[k].y==node[j].y-1){
                        node[j].score++;}
                    if(node[k].x==node[j].x-1&&node[k].y==node[j].y+1){
                        node[j].score++;}
                    if(node[k].x==node[j].x-1&&node[k].y==node[j].y-1){
                        node[j].score++;}
                }
                if(node[j].around==4)res[node[j].score]++;
            }
            for(int j=0;j<5;j++){
                cout<<res[j]<<endl;
            }
    }
}
#endif //CSP2019_CSP20191202_H
