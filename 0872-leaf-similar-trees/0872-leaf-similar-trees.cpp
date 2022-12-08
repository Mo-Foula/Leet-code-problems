/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        string dfs_leafSimilar(TreeNode *node)
        {
            if (node->left == NULL && node->right == NULL) return to_string(node->val)+",";
            string a, b;
            if (node->left != NULL) a = dfs_leafSimilar(node->left);
            if (node->right != NULL) b = dfs_leafSimilar(node->right);
            return a + b;
        }

    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        string leafValuesOfNode1 = dfs_leafSimilar(root1);
        string leafValuesOfNode2 = dfs_leafSimilar(root2);
        return leafValuesOfNode1 == leafValuesOfNode2;
    }
};