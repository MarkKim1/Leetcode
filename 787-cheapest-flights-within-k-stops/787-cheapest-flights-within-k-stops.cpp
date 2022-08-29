class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n,INT_MAX);
        prices[src] = 0;
        for(int i = 0; i <=k; i++){
            vector<int> temp(prices);
            for(auto f : flights){
                if(prices[f[0]]==INT_MAX){
                    continue;
                }
                temp[f[1]] = min(temp[f[1]],prices[f[0]] + f[2]);
            }
            prices = temp;
        }
        return prices[dst] == INT_MAX ? -1 : prices[dst];
    }
};

// class Solution {
// public:
//     //bellman ford.
//     //just run it k+1 iterations.
//     int findCheapestPrice(int n, vector<vector<int>>& a, int src, int sink, int k) {
        
//         vector<int> c(n, 1e8);
//         c[src] = 0;
        
//         for(int z=0; z<=k; z++){
//             vector<int> C(c);
//             for(auto e: a)
//                 C[e[1]] = min(C[e[1]], c[e[0]] + e[2]);
//             c = C;
//         }
//         return c[sink] == 1e8 ? -1 : c[sink];
//     }
// };