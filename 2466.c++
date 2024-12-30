class Solution {
public:
    int fun(int l, int h, int z , int o, int len, vector<int>& dp){
        long long ans = 0;
        if(len  > h ) return 0;
        if(dp[len] != -1) return dp[len];
        if( l <= len && len <= h){
            ans+=1;
        }
         ans+= fun(l, h, z, o, len+z, dp);
         ans  = fmod(ans, 1e9+7);
         ans +=fun(l, h, z, o, len+o, dp);
         return dp[len] =fmod(ans, 1e9+7);
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> v(high+1, -1);
        return fun(low, high, zero, one, 0, v);
    }
};
