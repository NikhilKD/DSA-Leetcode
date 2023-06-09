class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int temp=x;
        long rev=0;
        while(temp>0){
            int rem=temp%10;
            rev*=10;
            rev+=rem;
            temp/=10;
        }
        return rev==x;
        
    }
};