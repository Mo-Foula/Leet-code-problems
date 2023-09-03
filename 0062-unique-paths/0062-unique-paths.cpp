class Solution {
public:
    
    int uniquePaths(int m, int n) {
    
        vector<vector<int>> memo (101, vector<int>(101, 0));
        
        function <int(int, int)> dp = [&](int x, int y){
            if (x >= m || y >= n) return 0;
            if (x == m - 1 && y == n - 1) return 1;
            if (memo[x][y]) return memo[x][y];
            
            int right = dp(x+1, y);
            int down = dp(x,y+1);
            
            return memo[x][y] = right + down;
        };
        int result = dp(0, 0);
        memo = vector(101, vector<int>(101, 0));
        return result;
    }
};