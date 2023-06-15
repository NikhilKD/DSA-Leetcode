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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        root->val=0;
        vector<int> v;
        while(!q.empty()){
            int n=q.size();
            int sum=0;
            for(int i=0;i<n;i++){
                auto x=q.front();
                q.pop();
                if(x->left!=NULL){
                    sum+=x->left->val;
                    q.push(x->left);
                }
                if(x->right!=NULL){
                    sum+=x->right->val;
                    q.push(x->right);
                }
            }
            v.push_back(sum);
        }
        int j=0;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            int sum=v[j];
            cout<<sum<<endl;
            for(int i=0;i<n;i++){
                auto x=q.front();
                q.pop();
                if(x->left!=NULL){
                    sum-=x->left->val;
                    q.push(x->left);
                }
                if(x->right!=NULL){
                    sum-=x->right->val;
                    q.push(x->right);
                }
                if(x->left!=NULL){
                    x->left->val=sum;
                }
                if(x->right!=NULL){
                    x->right->val=sum;
                }
                sum=v[j];
            }
            j++;
        }
        return root;
    }
};