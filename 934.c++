class Solution {
public:
    void dfs(queue<pair<int, int>>& q,vector<vector<int>>& grid, int i, int j, vector<vector<int>>& vis ){
          int n = grid.size() , m = grid[0].size();
          if(i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || grid[i][j] == 0) return;
          vis[i][j] =1 ;
          grid[i][j] = 0;
          q.push({i, j});
          dfs(q, grid, i-1, j, vis);
          dfs(q, grid, i+1, j, vis);
          dfs(q, grid, i, j-1, vis);
          dfs(q, grid, i, j+1, vis);
    }
    int shortestBridge(vector<vector<int>>& grid) {
       int n = grid.size() , m = grid[0].size();
       vector<vector<int>> vis(n, vector<int>(m, 0));
       queue<pair<int, int>> q;
       for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if( grid[i][j] == 1 && vis[i][j] == 0){
                  dfs(q, grid, i, j, vis);
                    break;
            }
        }
         if(q.size()) break;
       }
        //cout<<q.size()<<endl;
       int ans = 0;
       while(!q.empty()){
          int s = q.size();
          for(int i = 0 ; i < s; i++){
              pair<int, int> p = q.front();
              q.pop();
              int row = p.first;
              int col = p.second;
              // cout<<"start"<<" "<<row<<" "<<col<<endl;
              if(grid[row][col]) return ans-1;
               if(col-1  >= 0 && vis[row][col-1] == 0){
                 //cout<< row << " "<<col-1<<endl;
                 vis[row][col-1] = 1;
                 q.push({row, col-1});
               }
               if(col+1 < m && vis[row][col+1] == 0 ){
                // cout<< row << " "<<col+1<<endl;
                vis[row][col+1] = 1;
                    q.push({row, col+1});
               }
                 if(row+1 < n && vis[row+1][col] == 0 ){
                    // cout<< row+1 << " "<<col<<endl;
                     vis[row+1][col] = 1;
                    q.push({row+1, col});
               }
                 if(row-1 >= 0 && vis[row-1][col] == 0 ){
                    // cout<< row-11 << " "<<col<<endl;
                    q.push({row-1, col});
                    vis[row-1][col] = 1;
               }
               // cout<<"end"<<endl;
          }
              ans+=1;
       }
      return 0;
    }
};
