class Solution {
public:
    
vector<bool> visited;
vector<vector<int>> graph;
priority_queue<int, vector<int>, greater<>> pq_nodes;
priority_queue<char, vector<char>, greater<>> pq_chars;
string k;

bool check_custom_leaf(int l) {
    for (int i : graph[l]) {
        if (i < l)
            return false;
    }
    return true;
}

void dfs(int n) {
    if (visited[n]) return;
    visited[n] = true;
    pq_nodes.push(n);
    pq_chars.push(k[n]);
    for (int i : graph[n]) {
        dfs(i);
    }
}

void _switch(){
    if(!pq_nodes.empty()){
        while(!pq_nodes.empty()){
            k[pq_nodes.top()] = pq_chars.top();
            pq_chars.pop();
            pq_nodes.pop();
        }
    }
}

string smallestStringWithSwaps(string s, vector<vector<int>> &pairs) {
    graph.resize(s.size());
    visited.resize(s.size());
    k = s;
    for (auto x : pairs) {
        graph[x[1]].push_back(x[0]);
        graph[x[0]].push_back(x[1]);
    }
    for (int i = 0; i <s.size() ; ++i) {
        dfs(i);
        _switch();
    }
    return k;
}
};