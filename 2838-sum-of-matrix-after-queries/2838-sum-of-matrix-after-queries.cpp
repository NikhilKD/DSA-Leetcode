class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        int m=n;
        int a=m;
        int b=n;
        map<int,int> c;
        map<int,int> r;
        long long sum=0;
        for(int i=queries.size()-1;i>=0;i--){
            if(c.size()==n && r.size()==n){
                break;
            }
            if(queries[i][0]==1 && c.find(queries[i][1])==c.end()){
                sum+=(b*queries[i][2]);
                a--;
                c[queries[i][1]]==1;
            }else if(queries[i][0]==0 && r.find(queries[i][1])==r.end()){
                sum+=(a*queries[i][2]);
                b--;
                r[queries[i][1]]==1;
            }
        }
        return sum;
    }
};
// 0 0
// 0 0