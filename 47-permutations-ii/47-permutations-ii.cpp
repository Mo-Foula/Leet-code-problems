class Solution {
public:

vector<vector<int>> ret;
vector<int> nums2;
map<int,bool> visited;
void recursionPermuteUnique(vector<int> v){
    if(v.size() == nums2.size()){
        ret.push_back(v);
        return;
    }
    int last = -11;
    map<int,bool> localvisited;
    for (int i = 0; i <nums2.size() ; ++i) {
        if(nums2[i] == last || visited[i] || localvisited[nums2[i]])
            continue;
        last = nums2[i];
        localvisited[nums2[i]] = true;
        v.push_back(nums2[i]);
        visited[i] = true;
        recursionPermuteUnique(v);
        visited[i] = false;
        v.pop_back();
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    nums2 = nums;
    vector<int> em;
    recursionPermuteUnique(em);
    return ret;
}

};