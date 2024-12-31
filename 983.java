class Solution {
    int fun(int[] days, int[] c, int i, int[] dp){
         int len = days.length;
         if( i >= len) return 0;
         if(dp[i] != -1) return dp[i];
         int case1, case2, case3;
          case1 = fun(days, c, i+1, dp)+c[0];
          int j = i ;
          for(; j < len ; j++){
             if(days[i]+6 < days[j]) break;
          }
          case2 = fun(days, c, j, dp)+c[1];
          j = i;
             for(; j < len ; j++){
             if(days[i]+29 < days[j]) break;
          }
          case3 = fun(days, c, j, dp)+c[2];
          return dp[i] = Math.min(case1, Math.min(case2, case3));



    }
    public int mincostTickets(int[] days, int[] costs) {
        int len = days.length;
        int[] dp = new int[len+1];
        Arrays.fill(dp, -1);
        return fun(days, costs, 0, dp);
    }
}
