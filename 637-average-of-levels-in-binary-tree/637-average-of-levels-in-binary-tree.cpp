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
        vector<double> averageOfLevels(TreeNode *root)
        {
            stack<pair<TreeNode*, int>> stk;
           	//      value   level
            stk.push({ root,
                0 });
            vector<vector < int>> numbers_in_levels;
            int max_lvl_idx = -1;

            pair<TreeNode*, int> p;

            while (!stk.empty())
            {
                p = stk.top();
                stk.pop();
                if (max_lvl_idx < p.second)
                {
                    max_lvl_idx++;
                    numbers_in_levels.push_back({ p.first->val });
                }
                else
                {
                    numbers_in_levels[p.second].push_back(p.first->val);
                }

                if (p.first->right != NULL)
                {
                    stk.push({ p.first->right,
                        p.second + 1 });
                }
                if (p.first->left != NULL)
                {
                    stk.push({ p.first->left,
                        p.second + 1 });
                }
            }

            vector<double> result(max_lvl_idx+1);
            for (int i = 0; i < numbers_in_levels.size(); i++)
            {
                double sum = 0;

                for (int j = 0; j < numbers_in_levels[i].size(); j++)
                {
                    sum += numbers_in_levels[i][j];
                }
                result[i] = sum / numbers_in_levels[i].size();
            }
            return result;
        }
};