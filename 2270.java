class Solution {
    public int waysToSplitArray(int[] nums) {
        long  sum = 0, lsum = 0;
        int ans = 0, n = nums.length;
        for(int i = 0 ; i < n ;i++){
            sum+=nums[i];
        }
         for(int i = 0 ; i < n-1 ;i++){
            sum-=nums[i];
            lsum +=nums[i];
            if(sum <= lsum) ans++;
        }
    


        return ans;
    }
}
