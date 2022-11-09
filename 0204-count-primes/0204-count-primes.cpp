class Solution {
public:
    int countPrimes(int n) {
        if(n == 1 || n == 0) return 0;
        vector<bool> prime(n,false);
        for(int i = 2; i < sqrt(n); i++){
            if(!prime[i]){
                for(int j = i*i; j < n; j += i){
                    prime[j] = true;
                }
            }
        }
        int primecount = 0;
        for(int i = 2; i < n; i++){
            if(!prime[i]){
                primecount++;
            }
        }
        return primecount;
    }
};