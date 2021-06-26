//
// Created by mo on 2021/6/24.
//

#ifndef SORT_SELECTIONSORT_H
#define SORT_SELECTIONSORT_H
template<typename T>
void SelectionSort(T array [],int length)
{
    //总共需要进行多少次选择
    for (int i = 0; i < length-1; ++i)
    {
        int min=i;//假定每一轮起始的下标对应的值最小，注意这里是下标，往后找到最小值的下标
        for(int j=i+1;j<length;j++)
        {
            if(array[j]<array[min])
            {
             min=j;
            }
        }
        swap(array[i],array[min]);
    }
}
#endif //SORT_SELECTIONSORT_H
