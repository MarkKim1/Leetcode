class Solution {
public:
    bool makesquare(vector<int>& match) {
        int total = 0;
        for(int a : match){
            total +=a;
        }
        if(match.size() < 4 || total % 4 != 0)return false;
        int target = total / 4;
        vector<int> sum(4,0);
        sort(match.begin(),match.end(),greater<int>());
        return DFS(0,target,sum,match);
    }
    bool DFS(int index, int target,vector<int>& sum, vector<int>& match){
        if(index == match.size()){
            return sum[0] == sum[1] and sum[1] == sum[2] and sum[2] == sum[3];
        }
        for(int i = 0; i < 4; i++){
            if(sum[i] + match[index] > target) continue;
            int j = i;
            while(--j >= 0){
                if(sum[j] == sum[i]){
                    break;
                }
            }
            if(j != -1) continue;
            sum[i]+=match[index];
            if(DFS(index+1,target,sum,match)){
                return true;
            }
            sum[i]-=match[index];
        }
        return false;
    }
};