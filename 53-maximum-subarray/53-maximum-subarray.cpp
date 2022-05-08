class Solution {
public:
    int maxSubArray(vector<int>& nums) {
  priority_queue<double> pq;
    int mx = INT_MIN;
    double sum = 0;
    for(auto x : nums){
        mx = max(x,mx);
        if(sum == 0 && x < 0)
            continue;
        if(sum > sum + x){
            // found a negative number
            pq.push(sum);
            sum+=x;
            if(sum <= 0){
                sum = 0;
            }
        }else{
            sum+=x;
        }
    }
    pq.push(sum);
    if(mx <= 0)
        return mx;
    return pq.top();
    }
};