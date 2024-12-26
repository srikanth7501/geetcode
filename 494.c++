class Solution {
public:
int  fun(vector<int>& v, int t, int i, map<pair<int, int>, int> &dp ){
        int n = v.size();
        if(t == 0 && i == n){
            return 1;
        }
        if(i == n ) return 0;
        if(dp.find({t, i}) != dp.end()) return dp[{t,i}];
        int x = fun(v, t-v[i], i+1, dp);
        int y = fun(v, t+v[i], i+1, dp);
        return dp[{t,i}] = x+y;


}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
         map<pair<int, int>, int> dp;
        return fun(nums, target,0, dp);
        
    }
};
