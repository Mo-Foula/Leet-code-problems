class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
     vector<int> retur;

    int minus;
    for (int i = 0; i <nums.size() ; ++i) {
        minus = target - nums[i];
        auto x = find(nums.begin()+i+1,nums.end(),minus);
        if(x != nums.end()){
            retur.push_back(i);
            retur.push_back(x-nums.begin());
            return retur;
        }
    }
    return retur;
        }
};