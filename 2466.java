class Solution {
     final int MOD = 1000000007;
    int fun(int l, int h, int z, int o, int len, List<Integer> dp ){
        int  ans = 0;
        if(l <= len && len <= h){
            ans++;
        }
        if(len > h) return 0;
        if(dp.get(len) != -1) return  dp.get(len);
         ans += fun(l,h, z, o, len+o, dp);
         ans = ans % MOD;
         ans+=fun(l,h, z, o, len+z, dp);
         ans = ans % MOD;
         dp.set(len, ans);
         return dp.get(len);
    }
    public int countGoodStrings(int low, int high, int zero, int one) {
      int defaultValue = -1;
      List<Integer> dp = new ArrayList<>(Collections.nCopies(high+1, defaultValue));
      return fun(low, high, zero, one, 0, dp);

    }
}
