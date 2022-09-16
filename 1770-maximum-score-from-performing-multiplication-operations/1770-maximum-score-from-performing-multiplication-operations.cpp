class Solution {
public:
  int maximumScore(vector<int>& nums, vector<int>& multipliers) {
    const int m = multipliers.size();
    const int n = nums.size();
    // dp[i][j] := max score of using first i elements and last j elements
    vector<vector<int>> dp(m + 1, vector<int>(m + 1));
    for (int k = 1; k <= m; ++k)
      for (int i = 0, j = k - i; i <= k; ++i, --j)
        dp[i][j] = max((i ? dp[i - 1][j] + nums[i - 1] * multipliers[k - 1] : INT_MIN),
                       (j ? dp[i][j - 1] + nums[n - j] * multipliers[k - 1] : INT_MIN));
    int ans = INT_MIN;
    for (int i = 0; i <= m; ++i)
      ans = max(ans, dp[i][m - i]);
    return ans;
  }
};
