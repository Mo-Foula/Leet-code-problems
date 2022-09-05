/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<pair<Node*,int>> q;
        //  node and its level
        
        vector<vector<int>> levels;
        q.push({root,0});
        pair<Node*,int> temp;
        while(!q.empty()){
            temp = q.front();
            q.pop();
            if(temp.first == NULL) continue;
            
            if(levels.size() < temp.second + 1){
                // increase 1 level
                levels.push_back({(temp.first)->val});
            }else{
                levels[temp.second].push_back((temp.first)->val);
            }
            for(auto v : (temp.first)->children){
                    q.push({v,temp.second+1});
            }
        }
        return levels;
    }
};