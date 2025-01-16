class Solution {
public:
    int minimizeXor(int num1, int num2) {
        vector<int> v(32, 0);
        for(int i = 0 ; i < 32 ; i++)
            if(num1>>i & 1) v[i]++;
        int count = 0;
        for(int i = 0 ; i < 32 ; i++)
             if(num2>>i & 1) count++;
        int ans = 0;
        vector<int> b(32, 0);
        for(int i = 31 ; i >= 0 ;i--){
             if(count > 0 && v[i] == 1){
                b[i] = 1;
                count--;
             }
        }
         //int ans 
         for(int i = 0 ; i < 32 ; i++){
               if(count && b[i] == 0) {
                   count--;
                   b[i] = 1;
               }
                if(b[i]) ans+=pow(2, i);
         }
        return ans;
        
    }
};
