class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 0;
        for(int i = 0; i < points.size(); i++){
            unordered_map<string,int> map;
            int dup = 1;
            for(int j = i+1; j < points.size(); j++){
                if(points[i][0] == points[j][0] and points[i][1] == points[j][1]){
                    dup++;
                }else{
                    int dx = points[i][0] - points[j][0];
                    int dy = points[i][1] - points[j][1];
                    int g = gcd(dx, dy);
                    map[to_string(dx/g) + '_' + to_string(dy/g)]++;
                }
            }
            ans = max(ans, dup);
            for(auto each : map){
                ans = max(ans,each.second + dup);
            }
        }
        return ans;
    }
    int gcd(int a, int b){
        if(b == 0){
            return a;
        }
        return gcd(b,a%b);
    }
};