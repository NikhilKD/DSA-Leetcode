class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n=pref.size();
        vector<int> v(n,0);
        v[0]=pref[0];
        int x=v[0];
        cout<<(3|1)<<endl;
        for(int i=1;i<n;i++){
            v[i]=(x^pref[i]);
            x=x^v[i];
        }
        return v;
    }
};
// 011

// 001