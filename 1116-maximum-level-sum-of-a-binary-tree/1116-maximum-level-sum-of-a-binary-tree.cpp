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
    int maxLevelSum(TreeNode* root) {
        int ans=1;
        int maxi=INT_MIN;
        queue<TreeNode*> q;
        q.push(root);
        int count=1;
        while(!q.empty()){
            int n=q.size();
            int sum=0;
            for(int i=0;i<n;i++){
                auto x=q.front();
                q.pop();
                sum+=x->val;
                if(x->left!=NULL){
                    q.push(x->left);
                }
                if(x->right!=NULL){
                    q.push(x->right);
                }
            }
            if(sum>maxi){
                maxi=sum;
                ans=count;
            }
            count++;
        }
        return ans;
        
    }
};