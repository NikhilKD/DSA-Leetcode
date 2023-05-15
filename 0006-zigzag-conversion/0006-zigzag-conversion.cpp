class Solution {
public:
    string convert(string s, int n) {
        string x;
        if(n==1){
            return s;
        }
        for(int i=0;i<n;i++){
            if(i==0 || i==n-1){
                int j=i;
                while(j<s.length()){
                    x+=s[j];
                    j+=(n-1)*2;   
                }
            }else{
                int j=i;
                while(j<s.length()){
                    x+=s[j];
                    if(j+((n-1)*2-(2*i))<s.length()){
                        x+=s[j+((n-1)*2-(2*i))];
                    }
                    j+=(n-1)*2;
                }
            }
        }
        return x;
    }
};