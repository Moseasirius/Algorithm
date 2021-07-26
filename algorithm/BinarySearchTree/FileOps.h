//
// Created by mo on 2021/7/26.
//

#ifndef BINARYSEARCHTREE_FILEOPS_H
#define BINARYSEARCHTREE_FILEOPS_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
// 文件相关操作
namespace FileOps{
    int firstCharacterIndex(const string& s,int start){
        for(int i = start ; i < s.length() ; i++)
            if(isalpha(s[i]))
                return i;
        return s.length();
    }
    // 将字符串s中的所有字母转换成小写之后返回




}
#endif //BINARYSEARCHTREE_FILEOPS_H
