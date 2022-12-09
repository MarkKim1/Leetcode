
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        
        int maxdepth = finddepth(nestedList);
        cout << "maxdepth : " << maxdepth << endl;
        return findweight(nestedList,maxdepth,1);
    }
    int finddepth(vector<NestedInteger>& list){
       if(list.size() == 0)return 0;
        int maxdepth = 1;
        for(NestedInteger child : list){
            if(!child.isInteger()){
                maxdepth = max(maxdepth, 1 + finddepth(child.getList()));
            }
        }
        return maxdepth;
    }
    int findweight(vector<NestedInteger>& list, int maxdepth,int depth){
        int total = 0;
        for(auto child : list){
            if(child.isInteger()){
                total += child.getInteger() * (maxdepth - depth + 1);
            }else{
                total += findweight(child.getList(), maxdepth, depth + 1);
            }
        }
        return total;
    }
};