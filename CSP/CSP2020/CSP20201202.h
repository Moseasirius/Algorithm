//
// Created by mozhenhai on 2021/9/4.
//

#ifndef CSP2020_CSP20201202_H
#define CSP2020_CSP20201202_H

namespace CSP202012021{
    typedef struct Node{
        int theta;
        int result;
    }Node;
    bool cmp(Node a,Node b){
        return a.theta<b.theta;
    }
    void testCSP202012021(){
        int m;
        Node node[100005];
        int flag0[100005]={0}; //记录小于每个位置点阈值的result=0的个数
        int flag1[100005]={0}; //记录大于等于每个位置点阈值的result=1的个数

        /*--输入--*/
        cin>>m;
        for(int i=0;i<m;i++){
            cin>>node[i].theta>>node[i].result;
        }
        sort(node,node+m,cmp); //输入后排序

        int i=0,j=1;
        int temp0=0,temp1=0;
        /*--统计小于每个阈值的result=0的个数--*/
        while(j<m){
            if(node[j].theta==node[i].theta){
                j++;
                continue;
            }
            int temp=0;
            while(i<j){
                if(node[i].result==0)temp++;
                flag0[i]=temp0;
                i++;
            }
            temp0+=temp;
        }
        while(i<j){
            flag0[i]=temp0;
            i++;
        }
        /*--以上统计小于每个阈值的result=0的个数--*/
        /*--以下统计大于等于每个阈值的result=1的个数--*/
        for(int i=0;i<m;i++){
            if(node[m-1-i].result==1){
                temp1++;
            }
            flag1[m-1-i]=temp1;
        }

        //根据flag0和flag1计算每个阈值的准确个数，输出最大的对应的阈值
        int ans=0,num=0;
        for(int i=0;i<m;i++){
            if(flag0[i]+flag1[i]>=num){
                num=flag0[i]+flag1[i];
                ans=node[i].theta;
            }
        }
        cout<<ans;

    }


}
namespace CSP202012022{
    typedef struct Node{
        int x;
        int y;
        int acr=0;
    }Node;
    bool cmp(Node a, Node b){
        if(a.acr!=b.acr){
            return a.acr>b.acr;
        }
        return a.x>b.x;
    }
    void testCSP20201202(){
        int n,x,y;
        Node node1[100000];
        Node node2[100000];
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>x>>y;
            node1[i].x=x;
            node2[i].x=x;
            node1[i].y=y;
            node2[i].y=y;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(node1[i].x<=node2[j].x&&node2[j].y==1
                   ||node1[i].x>node2[j].x&&node2[j].y==0){
                    node1[i].acr+=1;
                }
            }
        }

        sort(node1,node1+n,cmp);
        cout<<node1[0].x<<endl;

    }

}
namespace CSP202012023{
    typedef struct Node{
        int theta;
        int predict;
    }Node;

    bool cmp(Node a,Node b){
        return a.theta<b.theta;
    }

    void testCSP20201202(){
        int m;
        Node node[100005];
        int flag0[100005]={0}; //记录小于每个位置点阈值的result=0的个数
        int flag1[100005]={0}; //记录大于等于每个位置点阈值的result=1的个数

        cin>>m;
        for(int i=0;i<m;i++){
            cin>>node[i].theta>>node[i].predict;
        }
        sort(node,node+m,cmp); //输入后排序



        int thetaid=0;
        int max=0;


        for(int i=1;i<=m;i++){
            if(node[i].predict==0){
                flag0[i]=flag0[i-1]+1;
            }
            else{
                flag0[i]=flag0[i-1];
            }

        }

        for(int i=m;i>=1;i--){
            if(node[i].predict==1){
                flag1[i]=flag1[i+1]+1;
            }
            else{
                flag1[i]=flag1[i+1];
            }
        }


        for(int i=1;i<=m;i++){
            if(node[i].theta==node[i-1].theta)
            {
                continue;}

            if(flag0[i-1]+flag1[i]>max)
            {
                max=flag0[i-1]+flag1[i];
                thetaid=node[i].theta;}
        }
        cout<<thetaid;

    }

}
namespace CSP202012024{
    void testCSP20201202(){
        pair<int,int> pii[100005];      //pair数组储存信息，每个pair存储一个同学的y和result
        int pre0[100005];               //记录该位置及前面的result为0的个数（前缀和）
        int rear1[100005];              //记录该位置及后面的result为1的个数（后缀和）
        int k = -1,ma = 0;


        int m;
        cin>>m;                     //输入m
        pii[0] = pair<int,int>(-1,-1);
        for(int i = 1;i <= m;++i)   //初始化pii数组
            cin>>pii[i].first>>pii[i].second;
        sort(pii + 1,pii + 1 + m);  //将所有学生信息按照阈值从小到大排序，方便后续前缀后缀和的操作
        for(int i = 1;i <= m;++i)            //记录前缀0个数
            if(pii[i].second == 0)
                pre0[i] = pre0[i - 1] + 1;
            else
                pre0[i] = pre0[i - 1];
        for(int i = m;i >= 1;--i)           //记录后缀1个数
            if(pii[i].second == 1)
                rear1[i] = rear1[i + 1] + 1;
            else
                rear1[i] = rear1[i + 1];
        for(int i = 1;i <= m;++i){          //最终处理
            if(pii[i].first == pii[i - 1].first)
                continue;                   //如果有阈值相同的情况，那么在相同区间的第一个位置统计了，直接跳过
            if(ma <= pre0[i - 1] + rear1[i])//更新k和ma
                ma = pre0[i - 1] + rear1[i],k = pii[i].first;
        }
        cout<<k;

    }

}


#endif //CSP2020_CSP20201202_H
