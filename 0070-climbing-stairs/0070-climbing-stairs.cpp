class Solution {
public:
    
    map <int, int> m;
    
    int climbStairs(int n) {
        if (m.find(n) != m.end()) return m[n];
        if (n == 0) return 1;
        if (n < 0) return 0;
        
        int result = climbStairs(n-1) + climbStairs(n-2);
        m[n] = result;
        return result;
    }
};