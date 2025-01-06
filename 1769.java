class Solution {
    public int[] minOperations(String boxes) {
        int n = boxes.length();
        int[] ans = new int[n];
        int[] left = new int[n];
        int [] right = new int[n];
        int count = 0;
        if(boxes.charAt(0) == '1') count++;
        for(int i = 1 ; i < n ; i++){
             left[i] = left[i-1]+ count;
             if(boxes.charAt(i) == '1') count++;
        }
        count = 0;
        if(boxes.charAt(n-1) == '1') count++;
        for(int i = n-2 ; i >= 0 ; i--){
            right[i] = right[i+1] + count;
             if(boxes.charAt(i) == '1') count++;
        }
         for(int i = 0 ; i <n ; i++){
             ans[i] = right[i]+left[i];
         }
         return ans;
    }
}
