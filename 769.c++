class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int count = 0;
        int n = arr.size();

        for(int i = 0 ;i < n ; i++){
            if(arr[i] == i){
                count++;
            }else{
                int m = arr[i];
                int j = i;
                for(; j <= m;j++  ){
                    m = max(m, arr[j]);
                }
                j-=1;
                i= j;
                count++;
            }
        }
        return count;
    }
};
