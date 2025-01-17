class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        int last = 0;
        for(int i = 0 ; i < n-1 ; i++){
            int next = last^derived[i];
            last = next;
        }
         if(derived[n-1] == last^0) return true;
         last = 1;
         for(int i = 0 ; i < n-1 ; i++){
            int next = last^derived[i];
            last = next;
        }
         if(derived[n-1] == last^1) return true;
        return false;
    }
};
