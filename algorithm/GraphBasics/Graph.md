## 无向图是一种特殊的有向图

有权图 weighted Graph

无权图 unweighted Graph

## 图的连通性

简单图 simple Graph

自环边 self- loop 平行边 parallel-edges

## 图的表示

### 邻接矩阵 adjacency matrix

```
  0 1 2 3 4
0 0 0 0 0 1
1 0 1 0 1 0
2 0 0 0 1 0
3 0 0 0 0 0
4 1 1 0 0 1
有向图
```

### 邻接表 adjacency lists

```
0 1

1 0 2 3

2 1 3

3 1 2
```

每一行相当于一个链表

优势 存储空间少

邻接表适合表示稀疏图 spare graph 边相对少

邻接矩阵适合表示稠密图 dense graph 边相对多

对于多少的定义具体情况具体分析

## 稠密图 和 完全图

构造函数初始化列表以一个冒号开始， 接着是以逗号分隔的数据成员列表，每个数据成员后面跟一个放在括号中的初始化式。例如：

```c++
class CExample {
public:
int a;
float b;
//构造函数初始化列表
CExample(): a(0), b(8.8)
{
}
//构造函数内部赋值
CExample()
{
a=0;
b=8.8;
}
};
```

上面两个构造函数的结果是一样的。上面的构造函数（使用初始化列表的构造函数）显式的初始化类的成员；而没使用初始化列表的构造函数是对类的成员赋值，并没有进行显式的初始化。

初始化和赋值对内置类型的成员没有什么大的区别，像上面的任一个构造函数都可以。对非内置类型成员变量，为了避免两次构造，推荐使用类构造函数初始化列表。但有的时候必须用带有初始化列表的构造函数：

- .成员类型是**没有默认构造函数的类**。若没有提供显示初始化式，则编译器隐式使用成员类型的默认构造函数，若类没有默认构造函数，则编译器尝试使用默认构造函数将会失败。
- 2.**const 成员**或**引用类型**的成员。因为 const 对象或引用类型只能初始化，不能对他们赋值。

**初始化数据成员与对数据成员赋值的含义是什么？有什么区别？**

首先把数据成员按类型分类并分情况说明:

- 1.**内置数据类型，复合类型（指针，引用）**- 在成员初始化列表和构造函数体内进行，在性能和结果上都是一样的

- 2.**用户定义类型（类类型）**-
  结果上相同，但是性能上存在很大的差别。因为类类型的数据成员对象在进入函数体前已经构造完成，也就是说在成员初始化列表处进行构造对象的工作，调用构造函数，在进入函数体之后，进行的是对已经构造好的类对象的赋值，又调用个拷贝赋值操作符才能完成（如果并未提供，则使用编译器提供的默认按成员赋值行为）

  **注意点：**

  初始化列表的成员初始化顺序:

  C++ 初始化类成员时，是按照声明的顺序初始化的，而不是按照出现在初始化列表中的顺序。

```c++
class CMyClass {
CMyClass(int x, int y);
int m_x;
int m_y;
};

CMyClass::CMyClass(int x, int y) : m_y(y), m_x(m_y)
{
};
```

