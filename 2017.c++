class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
       int m = grid[0].size();
       long long sum1 = 0;
       long long sum2 = 0;
       int i = m-1, j = 0; //count = 0;
       while(i != j){
         if(sum1+grid[0][i] > sum2+grid[1][j]){
            sum2+=grid[1][j];
            j++;
         }else{
            sum1+=grid[0][i];
            i--;
         }
         
        //  cout<<sum1 <<" "<< sum2<<endl;
          //count++;
       }
      //cout<<i <<" "<<j<<endl;
       return max(sum1 , sum2 );
    }
};
