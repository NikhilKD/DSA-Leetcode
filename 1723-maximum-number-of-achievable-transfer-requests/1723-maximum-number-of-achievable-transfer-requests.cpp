class Solution {
public:
    int ans=0;
    void f(int i,int count,vector<vector<int>>& requests,unordered_map<int,int> &m){
        if(i==requests.size()){
            for(auto i:m){
                if(i.second!=0){
                    return;
                }
            }
            ans=max(ans,count);
            return;
        }
        m[requests[i][0]]--;
        m[requests[i][1]]++;
        f(i+1,count+1,requests,m);
        m[requests[i][0]]++;
        m[requests[i][1]]--;

        f(i+1,count,requests,m);
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        unordered_map<int,int> m;
        f(0,0,requests,m);
        return ans;
    }
};