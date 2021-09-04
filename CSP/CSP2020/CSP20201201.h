//
// Created by mozhenhai on 2021/9/4.
//

#ifndef CSP2020_CSP20201201_H
#define CSP2020_CSP20201201_H
void testCSP20201201(){
    int n;
    int w,score;
    cin>>n;
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>w>>score;
        sum+=w*score;
    }
    if(sum<0){
        sum=0;
    }
    cout<<sum;
}
#endif //CSP2020_CSP20201201_H
