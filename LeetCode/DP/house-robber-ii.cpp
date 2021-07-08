class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n==1)
            return nums[0];
        if(n==2)
            return max(nums[0],nums[1]);
        
        int ans = max(rob_linear(0,n-2,nums),rob_linear(1,n-1,nums));
        return ans;
    }
    
    int rob_linear(int st,int end,vector<int>& nums){
        int cur = 0;
        int prev = 0;
        for(int i=st;i<=end;i++){    
            int temp = max(prev+nums[i],cur);
            prev = cur;
            cur = temp;
        }
        return cur;
    }
    
};
