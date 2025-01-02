class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size(), m = queries.size();
        vector<int> ans(m, 0), arr(n, 0);
        set<char> s = {'a', 'e', 'i', 'o','u'};
        for(int i = 0 ; i < n ; i++){
            int k = words[i]. size();
            if(s.count(words[i][0]) &&s.count(words[i][k-1])){
                arr[i]+=1;
            }
            if(i != 0) arr[i] +=arr[i-1];

        }
        for(int i = 0 ; i < m ; i++){
              if(queries[i][0] == 0) ans[i] = arr[queries[i][1]];
              else ans[i] = arr[queries[i][1]]-arr[queries[i][0]-1];
        }
        return ans;

        
    }
};
