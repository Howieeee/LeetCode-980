class Solution {
public:
    int path = 0;

    void DFS(vector<vector<int>>& grid, int x, int y, int has_visited){
        int m = grid.size() , n = grid[0].size();
        if( x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == -1)
            return;
        if(grid[x][y] == -1)//不能走
            return;
       
        if(grid[x][y] == 2 ){
            if(has_visited == can_visited)
                path++;
            return;
        }
        
        grid[x][y] = -1; //走過的就放顆石頭
        
        //上下左右走看看
        DFS(grid,x-1,y,has_visited+1);
        DFS(grid,x+1,y,has_visited+1);
        DFS(grid,x,y-1,has_visited+1);
        DFS(grid,x,y+1,has_visited+1);
        
        grid[x][y] = 0; //如果沒走完就把石頭拿起來
        
    }
    
    int can_visited = 1;
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size();
        int start_x, start_y;
        for(int i=0;i< m ;i++){
            for(int j=0;j< n;j++){
                if(grid[i][j] == 1){//start position
                    start_x = i;
                    start_y = j;
                }
                else if(grid[i][j] == 0){//可以走的
                    can_visited ++;
                }
            }
        }
        
        DFS(grid,start_x,start_y,0);
        
        
        return path;
    }
};
