class Solution {
public:
    bool makesquare(vector<int>& match) {
        int total = accumulate(match.begin(),match.end(),0);
        if(match.size() < 4 || total % 4 != 0)return false;
        int target = total / 4;
        vector<int> sum(4,0);
        sort(match.rbegin(),match.rend());
        return DFS(0,target,sum,match);
    }
    bool DFS(int index, int target,vector<int>& sum, vector<int>& match){
        if(index >= match.size()){
            if(sum[0] == sum[1] and sum[1] == sum[2] and sum[2] == sum[3]){
                return true;
            }
            return false;
        }
        for(int i = 0; i < 4; i++){
            if(sum[i] + match[index] > target) continue;
            sum[i]+=match[index];
            int j = i;
            // while(--j >= 0){
            //     if(sum[j] == sum[i]){
            //         break;
            //     }
            // }
            // if(j != -1) continue;
            if(DFS(index+1,target,sum,match)){
                return true;
            }
            sum[i]-=match[index];
        }
        return false;
    }
};