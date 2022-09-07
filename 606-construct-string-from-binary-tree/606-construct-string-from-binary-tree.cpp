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
    
    string dfs(TreeNode* node){
        if(node == NULL) return "";
        string s = to_string(node->val);
        if(node->left != NULL){
            s += "("+dfs(node->left)+")";
            if(node->right != NULL){
                s += "(" + dfs(node->right) + ")";
            }
        }else{
            if(node->right != NULL){
                s += "()(" + dfs(node->right) + ")";
            }
        }
        return s;
    }
    
    string tree2str(TreeNode* root) {
        return root == NULL?"":dfs(root);
    }
};