class Solution {
public:
    int getvalue(int x, vector<vector<int>>& matrix){
        int i=x/matrix[0].size();
        int j=x%matrix[0].size();
        return matrix[i][j];
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=0;
        int h=(matrix[0].size())*(matrix.size())-1; 
        while(l<=h){
            int m=l+(h-l)/2;
            int x=getvalue(m,matrix);
            if(x==target){
                return true;
            }else if(x>target){
                h=m-1;
            }else{
                l=m+1;
            }
        } 
        return false; 
    }
};
