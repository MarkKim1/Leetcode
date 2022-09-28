class Solution {
public:
    string pushDominoes(string d) {
        int right = -1;
        int left = 0;
        for(int i = 0; i < d.size(); i++){
            if(d[i] == 'L'){
                if(right == -1){
                    for(int j = i; j >= 0; j--){
                        d[j] = 'L';
                    }
                }else if(i > left and left > right){
                    for(int j = i; j >= left; j--){
                        d[j] = 'L';
                    }
                    left = i;
                }else{
                    left = i;
                    int temp_right = right;
                    int temp_left = left;
                    while(temp_right < temp_left){
                        d[temp_right++] = 'R';
                        d[temp_left--] = 'L';
                    }
                }
            }else if(d[i] == 'R'){
                if(right != -1 and (left < right || left == 0)){
                    for(int j = right; j < i; j++){
                        d[j] = 'R';
                    }
                }
                right = i;
            }
        }
        if(left < right || left == 0){
            for(int i = right; i < d.size(); i++){
                d[i] = 'R';
            }
        }
        return d;
    }
};