class Solution {
public:
    
    vector<int> sortByBits(vector<int>& arr) {
           auto comparator = [](int &x, int &y) {
            int x_1 = 0;
            int y_1 = 0;
            
            int temp_x = x;
            int temp_y = y;
            
            while(temp_x) {
                temp_x = temp_x & (temp_x-1);
                x_1++;
            }
            
            while(temp_y) {
                temp_y = temp_y & (temp_y-1);
                y_1++;
            }
            
            if(x_1 == y_1)
                return x < y;
            
            return x_1<y_1;
        };
        
        sort(arr.begin(),arr.end(),comparator);
        return arr;
    }
};