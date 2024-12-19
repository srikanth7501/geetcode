class Solution {
    public int maxChunksToSorted(int[] arr) {
        int n = arr.length;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == i) {
                count++;
            } else {
                int m = arr[i], j = i;
                while (j <= m) {
                    m = Math.max(m, arr[j]);
                    j += 1;
                }
                count++;
                j -= 1;
                i = j;

            }
        }
        return count;
    }
}
