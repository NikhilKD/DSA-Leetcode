class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        map<long long,long long> m1;
        map<long long,long long> m2;
        for(auto i:nums1){
            m1[(long long)i*(long long)i]++;
        }
        for(auto i:nums2){
            m2[(long long)i*(long long)i]++;
        }
        int count=0;
        for(int i=0;i<nums2.size();i++){
            for(int j=i+1;j<nums2.size();j++){
                if(m1[(long long)nums2[i]*(long long)nums2[j]]>=1 ){
                    count+=m1[(long long)nums2[i]*(long long)nums2[j]];
                }
            }
        }
        for(int i=0;i<nums1.size();i++){
            for(int j=i+1;j<nums1.size();j++){
                if(m2[(long long)nums1[i]*(long long)nums1[j]]>=1 ){
                    count+=m2[(long long)nums1[i]*(long long)nums1[j]];
                }
            }
        }
        return count;
        
    }
};