class Solution {
    public int maxScoreSightseeingPair(int[] v) {
       int ans = 0;
       int n = v.length;
       int ind = n-1;
       for(int i = n-2 ; i >= 0 ; i--){
           ans = Math.max(ans, v[i]+v[ind]+i-ind);
           if(v[i] > v[ind]+i-ind) ind = i;
       }
       return ans;
    }
}
