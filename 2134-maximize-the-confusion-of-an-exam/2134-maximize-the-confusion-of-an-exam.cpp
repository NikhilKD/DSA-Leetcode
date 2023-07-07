class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        queue<char> q;
        int t=0;
        int f=0;
        int maxi=0;
        for(auto i:answerKey){
            q.push(i);
            if(i=='T'){
                t++;
            }else{
                f++;
            }
            int mini=min(t,f);
            while(!q.empty() && mini>k){
                if(q.front()=='T'){
                    t--;
                }else{
                    f--;
                }
                mini=min(t,f);
                q.pop();
            }
            int x=q.size();
            maxi=max(maxi,x);
        }
        return maxi;
    }
};