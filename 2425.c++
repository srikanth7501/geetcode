class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
       vector<int> v(32, 0);
       int  len2 = nums2.size();
       int n = nums1.size();
       if(n%2 == 0 && len2%2 == 0) return 0;
       if(n%2 && len2%2){
         int  ans = 0;
         for(int i = 0 ; i < n ; i++) ans^= nums1[i];
         for(int j = 0 ; j < len2 ; j++) ans^= nums2[j];
         return ans;
       }
       if(n%2 == 0){
         int  ans = 0;
         for(int i = 0 ; i < n ; i++) ans^= nums1[i];
         return ans;
       }
        int  ans = 0;
         for(int j = 0 ; j < len2  ; j++) ans^= nums2[j];
         return ans;

    }
};
