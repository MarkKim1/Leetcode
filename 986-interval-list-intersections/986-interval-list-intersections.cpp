class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& a, vector<vector<int>>& b) {
        int i = 0;
        int j = 0;
        vector<vector<int>> result;
        vector<int> sub_result;
        while(i < a.size() and j < b.size()){
            if(a[i][1] >= b[j][0] and b[j][1] >= a[i][0]){
            int low = max(a[i][0],b[j][0]);
            int high = min(a[i][1],b[j][1]);
            result.push_back({low,high});
            }
            if(b[j][1] > a[i][1]){
                i++;
            }
            else{
                j++;
            }
        }
        return result;
    }
};