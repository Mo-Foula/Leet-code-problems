/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
int mxRow = 0;
    unordered_map<TreeNode*, pair<int,pair<int,int>> > m;
bool comp(pair<int,pair<int,int>>& a,pair<int,pair<int,int>>& b){
        // col first then row then val
        // p.second.second, p.second.first, p.first
        if(a.second.second == b.second.second){
            if(a.second.first == b.second.first){
                return a.first < b.first;
            }
            return a.second.first < b.second.first;
        }
        return a.second.second < b.second.second;
    }

class Solution {
public:
    
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<pair<int,pair<int,int>>> res;
        //        val       row  col
        
        // pair<int,pair<int,int>
        
        queue< TreeNode* > q;
        q.push(root);
        TreeNode* temp;
        pair<int,int> tempPosition;
        
        pair<int,pair<int,int>> toto;
        
        m[root] = {root->val,{0,0}};
        res.push_back({root->val,{0,0}});
        
        
        while(!q.empty()){
            temp = q.front();
            q.pop();
            
            if(temp == NULL) continue;
            
            tempPosition = m[temp].second;
            // row col
            
            
                
            
            if(temp->left != NULL){
                q.push(temp->left);
                toto = {temp->left->val,{tempPosition.first+1,tempPosition.second-1}};
                m[temp->left] = toto;
                res.push_back(toto);
            }
            if(temp->right != NULL){
                q.push(temp->right);
                toto = {temp->right->val,{tempPosition.first+1,tempPosition.second+1}};
                m[temp->right] = toto;
                res.push_back(toto);
            }  
        }
        sort(res.begin(),res.end(),comp);
        
        vector<vector<int>> v;
        
        int prevColumn = 200;
        // random positive integer as first col will be a negative number or 0
        
        for(auto x : res){
            // val, {row, col}
            if(prevColumn == x.second.second){
                v.back().push_back({x.first});
                
            }else{
                prevColumn = x.second.second;
                v.push_back({x.first});
            }
        }
        
        return v;
        
    }
};