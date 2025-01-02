class Solution {
    public int[] vowelStrings(String[] words, int[][] queries) {
         int n = words.length;
         int m = queries.length;
         int arr[] = new int[n];
         int ans[] = new int[m];
          Set<Character> s = new HashSet<>();
          Collections.addAll(s, 'a', 'e', 'i', 'o', 'u');
         for(int i = 0 ; i< n ; i++){
            int k = words[i].length();
    if(s.contains(words[i].charAt(0)) == true && s.contains(words[i].charAt(k-1)) == true ){
                 arr[i] +=1;
    }
             if(i != 0) arr[i] = arr[i-1]+arr[i];
         }
        for(int i = 0 ; i < m ; i++){
            int val1 = 0,  val2 = 0;
            if(queries[i][0] != 0){
                val1 =  arr[queries[i][0]-1];
            }
             val2= arr[queries[i][1]];
             ans[i] = (val2 - val1);
        }
        return ans;




    }
}
