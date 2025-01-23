class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> row(n, 0);
        vector<int> col(m, 0);
        int count= 0;
        vector<pair<int, int>> v;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] ==1 ){
                    row[i]++;
                    col[j]++;
                    v.push_back({i, j});
                    count++;
                }
            }
        }
        int ans = 0;
        for(auto x: v){
            if(row[x.first] == 1 && col[x.second] == 1) ans+=1;
        }


     return count-ans;
    }
};
