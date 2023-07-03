class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.length()!=goal.length()){
            return 0;
        }
        int count=0;
        map<int,int> m1;
        map<int,int> m2;
        for(int i=0;i<s.length();i++){
            if(s[i]!=goal[i]){
                count++;
            }
            m1[s[i]]++;
            m2[goal[i]]++;
        }
        if(s==goal){
            for(auto i:m1){
                if(i.second>=2){
                    return true;
                }
            }
        }
        // if(m1.size()==1 && s==goal){
        //     return true;
        // }
        return count==2 && m1==m2;
    }
};