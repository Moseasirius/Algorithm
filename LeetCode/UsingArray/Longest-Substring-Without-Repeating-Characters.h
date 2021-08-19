//
// Created by mozhenhai on 2021/8/8.
//

#ifndef USINGARRAY_LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS_H
#define USINGARRAY_LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS_H

// 3. Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
//
// 滑动窗口
// 时间复杂度: O(len(s))
// 空间复杂度: O(len(charset))
namespace LongestSubstringWithoutRepeatingCharacters1{
    class Solution {
    public:
        int lengthOfLongestSubstring(string s) {

            int freq[256]={0};
            int l = 0,r =-1;
            int res = 0;
            while(l<s.size()){

                if(r+1<s.size()&&freq[s[r+1]]==0){
                    freq[s[++r]]++;
                }
                else{
                    freq[s[l++]]--;
                }
                res = max(res,r-l+1);
            }
            return res;

        }
    };

}

// 3. Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
//
// 滑动窗口
// 时间复杂度: O(len(s))
// 空间复杂度: O(len(charset))

// 3. Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
//
// 滑动窗口的另一个实现, 仅做参考
// 时间复杂度: O(len(s))
// 空间复杂度: O(len(charset))

// 3. Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
//
// 课程问答区 @yatkun 提出的方法,
// l每次可以向前跳跃, 而不仅仅是+1
// 但代价是, 为了获得这个跳跃的位置, 每次需要遍历整个窗口的字符串
//
// 时间复杂度: O(len(s)*len(charset))
// 空间复杂度: O(1)

// 3. Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
//
// 滑动窗口
// 其中使用last[c]保存字符c上一次出现的位置, 用于在右边界发现重复字符时, 快速移动左边界
// 使用这种方法, 时间复杂度依然为O(n), 但是只需要动r指针, 实际上对整个s只遍历了一次
// 相较而言, 之前的方法, 需要移动l和r两个指针, 相对于对s遍历了两次
//
// 时间复杂度: O(len(s))
// 空间复杂度: O(len(charset))


#endif //USINGARRAY_LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS_H
