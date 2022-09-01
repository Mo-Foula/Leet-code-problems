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
class Solution {
public:
    
    int goodNodes(TreeNode* root) {
        bool flag = true;
        stack<pair<TreeNode*,int>> stk;
        //      DFS node, max until it (before it)
        stk.push({root,-1e4-5});
        TreeNode* node;
        int mx_above_node = 0,counter = 0;
        
        while(!stk.empty()){
            node = stk.top().first;
            mx_above_node = stk.top().second;
            stk.pop();
            
            if(mx_above_node <= node->val){
                counter++;
            }
            
            mx_above_node = max(mx_above_node,node->val);
            
            if(node->left != NULL){
                // push in stack
                stk.push({node->left,mx_above_node});
            }
            if(node->right != NULL){
                // push in stack
                stk.push({node->right,mx_above_node});
            }
            
        }
        return counter;
    }
};