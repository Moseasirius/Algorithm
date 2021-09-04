//
// Created by mozhenhai on 2021/9/4.
//

#ifndef CSP2019_CSP20190301_H
#define CSP2019_CSP20190301_H

void testCSP20190301(){
    int n;
    int data[100001]={0};
    int max,min;
    double median;
    cin>>n;


    for(int i=0;i<n;i++){
        cin>>data[i];
    }
    if(data[0]>=data[n-1]){
        max=data[0];
        min=data[n-1];
    }
    if(data[0]<data[n-1]){
        max=data[n-1];
        min=data[0];
    }

    if(n%2==0){
        median=(data[n/2]+data[n/2-1])*1.0/2;
        if(median==(int)median){

            printf("%d %.0f %d",max,median,min);// 保留整数
        }else{
            printf("%d %.1f %d",max,median,min);//  保留一位小数
        }
    }
    else{
        median=data[n/2];
//		printf("%d %d %d",max,(int)median,min);//中位数注意保留整数
        printf("%d %.0f %d",max,median,min);//中位数注意保留整数
        //两种方法都行。
    }
}
#endif //CSP2019_CSP20190301_H
