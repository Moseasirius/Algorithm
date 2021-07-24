//
// Created by mo on 2021/7/24.
//

#ifndef SORT_INDEXHEAP_H
#define SORT_INDEXHEAP_H
//索引堆
//数据和索引分开存储
//构建堆的过程和对数据的操作对索引操作就行
template<typename Item>
class IndexMaxHeap{

private:
    Item* data;
    int* indexes;
    int* reverse;

    int count;
    int capacity;
    void shiftUp(int k)
    {
        while (k>1&&data[indexes[k/2]]<data[indexes[k]])//k>1防止越界父节点的元素值是否小于子节点
        {
            swap(indexes[k/2],indexes[k]);
            reverse[k/2]=k/2;
            reverse[k]=k;
            k/=2;//更新k

        }
    }
    void shiftDown(int k)
    {
        //判断k节点有孩子，这里判断左孩子，一棵完全二叉树中，可能只有左孩子而没有右孩子，不可能只有右孩子而没有左孩子
        while (2*k<=count)
        {
            int j = 2*k;//在此轮循环中，data[k]和data[j]交换位置
            if(j+1<=count&&data[indexes[j+1]]>data[indexes[j]])//说明有右孩子，而且右孩子的值比左孩子的值大
            {
                j=j+1;
            }
            // data[j] 是 data[2*k]和data[2*k+1]中的最大值
            if(data[indexes[k]]>=data[indexes[j]])
                break;
            swap(indexes[k],indexes[j]);//可以优化，不用每一遍都swap，可以最后再交换(插入排序优化  思想）
            reverse[indexes[k]]=k;
            reverse[indexes[j]]=j;
            k=j;
        }
    }
public:
    //构造函数，构造一个空堆，可容纳capacity个元素
    IndexMaxHeap(int capacity)
    {
        data = new Item[capacity+1];//因为我们从数组下标索引1开始存数据
        indexes = new int[capacity+1];
        reverse = new int[capacity+1];
        for(int i=0;i<=capacity;i++)
        {
            reverse[i]=0;
        }
        count = 0;
        this->capacity = capacity;
    }

    //Heapify
    IndexMaxHeap(Item array[],int n)
    {
        data = new Item[n+1];
        capacity = n;
        for(int i=0;i<n;i++)
        {
            data[i+1]==array[i];

        }
        count = n;
        for(int i= count/2;i>=1;i--)
        {
            shiftDown(i);
        }
    }

    //析构函数
    ~IndexMaxHeap()
    {
        delete [] data;
        delete [] indexes;
        delete [] reverse;

    }

    //返回堆中元素的个数
    int size()
    {
        return  count;
    }
    // 返回一个布尔值, 表示索引堆中是否为空
    bool isEmpty()
    {
        return count == 0;
    }
    // 向最大索引堆中插入一个新的元素, 新元素的索引为i, 元素为item
    // 传入的i对用户而言,是从0索引的
    void insert(int i,Item item)//内部1从开始，外部从0开始，用户看不到
    {
        assert(count+1<=capacity);
        assert(i+1 >= 1 && i+1 <=capacity);

        i=i+1;
        data[i] = item;//隐藏数组越界问题,可以先判断后开辟新的空间解决
        indexes[count+1]=i;
        reverse[i]=count+1;


        count++;
        shiftUp(count);
    }

    void print()
    {
        for(int i = 1;i <= size();i++)
        {
            cout<< data[i]<<" ";
        }
        cout<<endl;
    }

    // 从最大索引堆中取出堆顶元素, 即索引堆中所存储的最大数据
    Item extractMax()
    {
        assert(count>0);
        Item ret = data[indexes[1]];
        swap(indexes[1],indexes[count]);
        reverse[indexes[1]]=1;
        reverse[indexes[count]]=0;

        count--;
        shiftDown(1);
        return ret;
    }

    // 从最大索引堆中取出堆顶元素的索引
    int extractMaxIndex()
    {
        assert(count>0);
        Item ret = indexes[1]-1;
        swap(indexes[1],indexes[count]);
        reverse[indexes[1]]=1;
        reverse[indexes[count]]=0;
        count--;
        shiftDown(1);
        return ret;
    }
    bool contain(int i)
    {
        return reverse[i+1]!=0;
    }

    // 获取最大索引堆中索引为i的元素
    Item getItem(int i)
    {
        assert(contain(i));
        return data[i+1];

    }
    // 将最大索引堆中索引为i的元素修改为newItem
    void change(int i,Item newItem)
    {
        assert(contain(i));
        i+=1;
        data[i]=newItem;
        //找到Indexes[j]=i,j表示data[i]在堆中的位置
        //之后再shiftDown(j)和shiftUp(j)
//        for(int j=1;j<=count;j++)
//        {
//            if(indexes[j]==i)
//            {
//                shiftDown(j);
//                shiftUp(j);
//            }
//        }
        int j= reverse[i];
        shiftDown(j);
        shiftUp(j);
    }

};



#endif //SORT_INDEXHEAP_H
