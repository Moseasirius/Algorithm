//
// Created by mozhenhai on 2021/8/15.
//

#ifndef RECURIONANDBACKSTRACKING_NUMBER_OF_ISLANDS_H
#define RECURIONANDBACKSTRACKING_NUMBER_OF_ISLANDS_H

/// 200. Number of Islands
/// https://leetcode.com/problems/number-of-islands/description/
/// 时间复杂度: O(n*m)
/// 空间复杂度: O(n*m)
#include <iostream>
#include <vector>

namespace numberOfIslands{
    class Solution {
    private:
        int d[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        vector<vector<bool>> visited;
        int m,n;
        bool isArea(int x,int y){
            return x>=0&&x<m && y>=0&&y<n;
        }
        // 从grid[x][y]的位置开始,进行FloodFill
        // 保证(x,y)合法,且grid[x][y]是没有被访问过的陆地
        void dfs(vector<vector<char>>& grid,int x,int y){

            visited[x][y] = true;
            for(int i=0;i<4;i++){

                int newx = x +d[i][0];
                int newy = y+ d[i][1];
                if(isArea(newx,newy)&&!visited[newx][newy]&&grid[newx][newy]=='1'){
                    dfs(grid,newx,newy);
                }

            }
            return;
        }

    public:
        int numIslands(vector<vector<char>>& grid) {

            m =grid.size();
            if(m==0)
                return 0;

            n= grid[0].size();
            if(n==0)
                return 0;
            visited = vector<vector<bool>>(m,vector<bool>(n,false));
            // for(int i = 0 ; i < m ; i ++)
            // visited.push_back(vector<bool>(n, false));

            int res = 0;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j]=='1'&&!visited[i][j]){
                        dfs(grid,i,j);
                        res++;
                    }
                }
            }
            return res;



        }
    };
}
void testNumberOfIsland(){
    char g1[4][5]={
            {'1','1','1','1','0'},
            {'1','1','0','1','0'},
            {'1','1','0','0','0'},
            {'0','0','0','0','0'}

    };
    vector<vector<char >> grid1;
    for(int i=0;i<4;i++){
        grid1.push_back(vector<char>(g1[i],g1[i]+sizeof (g1[i])/sizeof (char )));
    }
    cout<<numberOfIslands::Solution().numIslands(grid1)<<endl;
    // 1

    // ---
    char g2[4][5] = {
            {'1','1','0','0','0'},
            {'1','1','0','0','0'},
            {'0','0','1','0','0'},
            {'0','0','0','1','1'}
    };
    vector<vector<char>> grid2;
    for(int i = 0 ; i < 4 ; i ++)
        grid2.push_back(vector<char>(g2[i], g2[i] + sizeof( g2[i])/sizeof(char)));

    cout << numberOfIslands::Solution().numIslands(grid2) << endl;
    // 2


}
#endif //RECURIONANDBACKSTRACKING_NUMBER_OF_ISLANDS_H
