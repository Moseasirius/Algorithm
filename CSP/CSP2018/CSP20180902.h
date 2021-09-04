//
// Created by mozhenhai on 2021/9/4.
//

#ifndef CSP2018_CSP20180902_H
#define CSP2018_CSP20180902_H

void testCSP20180902(){
    int n;

    cin>>n;

    int *time=new int[1000000];
    int a=0,b=0,c=0,d=0;
    int count=0;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        for(int j=a;j<b;j++){
            time[j]=1;
        }
    }
    for(int i=0;i<n;i++){
        cin>>c>>d;
        for(int j=c;j<d;j++){
            if(time[j]==1)
                count++;
        }
    }
    cout<<count<<endl;
}
#endif //CSP2018_CSP20180902_H
