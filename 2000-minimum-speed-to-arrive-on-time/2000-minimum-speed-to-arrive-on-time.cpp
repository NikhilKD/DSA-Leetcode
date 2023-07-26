class Solution {
public:
    bool f(int mid,vector<int>& dist, double hour){
        double x=0;
        for(int i=0;i<dist.size();i++){
            x+=((double)dist[i]/(double)mid);
            if(i!=dist.size()-1){
                x=ceil(x);
            }
        }
        // cout<<mid<<" <<x<<endl;
        return x<=hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
       int l=1;
       int h=1e9;
       while(l<=h){
           int mid=(l+h)/2;
           if(f(mid,dist,hour)){
               h=mid-1;
           }else{
               l=mid+1;
           }
       }
       cout<<l<<endl;
       return l>=1e9?-1:l;
    }
};