

class Solution {
public:
     
   
    
    
    int concatenatedBinary(int n) {
        
        long long ans = 1, len = 4;
        
        for (int i = 2; i <= n; i++) {
            if (i == len) len *= 2;
                ans = (ans * len + i) % 1000000007;
        }
        return ans;
    }
};