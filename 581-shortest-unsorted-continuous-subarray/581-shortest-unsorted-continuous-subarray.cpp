class Solution {
public:
   
int findUnsortedSubarray(vector<int>& nums) {
    priority_queue<int, vector<int> , greater<> > pq_asc;
    priority_queue<int> pq_desc;
    for(int number : nums){
        pq_asc.push(number);
        pq_desc.push(number);
    }
    int start_of_subarray = 0,end_of_subarray = nums.size()-1,i = 0;

    for (i = 0; i <nums.size() ; ++i) {
        if(nums[i] == pq_asc.top()){
            pq_asc.pop();
        }else{
            break;
        }
    }
    start_of_subarray = i;
    if(pq_asc.empty())
        return 0;
    for (i = nums.size()-1; i >=0 ; --i) {
        if(nums[i] == pq_desc.top()){
            pq_desc.pop();
        }else{
            break;
        }
    }
    end_of_subarray = i;
    return end_of_subarray - start_of_subarray+1;

}

};