//
// Created by mozhenhai on 2021/9/4.
//

#ifndef CSP2020_CSP20200601_H
#define CSP2020_CSP20200601_H

namespace CSP20200601{
    typedef struct Node{
        double x,y;
        char type;
    }Node;
    void testCSP20200601(){
        int n,m;
        Node node[1001];
        cin>>n>>m;
        for (int i=0;i<n;i++){
            cin>>node[i].x>>node[i].y>>node[i].type;
        }

        double n0,n1,n2;

        while(m--){
            cin>>n0>>n1>>n2;
            set<char> up,down;
            for( int i=0;i<n;i++){
                if(n0+n1*node[i].x+n2*node[i].y>0){
                    up.insert(node[i].type);
                }else {
                    down.insert(node[i].type);
                }
            }
            //在set中，size()返回的元素种类的个数，同一种元素即使有很多个，也算一个
            //所以我们可以用来判断分类是否正确，
            //如果set不是同一种元素，即size()的值大于1，则分类错误，反之则正确
            if(up.size()>1||down.size()>1){
                cout<<"No"<<endl;
            }
            else {
                cout<<"Yes"<<endl;
            }
        }
    }

}

#endif //CSP2020_CSP20200601_H
