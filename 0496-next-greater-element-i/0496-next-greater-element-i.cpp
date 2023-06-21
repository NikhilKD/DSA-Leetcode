class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> m;
        int n=nums2.size();
        m[nums2[n-1]]=-1;
        stack<int> s;
        for(int i=n-1;i>=0;i--){
            if(s.empty()){
                s.push(i);
            }else{
                while(!s.empty() && nums2[s.top()]<=nums2[i]){
                    s.pop();
                }
                if(s.empty()){
                    m[nums2[i]]=-1;
                }else{
                    m[nums2[i]]=nums2[s.top()];
                }
                s.push(i);
            }
        }
        for(int i=0;i<nums1.size();i++){
            nums1[i]=m[nums1[i]];
        }
        return nums1;
    }
};