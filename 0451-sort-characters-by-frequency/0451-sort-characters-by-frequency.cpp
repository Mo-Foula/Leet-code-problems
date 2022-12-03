class Solution {
public:
    string frequencySort(string s) {
        map<char,int> m;
        for(auto c : s){
            m[c]++;
        }
        
        vector<pair<int,char>> vec;
        
        for(auto x : m){
            vec.push_back({x.second,x.first});
        }
        
        sort(vec.begin(),vec.end(),greater<pair<int,char>>());
//    reverse(vec.begin(),vec.end());
        
        string output = "";
        
        for(auto x : vec){
            output.append(x.first,x.second);
        }
        return output;
    }
};