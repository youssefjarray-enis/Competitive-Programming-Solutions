class Solution {
private :
 void dfs(vector<vector<int>>& grid, int i, int j,int &nb) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != 1)return;
        nb++; 
        grid[i][j] = 0;
        dfs(grid, i + 1, j,nb);
        dfs(grid, i - 1, j,nb);
        dfs(grid, i, j + 1,nb);
        dfs(grid, i, j - 1,nb);
    } 
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();int nb=0 ;int maxArea=0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 1) {
                    int nb=0; 
                    dfs (grid ,i, j,nb);
                    maxArea=max (nb,maxArea); 
                    
                }
         return maxArea;    
    }
};