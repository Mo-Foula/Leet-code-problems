class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int fast = nums[0];
        int slow = nums[0];
        
        do{
            fast = nums[nums[fast]];
            slow = nums[slow];
        }while(fast != slow);
        
        fast = nums[0];
        
        while(fast != slow)
        {
            fast = nums[fast];
            slow = nums[slow];
        }
        
        return slow;
        
    }
    /*int findDuplicate(vector<int>& nums) {
        int n = nums.size() - 1;
        long long prod = 1;
        for (int i = 2; i <= n; ++i){
            prod *= i;
        }
        int i = 0;
        while (i < nums.size() && !(prod % nums[i])){
            prod /= nums[i];
            ++i;
        }
        return i == nums.size()? 1 : nums[i];
    }*/
};

/*
factorial 4 = 24
// 1 2 4 4 4
24 / 2 = 12
12 / 4 = 3
3 / 4 X 


24 / 3 = 8
8 / 2 = 4
4 / 2 = 2
2 / 2 = 1
1 / 4 = nope

2 3 2 4 2
*/


/*
long long sum = 0, n = nums.size();
for (int i = 0; i < n; ++i){
    sum += nums[i];
}
int ans = sum - (n * (n-1) / 2);
return ans?ans:nums[0];
*/

// [2,5,9,6,9,3,8,9,7,1]
//  0 1 2 3 4 5 6 7 8 9

/*
    slow: 2 9 1
    fast: 3 8 1 
*/