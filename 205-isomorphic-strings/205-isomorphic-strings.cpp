class Solution {
public:
    bool isIsomorphic(string s, string t) {
        array<int,256>fromStringS{};
        array<int,256>fromStringT{};
        fromStringS.fill(-1);
        fromStringT.fill(-1);
        
        for(int i = 0; i < s.size(); i++){
            char c1 = s[i];
            char c2 = t[i];
            if(fromStringS[c1] == -1 && fromStringT[c2] == -1){
                fromStringS[c1] = c2;
                fromStringT[c2] = c1;
            }
            else if(!(fromStringS[c1] == c2 && fromStringT[c2] == c1)){
                return false;
            }
        }
        
     return true;   
    }
};