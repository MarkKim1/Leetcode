class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<long,long> map;
        vector<long> dp(arr.size(),1);
        sort(arr.begin(),arr.end());
        map[arr[0]]++;
        long ans = 1;
        int MOD = pow(10,9) + 7;
        for(int i = 1; i < arr.size(); i++){
            for(auto each : map){
                if(arr[i] % each.first == 0 and map.find(arr[i] / each.first) != map.end()){
                    dp[i] += (each.second * map[arr[i]/each.first]) % MOD;
                }
            }
            ans = (ans +dp[i]) % MOD;
            map[arr[i]] = dp[i];
        }
        return (int) ans;
    }
};