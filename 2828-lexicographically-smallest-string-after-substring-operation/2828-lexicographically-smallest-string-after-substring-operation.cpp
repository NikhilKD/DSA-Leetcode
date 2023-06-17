class Solution {
public:
    string smallestString(string s) {
        int i=0;
        while(i<s.length() && s[i]=='a'){
            i++;
        }
        if(i==s.length()){
            s[s.length()-1]='z';
        }
        while(i<s.length() && s[i]!='a'){
            s[i]=s[i]-1;
            i++;
        }
        return s;
    }
};