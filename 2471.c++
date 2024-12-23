class Solution {
public:
 //int levl = 0;
    int fun(vector<int>& v){
    unordered_map<int, int> mp;
    int n = v.size();
    for(int i = 0 ; i < n ; i++){
         mp[v[i]] = i;
    }
     sort(v.begin(), v.end());
     int ans = 0;
     for(int i = 0 ; i < n ; i++){
           while(mp[v[i]] != i){
               int temp = v[mp[v[i]]];
              v[mp[v[i]]] = v[i];
              v[i] = temp;
               ans++;
           }
     }
      //cout<<levl<<" "<< ans<<endl;
      //levl+=1;
     return ans;


    }




    int minimumOperations(TreeNode* root) {
         if(!root) return 0;
         int ans = 0;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> v;
             int  n = q.size();
            for(int i = 0 ; i < n ; i++){
                  v.push_back(q.front()->val);
                  if(q.front()->left){
                    q.push(q.front()->left);
                  }
                  if(q.front()->right){
                    q.push(q.front()->right);
                  }
                  q.pop();
                 
            }
             ans += fun(v);


        }
        return ans;
    }
};
