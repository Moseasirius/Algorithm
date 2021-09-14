//
// Created by mozhenhai on 2021/9/14.
//

#ifndef ONEQUESTIONPERDAY_MAXIMALSQUARE_H
#define ONEQUESTIONPERDAY_MAXIMALSQUARE_H

#include <iostream>
#include <vector>
using namespace std;
namespace maximalSquare{
    class Solution {
    public:
        int maximalSquare(vector<vector<char>>& matrix) {
            int rows = matrix.size();
            int columns = matrix[0].size();
            if(rows==0||columns==0){
                return 0;
            }
            int maxSide = 0;

            for(int i = 0;i<rows;i++){
                for(int j=0;j<columns;j++){
                    if(matrix[i][j] =='1'){
                        //遇到一个1作为正方形的左上角
                        maxSide = max(maxSide,1);
                        //计算可能得最大正方形
                        int currentMaxSide = min(rows-i,columns-j);
                        for(int k=1;k<currentMaxSide;k++){
                            //判断新增的一行一列是否均为1
                            bool flag = true;
                            if(matrix[i+k][j+k] =='0'){
                                break;
                            }
                            for(int m=0;m<k;m++){
                                if(matrix[i+k][j+m]=='0'||
                                   matrix[i+m][j+k]=='0'){
                                    flag = false;
                                    break;
                                }
                            }
                            if(flag){
                                maxSide = max(maxSide,k+1);
                            }else{
                                break;
                            }
                        }
                    }
                }
            }
            return  maxSide*maxSide;
        }
    };
}
void testMaximalSquare(){
    char g1[4][5] = {
            {'1','0','1','0','0'},
            {'1','0','1','1','1'},
            {'1','1','1','1','1'},
            {'1','0','0','1','0'}
    };
    vector<vector<char>> matrix;
    for(int i=0;i<4;i++){
        matrix.push_back(vector<char>(g1[i],g1[i]+sizeof (g1[i])/sizeof (char )));
    }
    cout<<maximalSquare::Solution().maximalSquare(matrix);
}
#endif //ONEQUESTIONPERDAY_MAXIMALSQUARE_H
