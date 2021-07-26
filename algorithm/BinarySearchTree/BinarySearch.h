//
// Created by mo on 2021/7/26.
//

#ifndef BINARYSEARCHTREE_BINARYSEARCH_H
#define BINARYSEARCHTREE_BINARYSEARCH_H

template<typename T>
// 二分查找法,在有序数组arr中,查找target
// 如果找到target,返回相应的索引index
// 如果没有找到target,返回-1

int binarySearch(T array[],int n,T target)
{
    //在[l,r]中查找target
    int l=0,r =n -1;
    while(l <= r)
    {
//        int mid = (l+r)/2;
        //防止极端情况整型溢出，使用下面逻辑求出mid
        int mid = (r-l)/2 + l;
        if(array[mid]==target)
        {
            return mid;
        }
        if(array[mid] > target)
        {
            r = mid -1;
        }
        if (array[mid] < target)
        {
            l = mid + 1;
        }
        return -1;
    }
}
// 用递归的方式写二分查找法
template<typename T>
int __binarySearch2(T array [],int l,int r,T target)
{
    if(l>r)
        return -1;
    //int mid = (l+r)/2;
    //防止极端情况整型溢出，使用下面逻辑求出mid
    int mid = (r-l)/2 + l;

    if(array[mid]==target)
    {
        return mid;
    } else if(array[mid] > target)
    {
        return __binarySearch2(array,l,mid-1,target);
    } else
    {
        return __binarySearch2(array,mid+1,r,target);
    }
}
template<typename T>
int binarySearch2(T array [],int n,T target)
{
    return __binarySearch2(array,0,n-1,target);
}

// 比较非递归和递归写法的二分查找的效率
// 非递归算法在性能上有微弱优势

#endif //BINARYSEARCHTREE_BINARYSEARCH_H
