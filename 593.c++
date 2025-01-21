class Solution {
public:
   int dis(vector<int>& a, vector<int>& b){

    return (a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]);

   }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_map<int, int> mp;
        mp[dis(p1, p2)]+=1;
        mp[dis(p1, p3)]+=1;
        mp[dis(p1, p4)]+=1;
        mp[dis(p2, p3)]+=1;
        mp[dis(p2, p4)]+=1;
         mp[dis(p3, p4)]+=1;
         if(mp.count(0)) return false;
        if(mp.size() != 2 ) return false;
        if (mp.size() == 2) {
    auto it = mp.begin();
    if (it->second == 4 || (++it)->second == 4) {
        return true;
    }
}

          
       return false; 
    }
};
