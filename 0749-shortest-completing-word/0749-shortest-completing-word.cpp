class Solution {
public:
    string shortestCompletingWord(string l, vector<string>& words) {
            map<char,int> m;
        	for(int i=0;i<l.length();i++){
                l[i]=tolower(l[i]);
                if(l[i]>='a' && l[i]<='z'){
                    m[l[i]]++;
                }
            }
            string x="";
            int maxi=0;
            for(int i=0;i<words.size();i++){
                map<char,int> m1=m;
                int count=0;
                string y=words[i];
                for(int j=0;j<words[i].length();j++){
                    if(m1.find(y[j])!=m1.end()){
                        m1[y[j]]--;
                        count++;
                        if(m1[y[j]]==0){
                            m1.erase(y[j]);
                        }
                    }
                }
                if(maxi<count){
                    x=y;
                    maxi=count;
                }
                if(maxi==count && x.length()>y.length()){
                    x=y;
                }
            }
            return x;


    }
};