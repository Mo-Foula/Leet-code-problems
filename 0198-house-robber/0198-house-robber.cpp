class Solution {
public:
    
    map<int, int> m;
    
    int rob_R(vector<int>& nums, int i) {
        if (m.find(i) != m.end()) return m[i];
        if (i >= nums.size()) return 0;
        
        int ifTaken = nums[i] + rob_R(nums, i+2);
        int ifSkipped = rob_R(nums, i+1);
        
        int result = max(ifTaken, ifSkipped);
        m[i] = result;
        return result;
    }
    
    int rob(vector<int>& nums) {
        return rob_R(nums,0);
    }
};