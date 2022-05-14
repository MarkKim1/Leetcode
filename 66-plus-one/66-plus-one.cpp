class Solution {
public:
    vector<int> plusOne(vector<int>& a) {
        int upper = 0;
        int flag = 0;
        for(int i = a.size()-1; i >= 0; i--){
            if(a[i] == 9){
                a[i] = 0;
                upper = 1;
            }else{
                if(upper == 1){
                    a[i]++;
                    flag = 1;
                    break;
                }else{
                    a[i]++;
                    return a;
                }
            }
        }
        if(flag = 1 && a.front() == 0){
            a.front() = 1;
            a.push_back(0);
        }
        return a;
    }
};