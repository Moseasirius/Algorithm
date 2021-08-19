//
// Created by mozhenhai on 2021/8/15.
//

#ifndef RECURIONANDBACKSTRACKING_LETTER_COMBINATIONS_OF_A_PHONE_NUMBER_H
#define RECURIONANDBACKSTRACKING_LETTER_COMBINATIONS_OF_A_PHONE_NUMBER_H


/// 17. Letter Combinations of a Phone Number
/// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
/// 时间复杂度: O(2^len(s))
/// 空间复杂度: O(len(s))
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

//树形问题 递归
//递归调用的一个重要特征 要返回 回溯 。回溯法是暴利解法的一个主要实现手段
//效率低 但是数据规模小可以
namespace LetterCombinationsOfAPhoneNumber{
    class Solution {

    private:
        const string letterMap[10]{
                " ",//0;
                "",//1
                "abc",//2
                "def",//3
                "ghi",//4
                "jkl",//5
                "mno",//6
                "pqrs",//7
                "tuv",//8
                "wxyz"//9
        };
        vector<string> res;
        void findCombination(const string &digits,int index,const string &s){
            cout<<index<<" : "<<s<<endl;
            if(index == digits.size()){
                //保存s
                res.push_back(s);
                cout<<"get "<<s<<" , return"<<endl;
                return ;
            }
            char c = digits[index];
            assert(c>='0'&&c<='9'&&c!='1');
            string letters = letterMap[c-'0'];
            for(int i=0;i<letters.size();i++){
                cout<<"digits["<<index<<"] = "<<c<<" ,use  "<<letters[i]<<endl;
                findCombination(digits,index+1,s+letters[i]);
            }
            cout<<"digits["<<index<<"] = "<<c<<" complete ,return"<<endl;
            return;

        }
    public:
        vector<string> letterCombinations(string digits) {

            res.clear();

            if(digits=="")
                return res;

            findCombination(digits,0,"");
            return res;

        }
    };
}
void  LetterCombinationsOfAPhoneNumberTest(){
    vector<string> res = LetterCombinationsOfAPhoneNumber::Solution().letterCombinations("234");
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<endl;
    }
}
#endif //RECURIONANDBACKSTRACKING_LETTER_COMBINATIONS_OF_A_PHONE_NUMBER_H
