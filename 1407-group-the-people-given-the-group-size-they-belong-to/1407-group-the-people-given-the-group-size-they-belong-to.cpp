class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& g) {
        map<int,vector<int>> m;
        int n=g.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            m[g[i]].push_back(i);
            if(m[g[i]].size()==g[i]){
                ans.push_back(m[g[i]]);
                m[g[i]].erase(m[g[i]].begin(),m[g[i]].end());
            }
        }
        return ans;
    }
};