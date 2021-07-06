class Solution {
public:
    int dp[601][101][101];
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        memset(dp,-1,sizeof(dp));
        int maxi = knapsack(strs,m,n,sz);
        return maxi;
    }
    int knapsack(vector<string> &strs,int m,int n,int sz){
              
        if(sz<=0 || m<0 || n<0)
            return 0;
        
        if(dp[sz][m][n]!=-1) return dp[sz][m][n];
        
        // cur string
        string s = strs[sz-1];
        int c0 = count(s.begin(),s.end(),'0');
        int c1 = s.size() - c0;
        // max
        // 1. pick     -  1 + k(strs,m-c0,n-c1,sz-1) 
        // 2. not pick -  k(strs,m,n,sz-1)
        
        if((m-c0)<0 || (n-c1)<0)
            return knapsack(strs,m,n,sz-1);  
        
        int ans = max(
            1 + knapsack(strs,m-c0,n-c1,sz-1),
            knapsack(strs,m,n,sz-1)
        );
        
        return dp[sz][m][n] = ans;   
    }
};
