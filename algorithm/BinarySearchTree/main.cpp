#include <iostream>
#include <cassert>
#include <ctime>

using namespace std;
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
int main() {
    std::cout << "Hello, World!" << std::endl;
    int n = 1000000;
    int* a = new int[n];
    for( int i = 0 ; i < n ; i ++ )
        a[i] = i;

    // 测试非递归二分查找法
    clock_t startTime = clock();

    // 对于我们的待查找数组[0...N)
    // 对[0...N)区间的数值使用二分查找，最终结果应该就是数字本身
    // 对[N...2*N)区间的数值使用二分查找，因为这些数字不在arr中，结果为-1
    for( int i = 0 ; i < 2*n ; i ++ ){
        int v = binarySearch(a, n, i);
//        if( i < n )
//            assert( v == i );
//        else
//            assert( v == -1 );
    }
    clock_t endTime = clock();
    cout << "Binary Search (Without Recursion): " << double(endTime - startTime) / CLOCKS_PER_SEC << " s"<<endl;


    // 测试递归的二分查找法
    startTime = clock();

    // 对于我们的待查找数组[0...N)
    // 对[0...N)区间的数值使用二分查找，最终结果应该就是数字本身
    // 对[N...2*N)区间的数值使用二分查找，因为这些数字不在arr中，结果为-1
    for( int i = 0 ; i < 2*n ; i ++ ){
        int v = binarySearch2(a, n, i);
//        if( i < n )
//            assert( v == i );
//        else
//            assert( v == -1 );
    }
    endTime = clock();
    cout << "Binary Search (Recursion): " << double(endTime - startTime) / CLOCKS_PER_SEC << " s"<<endl;

    delete[] a;


    return 0;
}
