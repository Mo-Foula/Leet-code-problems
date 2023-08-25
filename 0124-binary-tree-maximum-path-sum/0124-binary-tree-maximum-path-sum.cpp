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

        int mx = INT_MIN;

    int maxPathSumRecursive(TreeNode *root)
    {
        if (!root) return INT_MIN;

        int lhs = maxPathSumRecursive(root->left);
        int rhs = maxPathSumRecursive(root->right);

        mx = max({ mx,
            lhs,
            rhs,
            lhs != INT_MIN && rhs != INT_MIN ? lhs + root->val + rhs : INT_MIN });
        return max({ lhs,
            rhs,
            0 }) + root->val;
    }

    int maxPathSum(TreeNode *root)
    {
        return max(maxPathSumRecursive(root), mx);
    }
};