class Solution {
public:
    long long totalCost(vector<int>& nums, int k, int c) {
        priority_queue<int,vector<int>,greater<int>> a;
        priority_queue<int,vector<int>,greater<int>> b;
        int i=0;
        int j=nums.size()-1;
        while(i<c){
            a.push(nums[i]);
            i++;
        }
        while(c>0 && i<=j){
            b.push(nums[j]);
            j--;
            c--;
        }
        long long total=0;
        // while(!a.empty()){
        //     cout<<a.top()<<endl;
        //     a.pop();
        // }
        // while(!b.empty()){
        //     cout<<b.top()<<endl;
        //     b.pop();
        // }
        while(k>0 && !a.empty() && !b.empty()){
            // cout<<i<<" "<<j<<endl;
            if(a.top()<b.top()){
                total+=a.top();
                a.pop();
                if(i<=j){
                    a.push(nums[i]);
                    i++;
                }
            }else if(a.top()>b.top()){
                total+=b.top();
                b.pop();
                if(i<=j){
                    b.push(nums[j]);
                    j--;
                }
            }else{
                total+=a.top();
                a.pop();
                if(i<=j){
                    a.push(nums[i]);
                    i++;
                }
            }
            // cout<<k<<" "<<total<<endl;
            k--;
        }
        // cout<<total<<endl;
        while(k>0 && !a.empty()){
            total+=a.top();
            a.pop();
            k--;
        }
        while(k>0 && !b.empty()){
            total+=b.top();
            b.pop();
            k--;
        }
        return total;
    }
};