//
// Created by mozhenhai on 2021/9/4.
//

#ifndef CSP2014_CSP20140902_H
#define CSP2014_CSP20140902_H

namespace CSP20140902{
    typedef struct Node{
        int x1,y1,x2,y2;
    }Node;

    void testCSP20140902(){
        int n;
        cin>>n;
        Node node[101];
        for (int i=0;i<n;i++){
            cin>>node[i].x1>>node[i].y1>>node[i].x2>>node[i].y2;
        }
        int count=0;
        for(double i=0.1;i<100;i++){
            for(double j=0.1;j<100;j++){
                for(int k=0;k<n;k++){
                    if(i>node[k].x1&&i<node[k].x2&&
                       j>node[k].y1&&j<node[k].y2){
                        count++;break;}

                }
            }
        }
        cout<<count;
    }
}
#endif //CSP2014_CSP20140902_H
