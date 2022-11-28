class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<long> dp(arr.size(),1);
        unordered_map<long,long> map;
        long ans = 0;
        int MOD = pow(10,9) + 7;
        for(int i = 0; i < arr.size(); i++){
            for(auto each: map){
                if(arr[i] % each.first == 0 and map.find(arr[i]/each.first) != map.end()){
                    dp[i] += (each.second * map[arr[i]/each.first]) % MOD;
                }   
            }
            map[arr[i]] = dp[i];
            ans = (ans + dp[i]) % MOD;
        }
        return int(ans);
    }
};