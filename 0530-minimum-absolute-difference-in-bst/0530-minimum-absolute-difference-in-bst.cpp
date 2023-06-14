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
    int ans=INT_MAX;
    void f(TreeNode* root,int &prev){
        if(root==NULL){
            return;
        }
        f(root->left,prev);
        ans=min(ans,abs(prev-root->val));
        prev=root->val;
        f(root->right,prev);
    }
    int getMinimumDifference(TreeNode* root) {
        int prev=-1e5;
        f(root,prev);
        return ans;
    }
};