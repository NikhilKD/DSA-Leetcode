class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        vector<int> p(n+1,0);
        int maxi=0;
        for(int i=0;i<n;i++){
            p[i+1]=p[i]+gain[i];
            maxi=max(p[i+1],maxi);
        }
        return maxi;
    }
};