class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        const int n = matrix.size();
        int start = matrix[0][0];
        int end = matrix[n-1][n-1];
        while(start < end){
            int pivot = start + (end - start) / 2;
            
            vector<int> sub = {matrix[0][0],matrix[n-1][n-1]};
            
            int count = this->searchForCount(matrix,n,pivot,sub);
            
            if(count == k) return sub[0];
            
            if(count < k) start = sub[1];
            else end = sub[0];
            }
        return start;
    }
    int searchForCount(vector<vector<int>>&matrix,int n,int pivot, vector<int>&sub){
        int row = matrix.size()-1;
        int col = 0;
        int count = 0;
        while(row >= 0 and col < n){
            
            if(matrix[row][col] > pivot){
                sub[1] = min(sub[1],matrix[row][col]);
                row--;
                
            }else{
                sub[0] = max(sub[0],matrix[row][col]);
                count +=row+1;
                col++;
            }
        }
        //cout << "efef" << endl;
        return count;
    }
};