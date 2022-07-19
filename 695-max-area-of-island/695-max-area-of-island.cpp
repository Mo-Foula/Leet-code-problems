class Solution {
public:
 
vector<pair<int, int>> moves = {{1,  0},
                                {0,  1},
                                {-1, 0},
                                {0,  -1}};
map<pair<int, int>, bool> visited2;

int myRecursion(vector<vector<int>> &grid, int x, int y) {
    if (visited2[{x, y}] || x >= grid.size() || y >= grid[x].size() || x < 0 || y < 0 || !grid[x][y]) return 0;
    visited2[{x, y}] = true;
    // There's island
    int count = 0;
    for (auto move: moves) {
        count += myRecursion(grid, x + move.first, y + move.second);
    }
    return count + 1;
}

int maxAreaOfIsland(vector<vector<int>> &grid) {
    int mx = 0;
    for (int x = 0; x < grid.size(); ++x) {
        for (int y = 0; y < grid[x].size(); ++y) {
            if(!visited2[{x,y}])
                mx = max(myRecursion(grid, x, y), mx);
        }
    }
    return mx;
}

};