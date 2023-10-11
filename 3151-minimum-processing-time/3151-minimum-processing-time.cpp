class Solution {
public:
    int minProcessingTime(vector<int>& p, vector<int>& tasks) {
        priority_queue<int> q;
        sort(p.begin(),p.end());
        for(auto i:tasks){
            q.push(i);
        }
        int n=tasks.size();
        int maxi=0;
        for(int i=0;i<n/4;i++){
            int j=0;
            int cur=0;
            while(j<4){
                cout<<q.top()<<" "<<p[i]<<endl;
                cur=max(q.top()+p[i],cur);
                q.pop();
                j++;
            }
            maxi=max(maxi,cur);
        }
        return maxi;
    }
};