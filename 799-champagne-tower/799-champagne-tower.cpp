class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double result[102][102] = {0,0};
        result[0][0] = (double)poured;
        for(int i = 0; i <= query_row; i++){
            for(int j = 0; j <= query_glass; j++){
                double amountForNextGlass = (result[i][j] - 1.00) / 2.00;
                if(amountForNextGlass > 0){
                    result[i+1][j] += amountForNextGlass;
                    result[i+1][j+1] += amountForNextGlass;
                }
            }
        }
        double answer = min(1.000000,result[query_row][query_glass]);
        return (double)answer;
    }
};