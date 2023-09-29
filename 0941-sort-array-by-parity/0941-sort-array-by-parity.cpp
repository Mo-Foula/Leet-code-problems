class Solution {
public:
    // bool comp (int a, int b){
    //     int aOdd = a&1;
    //     int bOdd = b&1;
    //     return aOdd == bOdd? a > b: aOdd < bOdd;
    // }
    vector<int> sortArrayByParity(vector<int>& nums) {
        function < bool (int, int) > comp = [](const int& a,const  int& b){
            int aOdd = a&1;
            int bOdd = b&1;
            return aOdd == bOdd? a > b: aOdd < bOdd;
        };
        sort(nums.begin(), nums.end(), comp);
        return nums;
    }
};