class Solution {
public:
    int minDeletions(string s) {
        map<char,int> m;
        for(auto i:s){
            m[i]++;
        }
        map<int,char> m1;
        int ans=0;
        for(auto i:m){
            int count=i.second;
            while(m1.find(count)!=m1.end()){
                count--;
                ans++;
                if(count==0){
                  break;
                }
            }
            cout<<endl;
            m1[count]=i.first;
        }
        return ans;
    }
};