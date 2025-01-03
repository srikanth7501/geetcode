class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        //long long  sum = accumulate(nums.begin(), nums.end(), 0);
        long long sum = 0;
        for(int x : nums) sum+=x;
        long long lsum =0;
        int ans = 0 ;
        for(int i = 0 ; i < nums.size()-1; i++){
            lsum+= nums[i];
            sum -=  nums[i];
            if(lsum >= sum) ans++;
        }
        return ans;
    }
};
