class Solution {
public:
 
bool exploreNode(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x,int y){
    if(x < 0 || y < 0 || x == grid.size() || y == grid[x].size() || visited[x][y]){
        return true;
    }
    visited[x][y] = true;
    if(grid[x][y] == '1'){
        // explore
        exploreNode(grid,visited, x-1,y); exploreNode(grid,visited, x,y-1);

        exploreNode(grid,visited, x+1,y); exploreNode(grid,visited, x,y+1);
    }
    return true;

}

int numIslands(vector<vector<char>>& grid) {
    int count = 0;
    vector<vector<bool>> visited(grid.size(), vector<bool> (grid[0].size(),0));
    for (int i = 0; i <grid.size() ; ++i) {
        for (int j = 0; j <grid[i].size(); ++j) {
            if(!visited[i][j] && grid[i][j] == '1') count += exploreNode(grid, visited,i,j);
        }
    }
    return count;
}

};