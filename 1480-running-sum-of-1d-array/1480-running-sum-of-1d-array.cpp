class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> vec(nums.size());
        vec[0] = nums[0];
        for(int i = 1; i<nums.size(); i++){
            vec[i] = vec[i-1] + nums[i];
        }
        return vec;
    }
};