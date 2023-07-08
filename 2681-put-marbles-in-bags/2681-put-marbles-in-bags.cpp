class Solution {
public:
    long long putMarbles(vector<int>& w, int k) {
        vector<int>pairSum;
        int n = w.size();

        for(int i=0;i<n-1;i++)
        {
            pairSum.push_back(w[i]+w[i+1]);
        }
        
        sort(pairSum.begin(),pairSum.end());

        long long max_score=0, min_score=0;

        for(int i=0;i<k-1;i++)
        {
            min_score += pairSum[i];
            max_score += pairSum[n-2-i];
        }

        return max_score - min_score;

    }
};