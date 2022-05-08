class Solution {
public:
    int minCost(string s, vector<int>& cost) {
    
    int j;
    int sum,total=0;int maxi;
    for (int i = 1; i <s.length() ; ) {
        if(s[i] == s[i-1]){
            j = i;
            sum = cost[j-1];
            maxi = cost[j-1];
            while (j<s.length() && s[j] == s[j-1]){
                sum+=cost[j];
                maxi = max(maxi,cost[j]);
                 j++;
            }
            sum-=maxi;
            total+=sum;
            i=j;
        }else{
            i++;
        }
    }
    return total;
}
};