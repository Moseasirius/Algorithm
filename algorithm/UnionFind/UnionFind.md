

# 并查集 Union Find

 **连接问题**

网络中节点间的连接状态

网络是个抽象的概念：用户之间形成的网络

数学中的集合类实现

并查集 的并就是数学集合中的并

连接问题和路径问题

比路径问题要回答的问题少

1.和二分查找作比较

2.和select作比较

3.和堆作比较

### 并查集

对于一组数据，主要支持两个动作

union(p,q)

find(p)

用来回答一个问题 isConnected(p,q)  连接问题

### 并查集的一种实现思路Quick Find

并查集的基本数据表示 数组

| Id（数组下标） | 0    | 1    | 2    | 3    | 4    | 5    | 6    | 7    | 8    | 9    |
| -------------- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| Id[i]          | 0    | 0    | 0    | 0    | 0    | 1    | 1    | 1    | 1    | 1    |

比如，0到4对应的值为0,它们之间是相互连接的。5到9对应的值为1，它们是相互连接的。

```C++
 // 查找过程, 查找元素p所对应的集合编号
 int find(int p) {
     assert(p >= 0 && p <= count);
     return id[p];
 }

```



```c++
// 查看元素p和元素q是否所属一个集合
// O(1)复杂度
bool isConnected(int p, int q) {
    return find(p) == find(q);
}
```

```c++
 // 合并元素p和元素q所属的集合
 // O(n) 复杂度
 void unionSet(int p, int q) {
      int pId = find(p);
      int qId = find(q);
      if (pId == qId)
           return;
 // 合并过程需要遍历一遍所有元素, 将两个元素的所属集合编号合并，就是合并两个集合
       for (int i = 0; i < count; i++) {
           if (id[i] == pId)
                id[i] = qId;
            }
     }
```

### 并查集的另外一种实现思路Quick Union

将每一个元素，看做是一个节点

![](E:\AlgorithmAndDataStructure\algorithm\UnionFind\images\UnionFind1.png)

连接的时候，使用一个根指向另有一个根

![](E:\AlgorithmAndDataStructure\algorithm\UnionFind\images\UnionFind2.png)

```c++
        int find(int p) {
            assert(p >= 0 && p <= count);
            while (p != parent[p])
                p = parent[p];
            return p;
        }
```

```c++
        bool isConnected(int p, int q) {
            return find(p) == find(q);
        }
```

```c++
        void unionSet(int p, int q) {
            int pRoot = find(p);
            int qRoot = find(q);
            if (pRoot == qRoot)
                return;
            parent[pRoot] = qRoot;
        }
```

