# 排序算法

排序算法测试的辅助函数

```c++
namespace SortTestHelper {
    //生成有n个随机数的数组，每个元素的随机范围为[rangeL,rangeR]
    //这里只是使用int型数组，可以使用template<typename T>
    int *generateRandomArray(int n, int range_l, int range_r) {
        int *array = new int[n];
        //设置随机数种子
        srand(time(NULL));
        for (int i = 0; i < n; i++) {
            array[i] = rand() % (range_r - range_l + 1) + range_l;
        }
        return array;
        //注意这里申请了内存空间，使用完以后记得释放内存
    }

    //生成一个近乎有序的数组，
    //首先生成一个[0...n-1]的完全有序数组，然后随机交换swapTimes对数据
    //swapTimes定义了数组无序的程度
    int *generateNearlyOrderedArray(int n, int swapTimes) {
        int *array = new int[n];
        for (int i = 0; i < n; i++) {
            array[i] = i;
        }
        srand(time(NULL));
        for (int i = 0; i < swapTimes; i++) {
            int pos1 = rand() % n;//交换的位置1
            int pos2 = rand() % n;//交换的位置2
            swap(array[pos1], array[pos2]);
        }
        return array;
        //这里申请了内存空间，使用完以后记得释放
    }

    //拷贝数组a中的元素的新的数组，并返回新的数组
    int *copyArray(int a[], int n) {
        int *array = new int[n];
        for (int i = 0; i < n; i++) {
            array[i] = a[i];
        }
        return array;
        //这里申请了内存空间，使用完后记得释放
    }

    //打印数组内容
    template<typename T>
    void printArray(T array[], int n) {
        for (int i = 0; i < n; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    // 判断arr数组是否有序
    template<typename T>
    bool isSorted(T arr[], int n) {

        for (int i = 0; i < n - 1; i++)
            if (arr[i] > arr[i + 1])
                return false;

        return true;
    }
     template<typename T>
    void testSort(const string &sortName, void (*sort)(T [], int), T array[], int n) {
        clock_t startTime = clock();
        sort(array, n);
        clock_t endTime = clock();
//        cout<<endTime-startTime<<endl;
//        cout<<CLOCKS_PER_SEC<<endl;
        cout << sortName << " " << double(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
        //CLOCKS_PER_SEC 每秒钟的时钟周期数

        assert(isSorted(array, n));
//        cout<<isSorted(array,n)<<endl;
        cout << "############################################################" << endl;
        return;
    }

}

```



## O（n^2)

为什么要学习O（n^2)的排序算法

基础 编码简单，易于实现，是一些简单情景的首选

在一些特殊情况下，简单的排序算法更有效

简单的排序算法思想衍生出复杂的排序算法

作为子过程，改进更加复杂的排序算法

### 冒泡排序 Bubble Sort

```c++
template<typename T>
void BubbleSort(T array, int length) {
    int i, j;
    //总共需要进行多少次冒泡
    for (i = 0; i < length - 1; i++) {
        //每一次冒泡需要比较的次数
        for (j = 0; j < length - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                //比较以后，大的数往后面放
                swap(array[j], array[j + 1]);
            }
        }
    }
}
```



### 选择排序  Selection Sort

```c++
template<typename T>
void SelectionSort(T array[], int length) {
    //总共需要进行多少次选择
    for (int i = 0; i < length - 1; ++i) {
        int min = i;//假定每一轮起始的下标对应的值最小，注意这里是下标，往后找到最小值的下标
        for (int j = i + 1; j < length; j++) {
            if (array[j] < array[min]) {
                min = j;
            }
        }
        swap(array[i], array[min]);
    }
}
```



### 插入排序  Insertion Sort

```c++

template<typename T>
void InsertionSort(T array[], int length) {
    //假设i前面已经排好序
    for (int i = 1; i < length; i++) {
        //从i往前比较，如果大于或者等于就停止比较，如果小于就交换
        for (int j = i; j > 0 && array[j - 1] > array[j]; j--)//注意这种写法j不能等于0 因为j-1会数组越界，产生错误。
        {
            swap(array[j - 1], array[j]);
        }
        //或者可以写成这样
//        for(int j=i;j>=0;j--)
//        {
//            if(array[j-1]>array[j])
//                swap(array[j-1],array[j]);
//            else
//                break;//之前自己忘记写如果条件不满足break循环，导致一些错误，就是数组元素变为很大的值，可能是数组越界了
//        }
    }
}

//第一种插入排序交换次数比较多，优化，只需要比较，需要最后一次交换。
template<typename T>
void InsertionSort_advance(T array[], int length) {
    //假设i前面已经排好序
    for (int i = 1; i < length; i++) {
        //从i往前比较，如果小于就一直比较，直到大于等于就停止比较
        int key = array[i];
        int j;
        for (j = i; j >= 0 && array[j - 1] > key; j--)
            array[j] = array[j - 1];
        array[j] = key;//这里的array[j]与上一行的array[j]不一样
    }
}
```



