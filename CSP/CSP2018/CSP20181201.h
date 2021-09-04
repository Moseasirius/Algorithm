//
// Created by mozhenhai on 2021/9/4.
//

#ifndef CSP2018_CSP20181201_H
#define CSP2018_CSP20181201_H

void testCSP20181201(){
    int r,y,g;
    int n;
    int k,t;
    int time=0;
    cin>>r>>y>>g;
    cin>>n;
    while(n--){
        cin>>k>>t;
        if(k == 0 || k == 1)
            time += t;
        else if(k == 2)
            time += t + r;
    }
    cout<<time;
}
#endif //CSP2018_CSP20181201_H
