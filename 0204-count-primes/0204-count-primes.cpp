class Solution {
public:
    int countPrimes(int n) {
        if(n == 1 || n == 0) return 0;
        vector<bool> arr(n,false);
        for(int i = 2; i*i < n; i++){
            if(!arr[i]){
                for(int j = i*i; j < n; j+=i){
                    arr[j] = true;
                }
            }
        }
        int ans = 0;
        for(int i = 2; i < n; i++){
            if(arr[i] == false){
                ans++;
            }
        }
        return ans;
    }
};