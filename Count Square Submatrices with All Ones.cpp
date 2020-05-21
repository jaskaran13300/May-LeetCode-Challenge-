class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=0;
        if(r){
            c=matrix[0].size();
        }
        int dp[r][c];
        int ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(i==0 || j==0){
                    dp[i][j]=matrix[i][j];
                    ans+=dp[i][j];
                }
                else{
                    if(matrix[i][j]==1){
                        dp[i][j]=min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]))+1;
                        ans+=dp[i][j];
                    }
                    else{
                        dp[i][j]=0;
                        ans+=dp[i][j];
                    }
                        
                }
                cout<<dp[i][j];
            }
        }
        return ans;
    }
};
