class Solution {
public:
    vector<int> f(string ex){
        if(ex.length()==1 ||ex.length()==2 ){
            vector<int> dig;
            dig.push_back(stoi(ex));
            return dig;
        }
        vector<int> ans;
        for(int i=0;i<ex.length();i++){
            if(ex[i]=='+'|| ex[i]=='-'||ex[i]=='*'){
                vector<int> left=f(ex.substr(0,i));
                vector<int> right=f(ex.substr(i+1,ex.length()));
                for(auto j:left){
                    for(auto k:right){
                        if(ex[i]=='+'){
                            ans.push_back(j+k);
                        }else if(ex[i]=='-'){
                            ans.push_back(j-k);
                        }else{
                            ans.push_back(j*k);
                        }
                    }
                }
            }
        }
        return ans;
    }
    vector<int> diffWaysToCompute(string expression) {
        return f(expression);
    }
};