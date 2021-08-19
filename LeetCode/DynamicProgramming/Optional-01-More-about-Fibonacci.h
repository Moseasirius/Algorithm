//
// Created by mozhenhai on 2021/8/15.
//

#ifndef DYNAMICPROGRAMMING_OPTIONAL_01_MORE_ABOUT_FIBONACCI_H
#define DYNAMICPROGRAMMING_OPTIONAL_01_MORE_ABOUT_FIBONACCI_H

/// 70. Climbing Stairs
/// https://leetcode.com/problems/climbing-stairs/description/
///
/// 在这一章的学习中, 我们看到了, 70号问题本质就是求斐波那契数
/// 只不过 climbStairs(n) 的答案, 对应第 n+1 个斐波那契数
/// 其中 f0 = 0, f(1) = 1, f(2) = 1, f(3) = 2...
/// 首先, 我们可以非常简单的使用O(1)的空间求出斐波那契数
/// 这个对空间的优化和我们在这个课程中所介绍的背包问题的空间优化, 其实是类似的思想
/// 我们对背包问题的空间优化, 从O(n^2)优化到了O(n)
/// 我们对斐波那契问题的优化,可以从O(n)优化到O(1)
/// 依靠的依然是, 求第n个斐波那契数, 我们只需要n-1和n-2两个斐波那契数,
/// 更小的斐波那契数不需要一直保存。
///
/// 时间复杂度: O(n)
/// 空间复杂度: O(1)

/// 70. Climbing Stairs
/// https://leetcode.com/problems/climbing-stairs/description/
///
/// 斐波那契数可以根据一个特殊矩阵的幂的形式求出。
/// | F(n+1) F(n)   | = | 1 1 |^n
/// | F(n)   F(n-1) |   | 1 0 |
/// 幂运算可以使用分治法, 优化为O(logn)的复杂度
/// 具体该方法的证明, 有兴趣的同学可以自行在互联网上搜索学习。
///
/// 时间复杂度: O(logn)
/// 空间复杂度: O(1)

/// 70. Climbing Stairs
/// https://leetcode.com/problems/climbing-stairs/description/
///
/// 对于第n个斐波那契数, 可以推导出其公式
/// Fn = 1/sqrt(5) * {[(1+sqrt(5))/2]^n - [(1-sqrt(5))/2]^n}
/// 具体推导过程, 有兴趣的同学可以自行在互联网上搜索学习。
/// 注意: 这个方法的时间复杂度依然是O(logn)的,因为数的幂运算也需要logn的时间
/// 但这个方法快于使用矩阵的幂运算符的方法
///
/// 时间复杂度: O(logn)
/// 空间复杂度: O(1)
#endif //DYNAMICPROGRAMMING_OPTIONAL_01_MORE_ABOUT_FIBONACCI_H
