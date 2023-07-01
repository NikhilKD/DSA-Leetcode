class Solution {
public:
    int f(int i,vector<int> &v,vector<int>& cookies,int k){
        if(i==cookies.size()){
            int x=*max_element(v.begin(),v.end());
            return x;
        }
        int mini=INT_MAX;
        for(int j=0;j<k;j++){
            v[j]+=cookies[i];
            mini=min(mini,f(i+1,v,cookies,k));
            v[j]-=cookies[i];
        }
        return mini;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> v(k,0);
        return f(0,v,cookies,k);
    }
};