class Solution {
public:
    string longestPalindrome(string s) {
        
        
        int n=s.size();
        
        if(n==0)
            return "";
        
        int start=0;
        int end=0;
        bool dp[n][n];   
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                dp[i][j]=0;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
        }
        
        for(int i=0;i<(n-1);i++)
        {
                if(s[i]==s[i+1])
                {
                    dp[i][i+1]=1;
                    start=i;
                    end=i+1;
        
                }
        }
        
        for(int k=3;k<=n;k++)
        {
            //The starting index
            for(int i=0;i<(n-k+1);i++)
            {
                //The ending index
                int j=i+k-1;
                if(dp[i+1][j-1] && s[i]==s[j])
                {
                        dp[i][j]=1;
                        start=i;
                        end=j;
        
                        
                }       
            }
        }
        
        string ans="";
        
        for(int i=start;i<=end;i++)
        {
                ans+=s[i];
        }
        
        return ans;
        
    }
};
