class Solution {
    public int tupleSameProduct(int[] nums) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        int n = nums.length;
        for(int i = 0 ; i< n; i++){
            for(int j = i+1 ; j < n ; j++){
                Integer val = nums[i]*nums[j];
                mp.putIfAbsent(val, 0);
                int x = mp.get(val);
                mp.put(val, x+1);
            }
             //i = 0;
        }
         int ans = 0;
         for(Integer x: mp.values()){
              ans += ((x*(x-1))/2) ; 
         }
         return ans*8;
    }
}
