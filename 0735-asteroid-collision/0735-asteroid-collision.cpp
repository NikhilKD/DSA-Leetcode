class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int> s;
        int n=ast.size();
        for(int i=0;i<n;i++){
            if(s.empty()){
                s.push(ast[i]);
            }else if(s.top()<0){
                s.push(ast[i]);
            }else{
                while(!s.empty() && (s.top()>0 && ast[i]<0)&&abs(s.top())<abs(ast[i])){
                    s.pop();
                }
                if(!s.empty() && ast[i]*-1==s.top()){
                    s.pop();
                    continue;
                }
                if(!s.empty() && (s.top()>0 && ast[i]<0) && abs(s.top())>abs(ast[i])){
                    continue;
                }
                s.push(ast[i]);
            }
        }
        vector<int> v;
        while(!s.empty()){
            v.push_back(s.top());
            s.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
};
