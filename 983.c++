class Solution {
public:
    int  fun(vector<int>& v, vector<int>& c, vector<int>& dp, int i){
        int n = v.size();
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        dp[i] = INT_MAX;
        vector<int> a ={1, 7, 30};
        int j = 0;
        while( j < 3){
            int k = v[i]+ a[j];
            int d = i;
            while(d < n && v[d] < k) d++;
            dp[i] = min(dp[i], fun(v, c, dp, d)+c[j]);
            j++;

        }
         
    return dp[i];
    }
    int mincostTickets(vector<int>& d, vector<int>& costs) {
        int n = d.size();
        vector<int> v(n, -1);
         return fun(d, costs, v, 0);
    }
};