### 希尔排序 Shell Sort

```C++
template<typename T>
void ShellSort(T array[], int length) {
    //计算 increment sequence: 1, 4, 13, 40, 121, 364, 1093...
    int step = 1;
    while (step < length / 3)
        step = step * 3 + 1;//跳出循环之后，step为increment sequence 的一项，该项大于或等于且最靠近length/3

    while (step >= 1) {
        //思想就是，按步长分组，每一组按照插入排序思想排序
        for (int i = step; i < length; i++) {
            //插入排序思想
            for (int j = i; j >= 0 && array[j - setp] > array[j]; j--) {
                swap(array[j - step], array[j]);
            }
        }
        step = step / 3;//步长变小
    }
}

void ShellSort_advance(T array[], int length) {
    //计算 increment sequence: 1, 4, 13, 40, 121, 364, 1093...
    int step = 1;
    while (step < length / 3)
        step = step * 3 + 1;//跳出循环之后，step为increment sequence 的一项，该项大于或等于且最靠近length/3
    //int step = length/2;//可以这样设置步长
    while (step >= 1) {
        //思想就是，按步长分组，每一组按照插入排序思想排序
        for (int i = step; i < length; i++) {
            //插入排序思想
            int j;
            int key = array[i];
            for (j = i; j >= 0 && array[j - setp] > key; j--) {
                array[j] = array[j - step];
            }
            array[j] = key;
        }
        step = step / 3;//步长变小
        //step=step/2;
    }
}
```



### 归并排序 Merge Sort

```c++

//l:left m:middle r:right 使用的是左闭右闭区间[l,r]
template<typename T>
//__表示私有函数
void __merge(T array[], int l, int mid, int r) {
    T aux[r - l + 1];
    //
    for (int i = l; i <= r; i++) {
        aux[i - l] = array[i];
    }
    //初始化，i指向左半部分数组的起始索引位置l,j指向右半部分数组的起始索引位置mid+1
    int i = l, j = mid + 1;
    for (int k = l; k <= r; k++) {
        if (i > mid)//如果左半部分数组已经处理完毕
        {
            array[k] = aux[j - l];
            j++;
        } else if (j > r)//如果右半部分数组已经处理完毕
        {
            array[k] = aux[i - l];
            i++;
        } else if (aux[i - l] < aux[j - l])//左半部分索引指的元素小于右半部分索引指的数组的元素
        {
            array[k] = aux[i - l];
            i++;
        } else//右半部分索引指的元素小于左半部分数组索引指的元素
        {
            array[k] = aux[j - l];
            j++;
        }

    }
}

template<typename T>
//__表示私有函数
void __mergesort(T array[], int l, int r) {
    if (l >= r)
        return;
    int mid = l + (r - l) / 2; //等价于(l+r)/2 为了防止溢出，如果l和r都很大，两个很大int型的数相加可能会溢出
    __mergesort(array, l, mid);
    __mergesort(array, mid + 1, r);
    __merge(array, l, mid, r);
}

template<typename T>
void MergeSort(T array[], int length) {
    __mergesort(array, 0, length - 1);
}
```

### 快速排序  Quick Sort

