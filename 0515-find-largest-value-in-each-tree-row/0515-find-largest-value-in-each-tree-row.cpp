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
    vector<int> largestValues(TreeNode* root) {
        vector<int> v;
        if(root==NULL){
            return v;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            int x=INT_MIN;
            for(int i=0;i<n;i++){
                TreeNode* y=q.front();
                q.pop();
                x=max(y->val,x);
                if(y->left!=NULL){
                    q.push(y->left);
                }
                if(y->right!=NULL){
                    q.push(y->right);
                }
            }
            v.push_back(x);
        }
    return v;
    }
};