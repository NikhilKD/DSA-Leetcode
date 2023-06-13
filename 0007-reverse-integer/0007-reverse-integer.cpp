class Solution {
public:
    int reverse(int temp) {
        bool neg=false;
        long x=temp;
        if(temp<0){
            x=x*-1;
            neg=!neg;
        }
        long rev=0;
        while(x>0){
            int rem=x%10;
            rev=(rev*10)+rem;
            x=x/10;
        }
        if(rev>pow(2,31)-1 || rev<(pow(2,31)-1)*-1 ){
            return 0;
        }
        if(neg){
            rev*=-1;
        }
        return rev;
        
    }
};