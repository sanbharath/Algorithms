class Solution {
public:
    map<pair<int,int>,int> memo;
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();  
        memo.clear();
        int scoreOfFirst = getBest(0,n-1,nums);
        cout<<scoreOfFirst<<endl;
        
        int tot = 0;
        for(auto x:nums){
            tot+=x;
        }
        return (tot-scoreOfFirst)<=(scoreOfFirst); 
    }
    
    int getBest(int l,int r,vector<int> nums){
        
        if(memo[{l,r}])
            return memo[{l,r}];
        
        if(l>r)
            return 0;
        if(l==r)
            return nums[l];
        
        // max
        // 1. nums[l] + min(getBest(l+2,r) , getBest(l+1,r-1))
        // 2. nums[r] + min(getBest(l,r-2), getBest(l+1,r-1))
        
        int best = max(
            nums[l] + min(getBest(l+2,r,nums) , getBest(l+1,r-1,nums)) ,
            nums[r] + min(getBest(l,r-2,nums), getBest(l+1,r-1,nums))
        );
        memo[{l,r}] = best;
        return best;
    }
};
