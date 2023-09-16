class Solution {
public:
    vector<vector<int>> isVisited;
    vector<pair<int,int>> steps = {
        {-1, 0},
        {0, -1},
        {1, 0},
        {0, 1}
    };
    int canReachEndWithK(vector<vector<int>>& graph, int k, int x, int y){
        if (isVisited[x][y]){
            return false;
        }
        isVisited[x][y] = true;
        if (x == graph.size() - 1 && y == graph[x].size() - 1){
            return true;
        }
        int x2,y2;
        for (auto step : steps){
            x2 = x + step.first;
            y2 = y + step.second;
            if (x2 < 0 || y2 < 0 || x2 >= graph.size() || y2 >= graph[x].size() )
                continue;
            if (abs(graph[x][y] - 
            graph[x2][y2]) <= k && canReachEndWithK(graph, k, x2, y2)){
                return true;
            }
        }
        return false;
    }   

    void resetVisited(vector<vector<int>>& graph){
        isVisited.clear();
        for (int i = 0; i < graph.size(); ++i) {
            isVisited.push_back(vector(graph[i].size(), 0));
        }
    }

    int binary_search_k_first_true(vector<vector<int>>& graph) {
        int l = 0, r = 1e6, mid, ans = -1;
        while (l <= r){
            resetVisited(graph);
            mid = l + (r - l) / 2;
            if (canReachEndWithK(graph, mid, 0, 0)) {
                r = mid - 1;
                ans = mid;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        return binary_search_k_first_true(heights);
    }
};