/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
   public int fun(List<Integer> arr){
        Map<Integer, Integer> mp = new HashMap<>();
        for(int i = 0 ; i < arr.size(); i++){
            mp.putIfAbsent(arr.get(i), i);
        }
         int ans = 0;
        Collections.sort(arr);
         for(int i = 0 ; i < arr.size(); i++){
               while(mp.get(arr.get(i)) != i){
                   int temp = arr.get(mp.get(arr.get(i)));
                   arr.set(mp.get(arr.get(i)), arr.get(i));
                   arr.set(i, temp);
                   ans++;
               }
        }
        return ans;
   }




    public int minimumOperations(TreeNode root) {
      if(root == null) return 0;
     Deque<TreeNode> q = new ArrayDeque<>();
     q.offerLast(root);
      int ans = 0;
     while(q.isEmpty() == false){
        int n = q.size();
        List<Integer> arr = new ArrayList<>();
        for(int i = 0 ; i < n ; i++){
             arr.add(q.peekFirst().val);
            if(q.peekFirst().left  != null){
                q.offerLast(q.peekFirst().left);
            }
             if(q.peekFirst().right  != null){
                q.offerLast(q.peekFirst().right);
            }
            q.pollFirst();
        }
           ans+= fun(arr);


     }
     return ans;
         
    }
}
