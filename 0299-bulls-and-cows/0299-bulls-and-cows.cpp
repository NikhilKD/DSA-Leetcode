class Solution {
public:
    string getHint(string secret, string guess) {
        map<int,char> m;
        map<char,int> m1;
        for(int i=0;i<secret.length();i++){
           m[i]=secret[i];
           m1[secret[i]]++;
        }
        int a=0;
        int b=0;
        string x="";
        for(int i=0;i<guess.length();i++){
            if(m[i]==guess[i]){
                m1[guess[i]]--;
                if(m1[guess[i]]==0){
                    m1.erase(guess[i]);
                }
                a++;
            }else{
                x+=guess[i];
            }
        }
        for(int i=0;i<x.length();i++){
            if(m1.find(x[i])!=m1.end()){
                m1[x[i]]--;
                b++;
                if(m1[x[i]]==0){
                    m1.erase(x[i]);
                }
            }
        }
        string s="";
        s+=to_string(a);
        s+="A";
        s+=to_string(b);
        s+="B";
        return s;

    }
};