class Solution {
public:
    bool bfs(int row,int col,vector<vector<int>> vis){
        queue<pair<int,int>> q;
        int di[]={1,0,-1,0};
        int dj[]={0,1,0,-1};
        for(int i=0;i<col;i++){
            if(!vis[0][i]){
                q.push({0,i});
                vis[0][i]=1;
            }
        }
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            if(x.first==row-1 && x.second>=0 && x.second<col){
                return true;
            }
            for(int i=0;i<4;i++){
                int xi=x.first+di[i];
                int xj=x.second+dj[i];
                if(xi>=0 && xj>=0 && xi<row && xj<col && !vis[xi][xj]){
                    vis[xi][xj]=1;
                    q.push({xi,xj});
                }
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int l=0;
        int h=cells.size()-1;
        while(l<=h){
            int mid=(l+h)/2;
            vector<vector<int>> vis(row,vector<int> (col,0));
            for(int i=0;i<=mid;i++){
                vis[cells[i][0]-1][cells[i][1]-1]=1;
            }
            if(bfs(row,col,vis)){
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        return l;
    }
};