class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int i=0;i<n;i++){
            for(int j=0;j<2;j++){
                dp[i][j][0]=0;
            }
        }
        for(int j=0;j<2;j++){
            for(int k=0;k<3;k++){
                dp[0][j][k]=0;
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int k=1;k<3;k++){
                    int profit=0;
                    if(j){
                        int pick=-prices[i]+dp[i+1][false][k];
                        int notPick=0+dp[i+1][true][k];
                        profit=max(pick,notPick);
                    }
                    else{
                        int pick=prices[i]+dp[i+1][true][k-1];
                        int notPick=dp[i+1][false][k];
                        profit=max(pick,notPick);
                    }
                    dp[i][j][k]=profit;
                }
            }
        }
        return dp[0][true][2];
    }
};