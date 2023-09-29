class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if (nums.size() == 1) return true;
        bool foundPattern = nums[0] != nums[1];
        bool isIncreasing = nums[0] < nums[1];
        for (int i = 1; i < nums.size() - 1; ++i){
            if (nums[i] == nums[i + 1]){
                continue;
            }
            if (foundPattern){
                if (nums[i] < nums[i + 1] != isIncreasing ){
                    return false;
                }
            }
            else {
                isIncreasing = nums[i] < nums[i + 1];
                foundPattern = true;
            }
                
        }
        return true;
    }
};