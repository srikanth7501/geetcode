class Solution {
        Map<String, Integer> mp = new HashMap<String, Integer> ();
    int fun(int val , int v[], int i){
        int n = v.length;
        if(i == n) return val == 0?1:0;
        String s = val +"sri" +i;
        if(mp.containsKey(s)) return mp.get(s);
        int ans = 0;
        ans+= fun(val-v[i], v, i+1);
        ans+=fun(val+v[i], v, i+1);
        mp.put(s, ans);
        return ans;

    }
    public int findTargetSumWays(int[] nums, int target) {
        mp.clear();
            return fun(target, nums, 0);
    }
}
