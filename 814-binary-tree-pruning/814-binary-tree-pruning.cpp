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
    
    bool dfs(TreeNode* node){
        if(node == NULL) return false;
        
        // bool willTrimMe = node->val;
        
        bool leftFalse = !dfs(node->left);
        bool rightFalse = !dfs(node->right);
        
        if(leftFalse) node->left = NULL;
        if(rightFalse) node->right = NULL;
        
        return node->val?true:!(leftFalse && rightFalse);
       
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        bool rootFalse = !dfs(root);
        return rootFalse?NULL:root;
    }
};