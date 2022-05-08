class Solution {
public:

int maxOperations(vector<int>& nums, int k) {
//https://leetcode.com/problems/max-number-of-k-sum-pairs/
    map<int  ,  int> m;
    unordered_set<int> s;
    // number frequency
    for(int x : nums){
        m[x]++;
        s.insert(x);
    }
    int maxOperations = 0;
    for(double x : s){
        if(x == k/2.0){
            maxOperations += m[x]/2;
        }
        else {
            auto i = min(m[x],m[k-x]);
            maxOperations += i;
        }
            m[x] = 0;
    }
    return maxOperations;
}
};