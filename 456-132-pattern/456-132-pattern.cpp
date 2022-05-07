class Solution {
public:

bool find132pattern(vector<int>& nums) {
    //https://leetcode.com/problems/132-pattern/
    int n = nums.size();
    vector<int> minimum(nums.size());
    int mn = nums[0];
    for(int i = 0; i<nums.size(); i++){
        mn = min(nums[i],mn);
        minimum[i] = mn;
    }
    stack<int> stk;
    int top;
    for (int i = nums.size()-1; i >=0 ; --i) {
        if(minimum[i] < nums[i]){
            while(!stk.empty() && stk.top() <= minimum[i]){
                stk.pop();
            }
            if(!stk.empty() && nums[i] > stk.top() && minimum[i] < stk.top())
                return true;
        }
        stk.push(nums[i]);
    }
    return false;
}


};