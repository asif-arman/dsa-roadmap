/*
Platform   : LeetCode
Problem    : 200. Number of Islands
Link       : https://leetcode.com/problems/number-of-islands/
Topic      : Graph - BFS
Difficulty : Medium
Status     : Solved
Approach   : BFS
Time       : O(m × n)
Space      : O(m × n)
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(int i, int j, vector<vector<char>>& grid,
             vector<vector<bool>>& visited) {
        queue<pair<int, int>> q;
        visited[i][j] = true;
        q.push({i, j});
        int row = grid.size();
        int col = grid[0].size();
        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};

        while (!q.empty()) {
            int nRow = q.front().first;
            int nCol = q.front().second;
            q.pop();
            for (int ii = 0; ii < 4; ii++) {
                int nr = nRow + dr[ii];
                int nc = nCol + dc[ii];
                if (nr < row and nr >= 0 and nc < col and nc >= 0 and
                    !visited[nr][nc] and grid[nr][nc] == '1') {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        int island = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (!visited[i][j] and grid[i][j] != '0') {
                    bfs(i, j, grid, visited);
                    island++;
                }
            }
        }
        return island;
    }
};