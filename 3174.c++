class Solution {
public:
    string clearDigits(string s) {
      string v;
      for(auto x: s){
          if(isdigit(x)){
            v.pop_back();
          }else{
            v.push_back(x);
          }
      }
      return v;
    }
};
