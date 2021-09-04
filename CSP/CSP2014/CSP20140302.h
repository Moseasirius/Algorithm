//
// Created by mozhenhai on 2021/9/4.
//

#ifndef CSP2014_CSP20140302_H
#define CSP2014_CSP20140302_H

namespace  CSP20140302{

    typedef struct Node{
        int id;
        int x1,y1,x2,y2;
    }Node;

    void testCSP20140302(){
        int n,m;
        cin>>n>>m;
        Node node[100];

        for(int i=0;i<n;i++){
            node[i].id=i+1;
            cin>>node[i].x1>>node[i].y1>>node[i].x2>>node[i].y2;
        }
        int winid;
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
//		bool flag=true;//判断是否循环玩所有窗口
            winid=-1;
            for(int j=0;j<n;j++){
                if(x>=node[j].x1&&x<=node[j].x2
                   &&y>=node[j].y1&&y<=node[j].y2)
                {
                    winid=node[j].id;
                    cout<<winid<<endl;

                    //用来交换变到顶层的窗口，
                    //点击之后原来在后面的
                    //窗口变到前面

                    Node temp=node[j];
                    for(int k=j;k>0;k--){
                        node[k]=node[k-1];
                    }
                    node[0]=temp;
//			flag=false;
                    break;
                }
            }
            if(winid==-1)
                cout<<"IGNORED"<<endl;
//	   else
//	       cout<<winid<<endl;
        }
    }
}

#endif //CSP2014_CSP20140302_H
