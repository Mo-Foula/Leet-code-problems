class Solution {
public:
    
vector<int> sortArrayByParity(vector<int>& nums) {
    vector<int> even,odd;
    for (int i : nums) {
        (i&1) == 0?even.push_back(i):odd.push_back(i);
    }
    even.insert(even.end(),odd.begin(),odd.end());
    return even;
}

};