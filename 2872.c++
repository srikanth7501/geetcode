class Solution {
public:
 int ans = 0;
    int fun(unordered_map<int, vector<int>>& mp, vector<int>& v, vector<int>& vis, int k, int i){
            if(vis[i]) return -1;
            vis[i] = 1;
            long long val = 0;
            for(auto x: mp[i]){
                int  cval = fun(mp, v, vis, k, x);
                 if(cval == -1) continue;
                if( cval% k == 0){
                    ans++;
                }else{
                    val+= cval;
                    val%k;
                }
            }

          return  (val+v[i])%k;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        unordered_map<int, vector<int>> mp;
        for(auto e: edges){
            mp[e[0]].push_back(e[1]);
            mp[e[1]].push_back(e[0]);

        }
         vector<int> v(n, 0);
         int  val =fun(mp, values, v, k, 0);
         return ans+1;    
    }
};
