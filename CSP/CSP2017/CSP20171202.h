//
// Created by mozhenhai on 2021/9/4.
//

#ifndef CSP2017_CSP20171202_H
#define CSP2017_CSP20171202_H

void testCSP20171202(){
    int n,k;
    cin>>n>>k;
    queue<int>q;
    for(int i=1;i<=n;i++){
        q.push(i);
    }
    int id=0,head;
    while(!q.empty()){
        head=q.front();
        q.pop();
        id++;
        if(id%k==0||id%10==k)
            ;
        else
            q.push(head);
    }
    cout<<head<<endl;
}
#endif //CSP2017_CSP20171202_H
