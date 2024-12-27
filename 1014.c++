class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& v) {
         int ind ;
        int n = v.size();
          ind = n-1;
        int ans = 0;
        for(int i = n-2; i  >= 0 ; i--){
                ans = max(ans, v[i]+v[ind]+i-ind);
              // while(!s.empty() &&   ) s.pop();
               if(v[ind]+i-ind < v[i]) ind = i;
        }
        return ans;
    }
};
