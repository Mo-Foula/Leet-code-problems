/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    Node* connect(Node* root) {
        vector<vector<Node*>> vec ;
        queue<Node*> q;
        q.push(root);
        vec.push_back({root});
        int level = 0;
        vec.push_back({});
        while(q.size()){
            auto x = q.front();
            q.pop();
            if(x == NULL){
                continue;
            }
            if(x->left != NULL){
                q.push(x->left);
                vec[level+1].push_back(x->left);
            }
            if(x->right != NULL){
                q.push(x->right);
                vec[level+1].push_back(x->right);
            }
             if(x == vec[level].back()){
                //last one
                x->next = NULL;
                vec.push_back({});
                level++;
            }else{
                while(q.front() == NULL) q.pop();
                if(q.size())
                    x->next = q.front();
            }
            // if(isLogOf2(x->val+1)){
            //     x->next = NULL;
            // }else{
            // }
        }
        // Node* node = root;
        // while(node != NULL){
        //     node->next = NULL;
        //     node = node->right;
        // }
        return root;
    }
};