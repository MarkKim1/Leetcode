class Solution {
public:
    int largestInteger(int num) {
        priority_queue<int> even;
        priority_queue<int> odd;
        string strNum = to_string(num);
        while(num){
            int curr = num % 10;
            if(curr % 2 == 0){
                even.push(curr);
            }else{
                odd.push(curr);
            }
            num /= 10;
        }
        for(int i = 0; i < strNum.size(); i++){
            if((strNum[i] - '0') % 2 == 0){
                strNum[i] = even.top() + '0';
                even.pop();
            }else{
                strNum[i] = odd.top() + '0';
                odd.pop();
            }
        }
        return stoi(strNum);
    }
};