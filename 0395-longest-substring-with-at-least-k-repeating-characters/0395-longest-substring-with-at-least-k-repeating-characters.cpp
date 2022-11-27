class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        return longestSubstringUtil(s,0,n,k);
    }
    int longestSubstringUtil(string s, int start, int end, int k){
        if(start >= end){
            return 0;
        }
        int countMap[26] = {0};
        for(int i = start; i < end; i++){
            countMap[s[i]-'a']++;
        }
        for(int mid = start; mid < end; mid++){
            if(countMap[s[mid]-'a'] >= k) continue;
            int midnext = mid+1;
            while(midnext < end and countMap[s[midnext]-'a'] < k){
                midnext++;
            }
            return max(longestSubstringUtil(s,start,mid,k),
                       longestSubstringUtil(s,midnext,end,k));
        }
        return end-start;
    }
};
//aabbbccddd k = 3
//a bbbccddd
//. bbbc ddd
//  
//0123456789
//[a = 2, b = 3, c = 2, d = 3]
//