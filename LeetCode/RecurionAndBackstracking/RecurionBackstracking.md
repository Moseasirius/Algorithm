# 递归和回溯法

## 什么是递归

## 什么是回溯

回溯法是暴力解法的一个主要实现手段 效率



## 为什么要使用回溯法

我们遇到很多问题，如果想要枚举其所有的解的话，如果不能使用简单的循环遍历的话，就需要使用回溯法。

有的问题可以使用多重循环，如果不能使用多重循环，就要考虑一下回溯法。



## 回溯算法的应用

## 排列问题

## 全排列

```
/// 46. Permutations
/// https://leetcode.com/problems/permutations/description/
/// 时间复杂度: O(n^n)
/// 空间复杂度: O(n)
```

```c++
class Solution {

    private:
        vector<vector<int>> res;
        vector<bool> used;

        //int index 表示现在正在处理第几个元素 vector<int>& p 表示找到的一个排列
        //p中保存了一个有index个元素的排列
        //向这个排列的末尾添加第index+1 个元素，获得一个有index+1个元素的排列
        void generatePermutations(const vector<int> &nums, int index, vector<int> &p) {

            if (index == nums.size()) {

                // for (int i:p)
                //     cout << i << " ";
                // cout << endl;

                res.push_back(p);
                return;
            }
            for (int i = 0; i < nums.size(); i++) {
                if (!used[i]) {


                    p.push_back(nums[i]);

                    // cout << "push_back:  " << nums[i] << endl;
                    used[i] = true;
                    generatePermutations(nums, index + 1, p);

                    // cout << "pop.back:  " << p.back() << endl;
                    p.pop_back();
                    used[i] = false;
                }
            }
            return;
        }

    public:
        vector<vector<int>> permute(vector<int> &nums) {
            res.clear();
            if (nums.size() == 0)
                return res;
            used = vector<bool>(nums.size(), false);
            vector<int> p;
            generatePermutations(nums, 0, p);

            return res;
        }

    };
```







## 递归和回溯的区别

### 波波老师的回答：

递归只是一种程序逻辑建立的机制：自己调用自己。和循环的概念类似，是一种组成逻辑的方式。

回溯是一种算法思想，本质其实是在树形的结构中进行“穷举”。二叉树的遍历是最好的解释回溯的方式：

```
     1
   /   \
  2     3 
 / \   /  \
4   5 6    7
```

比如上面的二叉树，我们做前序遍历，先遍历了1->2->4这个路径，之后为了遍历其他的可能，我们要从4“回到”2，之后遍历5；然后我们再“回到”2，发现在2上也没有其他路径了，又“回到”1，然后去3继续遍历。可以看到，回溯的关键是“回来”继续寻找其他的可能。

我要没记错，在这一章讲回溯的时候，应该每一个问题我都相应的画了一棵回溯树，来展示对于每一个问题，寻找解的过程是怎样的。

但递归不是一种算法思想，所以我们通常说这个问题可以使用回溯法解决，具体实现可以使用递归实现。

可以回忆一下在二叉搜索树中插入节点，或者删除节点，我们可以使用递归实现，但这个过程不是在树中进行“穷举”，通常不叫回溯法。再比如，为链表插入一个节点，删除一个节点，翻转链表，这些任务都可以使用递归实现，但通常不叫“回溯”，因为不是在一个树形结构中做搜索。

更复杂一些，在后面讲解动态规划的时候，对于每一个问题，我都会讲解一个“记忆化搜索”的解法，这种解法和回溯很像，但并没有穷举整棵递归树，所以通常也不叫“回溯”。

不过，其实，对于这种概念，通常也不用较真。比如在面试时，你说：我使用回溯法，加上了记忆化的策略，具体是如何balabalabla... 大家也能听懂你的意思，不会有人较真，问你，到底什么是回溯？你这样做真的叫回溯吗？等等等等。我还没听说过有人因为不能明确阐释“回溯”的概念而被拒。懂不懂回溯，随便拿一个“经典”回溯问题问一下便知：）

所以，如果要想深入理解这个概念，如果基于这个课程的话，我的建议是：把七八九三章看完，将其中的例题和练习题都自己亲自实践一遍，然后再回过头用自己的感悟总结一下：什么是回溯，什么动态规划，什么是递归实现。到那时，相信你会有更多的体会：）

## N-Queens

解决N皇后问题

先尝试在第一行怎么摆放，在尝试第二行怎么摆放……

考虑冲突的地方，相当于回溯的剪枝

快速判断不合法的情况

竖向：col[i] 表示第i列被占用

对角线1：dia1[i] 表示第i对角线1被占用

对角线2：dia2[i] 表示第i对角线2被占用

如何使用一个数组表示两个方向的对角线

|      |      |      |      |
| ---- | ---- | ---- | ---- |
| 0 0  | 0 1  | 0 2  | 0 3  |
| 1 0  | 1 1  | 1 2  | 1 3  |
| 2 0  | 2 1  | 2 2  | 2 3  |
| 3 0  | 3 1  | 3 2  | 3 3  |

一三象限  左下到右上的对角线1 

2*n-1 个 

同一对角线上i+j的值相等  i+j

二四象限  左上到右下的对角线2

2*n-1个

同一对角线上i-j的值相等 i-j, 对于数组我们希望数组下标从零开始  i-j+n-1

```c++
namespace Queens {
    class Solution {
    private:
        vector<vector<string>> res;
        vector<bool> col;
        vector<bool> dia1;
        vector<bool> dia2;

        void putQueen(int n, int index, vector<int> &row) {
            //递归到底 得到一个解
            if (index == n) {
                res.push_back(generateBoard(n, row));
                return;
            }
            for (int i = 0; i < n; i++) {
                // 尝试将第index行的皇后摆放在第i列
                if (!col[i] && !dia1[index + i] && !dia2[index - i + n - 1]) {
                    row.push_back(i);
                    col[i] = true;
                    dia1[index + i] = true;
                    dia2[index - i + n - 1] = true;
                    putQueen(n, index + 1, row);
                    col[i] = false;
                    dia1[index + i] = false;
                    dia2[index - i + n - 1] = false;
                    row.pop_back();

                }
            }
            return;
        }

        vector<string> generateBoard(int n, vector<int> &row) {
            assert(row.size() == n);
            vector<string> board(n, string(n, '.'));
            for (int i = 0; i < n; i++) {
                board[i][row[i]] = 'Q';
            }
            return board;
        }

    public:
        vector<vector<string>> solveNQueens(int n) {
            res.clear();
            col.clear();

            col = vector<bool>(n, false);
            dia1 = vector<bool>(2 * n + 1, false);
            dia2 = vector<bool>(2 * n + 1, false);

            vector<int> row;
            putQueen(n, 0, row);
            return res;
        }
    };
}

void testNQueens() {
    int n = 4;
    vector<vector<string>> res = Queens::Solution().solveNQueens(n);
    cout << res.size() << " Queens " << endl;
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < n; j++)
            cout << res[i][j] << endl;
        cout << endl;
    }
}

```

