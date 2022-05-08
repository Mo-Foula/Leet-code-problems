class Solution {
public:

bool isBipartite(vector<vector<int>>& graph) {
    map<int,bool> m;
    map<int,bool> first,second;
    queue<pair<int,bool>> q;
    map<int,bool> visited2 ;
    for (int j = 0; j <graph.size() ; ++j) {
        if(!visited2[j])
            q.push({j,true});
        while(!q.empty()){
        if(visited2[q.front().first]){
            q.pop();
            continue;
        }
        auto i = graph[q.front().first];
        visited2[q.front().first] = true;
        for(auto x : i){
            q.push({x,!q.front().second});
            if(q.front().second){
                if(second[x])
                    return false;
                first[x] = true;
            }else{
                if(first[x])
                    return false;
                second[x] = true;
            }
        }

        q.pop();
    }}
    return true;
}
};