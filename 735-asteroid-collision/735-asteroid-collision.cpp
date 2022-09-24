class Solution {
public:
    vector<int> asteroidCollision(vector<int>& as) {
        vector<int> ans;
        for(int i = 0; i < as.size(); i++){
            while(!ans.empty() && ans.back() > 0 && ans.back() < -as[i]){
                ans.pop_back();
            }
            if(ans.empty() || as[i] > 0 || ans.back() < 0){
                ans.push_back(as[i]);
            }
            else if(as[i] < 0 && ans.back() == -as[i]){
                ans.pop_back();   
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> asteroidCollision(vector<int>& a) {
//         vector<int> s; // use vector to simulate stack.
//         for (int i : a) {
//             while (!s.empty() && s.back() > 0 && s.back() < -i)
//                 s.pop_back();
//             if (s.empty() || i > 0 || s.back() < 0)
//                 s.push_back(i);
//             else if (i < 0 && s.back() == -i)
//                 s.pop_back();
//         }
//         return s;
//     }
// };