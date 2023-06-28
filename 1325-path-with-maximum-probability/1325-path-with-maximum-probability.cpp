class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>> adj(n);
        int k=0;
        for(auto i:edges){
            adj[i[0]].push_back({i[1],succProb[k]});
            adj[i[1]].push_back({i[0],succProb[k]});
            k++;
        }
        vector<double> dis(n,0);
        set<pair<int,int>> s;
        s.insert({1,start});
        dis[start]=1;
        while(!s.empty()){
            auto x=*(s.begin());
            s.erase(x);
            for(auto i:adj[x.second]){
                if(dis[i.first]<dis[x.second]*i.second){
                    s.erase({dis[i.first],i.first});
                    dis[i.first]=(dis[x.second]*i.second);
                    s.insert({dis[i.first],i.first});
                }
            }
        }
        return dis[end];
    }
};