```c++
//对array[l,r]进行partition操作
template<typename T>
int __partition(T array[], int l, int r) {
    swap(array[l], array[rand() % (r - l + 1) + l]);//[l,r]的任意一个索引
    T v = array[l];

    //array[l+1,j]<v array[j+1,i)>v 为什么是开区间 因为当前考察的是第i个元素
    int j = l;
    for (int i = l + 1; i <= r; i++) {
        if (array[i] < v) {
            swap(array[j + 1], array[i]);
            j++;
        }
    }
    swap(array[l], array[j]);
    return j;
}

//对array[l,r]部分进行快速排序
template<typename T>
void __quickSort(T array[], int l, int r) {
    if (l >= r)
        return;
    int p = __partition(array, l, r);
    __quickSort(array, l, p - 1);
    __quickSort(array, p + 1, r);
}

template<typename T>
void QuickSort(T array[], int n) {
    srand(time(NULL));
    __quickSort(array, 0, n - 1);
}

//QuickSort2
//对array[l,r]进行partition操作
template<typename T>
int __partition2(T array[], int l, int r) {
    swap(array[l], array[rand() % (r - l + 1) + l]);//[l,r]的任意一个索引
    T v = array[l];

    //array[l+1,j]<=v array(j+1,i]>=v
    int i = l + 1, j = r;
    while (true) {
        while (i <= r && array[i] < v) i++;
        while (j >= l + 1 && array[j] > v) j--;
        if (i > j) break;
        swap(array[i], array[j]);
        i++;
        j--;
    }
    swap(array[l], array[j]);
    return j;
}

//对array[l,r]部分进行快速排序
template<typename T>
void __quickSort2(T array[], int l, int r) {
    if (l >= r)
        return;

    int p = __partition2(array, l, r);
    __quickSort2(array, l, p - 1);
    __quickSort2(array, p + 1, r);
}

template<typename T>
void QuickSort2(T array[], int n) {
    srand(time(NULL));
    __quickSort2(array, 0, n - 1);
}

//递归三路快速排序算法
template<typename T>
void __quickSort3ways(T array[], int l, int r) {
    if (l >= r)
        return;

    swap(array[l], array[rand() % (r - l + 1) + l]);//[l,r]的任意一个索引
    T v = array[l];

    int lt = l; //array[l+1,lt]<v
    int gt = r + 1; //array[gt,r]>v
    int i = l + 1;//array[lt+1,i]==v

    while (i < gt) {
        if (array[i] < v) {
            swap(array[i], array[lt + 1]);
            i++;
            lt++;
        } else if (array[i] > v) {
            swap(array[i], array[gt - 1]);
            gt--;
        } else//array[i]==v
        {
            i++;
        }
    }
    swap(array[l], array[lt]);
    __quickSort3ways(array, l, lt - 1);
    __quickSort3ways(array, gt, r);
}

template<typename T>
void QuickSort3ways(T array[], int n) {
    srand(time(NULL));
    __quickSort3ways(array, 0, n - 1);
}
```

测试算法的性能

在特定的数据集上运行的时间

```c++
void test() {
    int n = 10000;
    //测试1，一般测试
    cout << "Test for random array ,size= " << n << ",random range [0," << n << "]" << endl;

    int *array1 = SortTestHelper::generateRandomArray(n, 0, n);
    int *array2 = SortTestHelper::copyArray(array1, n);
    int *array3 = SortTestHelper::copyArray(array1, n);
    int *array4 = SortTestHelper::copyArray(array1, n);
    int *array5 = SortTestHelper::copyArray(array1, n);

    SortTestHelper::testSort("Bubble Sort", BubbleSort, array1, n);
    SortTestHelper::testSort("Selection Sort", SelectionSort, array2, n);
    SortTestHelper::testSort("Insertion", InsertionSort, array3, n);
    SortTestHelper::testSort("Merge Sort", MergeSort, array4, n);
    SortTestHelper::testSort("Quick Sort", QuickSort, array5, n);

    delete[] array1;
    delete[] array2;
    delete[] array3;
    delete[] array4;
    delete[] array5;

    cout << endl;
}
```

![](E:\AlgorithmAndDataStructure\algorithm\Sort\testImg\img.png)

排序算法的总结

|      |
| :--: |

|          | 平均时间复杂度 | 原地排序 | 额外空间  | 稳定性 |
| -------- | -------------- | -------- | --------- | ------ |
| 插入排序 | O(n^2)         | 是       | O(1)      | 是     |
| 归并排序 | O(nlogn)       | 不是     | O(n+logn) | 是     |
| 快速排序 | O(nlogn)       | 是       | O(logn)   | 不是   |
| 堆排序   | O(nlogn)       | 不是     | O(1)      | 不是   |

排序算法的稳定性

Stable

稳定排序：相对于相等的元素，在排序后，原来靠前的元素依然靠前。相等元素的相对位置没有发生改变。



| 4    | 3（1） | 2    | 3（3） | 1    | 5    | 3（3） | 6    |
| ---- | ------ | ---- | ------ | ---- | ---- | ------ | ---- |

| 1    | 2    | 3（1） | 3（2） | 3(3) | 4    | 5    | 6    |
| ---- | ---- | ------ | ------ | ---- | ---- | ---- | ---- |

在现实生活中的应用

学生成绩表原先按姓名的字典序排序，现在在按分数高低排序后，稳定的排序算法就是可以做到，相同分数的学生按姓名的字典序排序。

稳定性是和具体实现相关的，如果你实现不好，可能会将插入排序和归并排序设计为不稳定的排序

可以通过自定义比较函数，让排序算法不存在稳定性的问题

是否存在神秘的排序算法符合所有的最低标准

