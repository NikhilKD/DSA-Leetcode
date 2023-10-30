class Solution {
public:
    int bits(int x){
        int count=0;
        while(x>0){
            if( (x&1) !=0){
                count++;
            }
            x=x>>1;
        }
        return count;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),[this](int i,int j){
        return bits(i)==bits(j)?(i<j):bits(i)<bits(j);
    });
    return arr;
    }
};