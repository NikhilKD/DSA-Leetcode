class Solution {
public:
    // int square(int n){
    //     long long count=1;
    //     while(count<=n){
    //         count=count<<2;
    //     }
    //     return count;
    // }
    int rangeBitwiseAnd(int left, int right) {
        if(left==0 || right==0){
            return 0;
        }
        int lp=(int)log2(left);
        // int rp=(int)log2(right);
        if(left==right){
            return left;
        }
        if(pow(2,lp+1)<=right){
            return 0;
        }
        long long sum=left;
        for(long long i=left+1;i<=right;i++){
            sum=sum&i;
        }
        return sum;
    }
};



