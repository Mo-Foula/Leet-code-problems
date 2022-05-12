class Solution {
public:
int minCostConnectPoints(vector<vector<int>> &points) {
//    Graph g(points.size());
    vector<vector<int> > myGraph(points.size(), vector<int> (points.size()));
    int val;
    for (int i = 0; i < points.size(); ++i) {
        for (int j = i + 1; j < points.size(); ++j) {
            val = abs((points[i][0] - points[j][0])) + abs((points[i][1] - points[j][1]));
            myGraph[i][j] = val;
            myGraph[j][i] = val;
        }
    }
//    return g.kruskals_minimumspanningtree();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<> > pq;
    map<int, bool> visited;
    pq.push({0, 0});
    map<int, int> scores,parent;
    scores[0] = 0;
    int child;
    while (!pq.empty()) {
        auto element = pq.top();
        pq.pop();
        if(visited[element.second])
            continue;
        visited[element.second] = true;
        for (int i = 0; i < myGraph[element.second].size(); i++) {
            if (!visited[i]) {
                parent[i] = element.second;
                if (!scores[i]) {
                    scores[i] = myGraph[element.second][i];
                    pq.push({myGraph[element.second][i],i});
                } else{
                    if(scores[i] > myGraph[element.second][i]){
                    scores[i] = myGraph[element.second][i];
                    pq.push({myGraph[element.second][i],i});
                    }
                }

            }
        }

    }
    int sum = 0;
    for (int k = 1; k <myGraph.size() ; ++k) {
        sum += scores[k];
    }
    return sum;
    //     score node
}

};