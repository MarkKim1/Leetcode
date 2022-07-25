class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
    int result = 0;
    int maxsofar = A[0]+0;
    
    for (int i=1; i<A.size(); ++i)
    {
        maxsofar = max(maxsofar, A[i-1]+i-1);  
        result = max(result, A[i]-i+maxsofar);         
    }
    return result;
}
};