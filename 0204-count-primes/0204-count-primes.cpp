// class Solution {
// public:
//     int countPrimes(int n) {
//         if(n == 1 || n == 0) return 0;
//         vector<bool> arr(n,false);
//         int ans = 0;
//         for(int i = 2; i*i < arr.size(); i++){
//             if(arr[i] == false){
//                 for(int j = i*i; j < arr.size(); j+=i){
//                     arr[j] = true;
//                 }
//             }
//         }
//         for(int i = 2; i < arr.size(); i++){
//             if(arr[i] == false){
//                 ans++;
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
	int countPrimes(int n) {
		//prime no. generation using sieve of eratothons
		vector<bool> prime(n + 1, true);
		prime[0] = false;
		prime[1] = false;
		for (int i = 2; i * i <= n; i++) {
			if (prime[i]) {
				for (int j = i * i; j <= n; j += i) {
					prime[j] = false;
				}
			}
		}
		//counting prime numbers
		int primeCount = 0;
		for (int i = 2; i < n; i++) {
			if (prime[i]) {
				primeCount++;
			}
		}
		return primeCount;
	}
};