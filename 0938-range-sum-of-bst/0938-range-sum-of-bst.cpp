/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *  int val;
 *  TreeNode * left;
 *  TreeNode * right;
 *  TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        int rangeSumBST(TreeNode *root, int low, int high)
        {
           	// DFS
            stack<TreeNode*> stk;
            stk.push(root);
            TreeNode * node;
            int sum = 0;
            while (!stk.empty())
            {
                node = stk.top();
                stk.pop();
                if (node->left != NULL) stk.push(node->left);
                if (node->right != NULL) stk.push(node->right);
                if(node->val >= low && node->val <= high) sum += node->val;
            }
            return sum;
        }
};