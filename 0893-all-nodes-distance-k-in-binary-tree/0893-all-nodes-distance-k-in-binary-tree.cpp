/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void bfs(TreeNode* root,int k,map<TreeNode*,TreeNode*> m,vector<int> &v){
        queue<pair<TreeNode*,int>> q;
        map<TreeNode*,int> vis;
        q.push({root,0});
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                auto x=q.front();
                q.pop();
                vis[x.first]=1;
                if(x.second==k){
                    v.push_back(x.first->val);
                    break;
                }
                if(m.find(x.first)!=m.end() && vis.find(m[x.first])==vis.end()){
                    q.push({m[x.first],x.second+1});
                }
                if(x.first->left!=NULL && vis.find(x.first->left)==vis.end()){
                    q.push({x.first->left,x.second+1});
                }
                if(x.first->right!=NULL&& vis.find(x.first->right)==vis.end()){
                    q.push({x.first->right,x.second+1});
                }

            }
        }

    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*> m;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* y;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* x=q.front();
                q.pop();
                if(x==target){
                    y=x;
                }
                if(x->left!=NULL){
                    m[x->left]=x;
                    q.push(x->left);
                }
                if(x->right!=NULL){
                    m[x->right]=x;
                    q.push(x->right);
                }
            }
        }
        vector<int> val;
        bfs(y,k,m,val);
        return val;

    }
};