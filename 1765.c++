class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
         int n = isWater.size(), m = isWater[0].size();
         vector<vector<int>> ans(n, vector<int>(m, -1));
         queue<pair<int, int>> q;
         for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(isWater[i][j] == 1){
                    ans[i][j] =0;
                    q.push({i, j});
                }
            }
         }
         int val = 1;
         while(!q.empty()){
            int k = q.size();
            for(int i = 0 ; i < k ; i++){
                 pair<int, int> p = q.front();
                 q.pop();
                  int row = p.first;
                  int col = p.second;
                  if(row-1 >= 0 && ans[row-1][col] == -1){
                      ans[row-1][col] = val;
                      q.push({row-1, col}) ;
                  }
                  if(row+1 < n && ans[row+1][col] == -1){
                      ans[row+1][col] = val;
                      q.push({row+1, col}) ;
                  }
                  if(col-1  >= 0 && ans[row][col-1] == -1){
                      ans[row][col-1] = val;
                      q.push({row, col-1}) ;
                  }
                  if(col+1  < m && ans[row][col+1] == -1){
                      ans[row][col+1] = val;
                      q.push({row, col+1}) ;
                  }
            }
            val+=1;
         }
         return ans;
    }
};
