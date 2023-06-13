class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int> m;
        int n=grid.size();
        for(int i=0;i<n;i++){
            vector<int> v;
            for(int j=0;j<n;j++){
                v.push_back(grid[i][j]);
            }
            m[v]++;
        }
        int count=0;
        for(int i=0;i<n;i++){
            vector<int> v;
            for(int j=0;j<n;j++){
                v.push_back(grid[j][i]);
            }
            if(m[v]>=1){
                count+=m[v];
            }
        }
        return count;
    }
};
