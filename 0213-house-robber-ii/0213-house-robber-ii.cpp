class Solution {
public:

    map<pair<int, int>, int> m;
    // 1 3 1 3 100
    
    int rob_R(vector<int>& nums, int i, bool tookFirst) {
        if (m.find({i, tookFirst}) != m.end()) return m[{i, tookFirst}];
        if (i >= nums.size() || ((i == nums.size() - 1) && tookFirst)) return 0;
        
        int ifTaken = nums[i] + rob_R(nums, i+2, tookFirst || i == 0);
        int ifSkipped = rob_R(nums, i+1, tookFirst);
        
        int result = max(ifTaken, ifSkipped);
        m[{i, tookFirst}] = result;
        return result;
    }
    
    int rob(vector<int>& nums) {
     return rob_R(nums, 0, false);
    }
};