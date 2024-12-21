class Solution {
     int ans = 0;
   int fun(Map<Integer, ArrayList<Integer>> graph, ArrayList<Integer> vis,int[] v, int k, int i){
              if(vis.get(i) ==1 ) return -1;
               vis.set(i, 1) ;
                 int val = 0;
               for(Integer x: graph.get(i)){
                  int cval = fun(graph, vis, v, k, x);
                  if(cval == -1) continue;
                  if(cval%k == 0){
                    ans++;
                  }else{
                    val+=cval;
                    val%=k;
                  }
               }
              return val+v[i];
   }


    public int maxKDivisibleComponents(int n, int[][] edges, int[] v, int k) {
        ans = 0;
        if(n ==1 ) return 1;
        Map<Integer, ArrayList<Integer>> graph = new HashMap<>();
        for(int i = 0 ; i < n-1; i++){
             graph.putIfAbsent(edges[i][0], new ArrayList<>());
            graph.putIfAbsent(edges[i][1], new ArrayList<>());
            graph.get(edges[i][0]).add(edges[i][1]);
            graph.get(edges[i][1]).add(edges[i][0]);
        }
          ArrayList<Integer> vis = new ArrayList<>(Collections.nCopies(n, 0));

        fun(graph, vis,v,k, 0  );
        return ans+1 ;

    }
}
