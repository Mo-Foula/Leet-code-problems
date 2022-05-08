class Solution {
public:
    
vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
    https://leetcode.com/problems/intersection-of-two-arrays-ii/
    unordered_map<int, int> m1, m2;
    // index,frequency
    for (auto x: nums1) {
        m1[x]++;
    }
    for (auto x: nums2) {
        m2[x]++;
    }
    vector<int> intersections;
    for(auto x : nums1.size()<nums2.size()?nums1:nums2){
         intersections.insert(intersections.end(),min(m1[x],m2[x]),x);
        m1[x] = 0;
    }
    return intersections;
}
};