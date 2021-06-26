//
// Created by mo on 2021/6/24.
//

#ifndef SORT_BUBBLESORT_H
#define SORT_BUBBLESORT_H
#include<algorithm>
template<typename T>
void BubbleSort(T array,int length)
{
     int i , j;
     //总共需要进行多少次冒泡
     for(i=0;i<length-1;i++)
     {
         //每一次冒泡需要比较的次数
         for(j=0;j<length-1-i;j++)
         {
             if(array[j]>array[j+1])
             {
                 //比较以后，大的数往后面放
                 swap(array[j],array[j+1]);
             }
         }
     }
}
#endif //SORT_BUBBLESORT_H
