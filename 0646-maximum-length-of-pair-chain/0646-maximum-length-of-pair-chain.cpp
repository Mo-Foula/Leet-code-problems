class Solution {
public:
    
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end()); 
        
        map<int,int> cache;
        
        for (int i = pairs.size() - 1; i >= 0; --i){
            if (i > 0 && pairs[i][0] == pairs[i-1][0]) continue;
            
            int result = 0;
            
            auto it = cache.upper_bound(pairs[i][1]);
            if (it == cache.end()){
                result = 1;
            } else {
                result = 1 + (*it).second;
            }
            
            cache[pairs[i][0]] = max (result, (i != pairs.size() - 1)? (*cache.upper_bound(pairs[i][0])).second: 0);
        }
        return (*cache.begin()).second;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
//     // [[1,2],[2,3],[3,4]]
    
//     //  index result
//     map <pair<int,int>, int> m;
    
//     int findLongestChain_R(vector<vector<int>>& pairs, int i, int previousB) {
//         if (m.find({i, previousB}) != m.end()) return m[{i, previousB}];
//         if (i >= pairs.size()) return 0;
        
//         int ifTaken = 0, ifSkipped = 0;
        
//         if (pairs[i][0] > previousB){
//             // Could be taken
//             ifTaken = 1 + findLongestChain_R(pairs, i+1, max(pairs[i][1], previousB));
//         }
            
        
//         ifSkipped = findLongestChain_R(pairs, i+1, previousB);
        
//         int result = max(ifTaken, ifSkipped);
//         m[{i, previousB}] = result;
//         return result;
//     }
    
    
    // int findLongestChain(vector<vector<int>>& pairs) {
    //     sort(pairs.begin(), pairs.end());
    //     return findLongestChain_R(pairs, 0, -2000);
    // }
};