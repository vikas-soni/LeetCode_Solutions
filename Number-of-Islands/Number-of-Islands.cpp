#include<vector>
#include<utility>
class Solution {
public:
    int row_len=0;
    int col_len=0;
    std::vector<std::pair<int,int>> offsets;
    int numIslands(vector<vector<char>>& grid) 
    {
        row_len=grid.size();
        if(row_len==0)
            return 0;
        col_len=grid[0].size();
        if(col_len==0)
            return 0;
        int num_islands=0;
        offsets.emplace_back(0,-1);
        offsets.emplace_back(0,1);
        offsets.emplace_back(-1,0);
        offsets.emplace_back(1,0);
        // we will do a dfs for each non-visited 1. total number of dfs invoked from here will give us
        // total number of islands
        // so lets create a 2d array of bool and set it to false
        vector<vector<bool>> visited(row_len,(vector<bool>(col_len,false)));
        for(int row=0;row<row_len;++row)
        {
            for(int col=0;col<col_len;++col)
            {
                if((grid[row][col]=='1') && (!visited[row][col]))
                {
                    ++num_islands;
                    dfs_islands(grid,visited,row,col);
                }
            }
        }
        return num_islands;
    }
    void dfs_islands(vector<vector<char>>& grid, vector<vector<bool>> &visited,int row, int col)
    {
        // visit the node
        visited[row][col]=true;
        // visit all the connected neighbors
        for(auto offset:offsets)
        {
            if((row+offset.first<0)||(row+offset.first>=row_len)
            ||(col+offset.second<0)||(col+offset.second>=col_len))
                    continue;
                    
            if((grid[row+offset.first][col+offset.second]=='1')
                && (!visited[row+offset.first][col+offset.second]))
            {
                // visit
                dfs_islands(grid,visited,row+offset.first,col+offset.second);
            }
        }
    }
};