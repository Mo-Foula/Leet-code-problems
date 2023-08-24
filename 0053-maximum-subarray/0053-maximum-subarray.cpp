class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    long long mx = LONG_LONG_MIN;
    long long sum = 0;
    for (auto it = nums.begin(); it != nums.end(); ++it ) {
        if (sum + *it >= *it && sum + *it > 0) {
            sum += *it;
        } else {
            sum = *it;
        }
        mx = max(sum, mx);
    }
    return mx;
}
};