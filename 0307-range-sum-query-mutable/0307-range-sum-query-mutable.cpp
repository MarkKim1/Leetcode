class NumArray {
public:
    vector<int> query;
    vector<int> nums;
    int n;
    void setquery(int pos, int left, int right, vector<int>& nums){
        if(left == right){
            query[pos] = nums[left];
            return;
        }
        int mid = (left + right) / 2;
        setquery(2*pos+1, left, mid, nums);
        setquery(2*pos+2, mid+1,right,nums);
        query[pos] = query[2*pos+1] + query[2*pos+2];
    }
    void updateHelper(int pos, int left, int right, int index, int val){
        if(index < left || index > right){
            return;
        }
        if(left == right){
            if(left == index){
                query[pos] = val;
                return;
            }
        }
        int mid = (right + left) / 2;
        updateHelper(2*pos+1, left, mid, index,val);
        updateHelper(2*pos+2, mid+1,right,index,val);
        query[pos] = query[2*pos+1] + query[2*pos+2];
    }
    int sumHelper(int pos, int numsleft, int numsright, int left, int right){
        if(numsleft >= left and numsright <= right){
            return query[pos];
        }
        if(numsleft > right || numsright < left){
            return 0;
        }
        int mid = (numsleft + numsright) / 2;
        return sumHelper(2*pos+1,numsleft,mid,left,right) + sumHelper(2*pos+2,mid+1,numsright,left,right);
    }
    NumArray(vector<int>& nums) {
        this->nums = nums;
        this->n = nums.size();
        this->query.resize(4*n,0);
        setquery(0,0,n-1,nums);
    }
    
    
    void update(int index, int val) {
        updateHelper(0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return sumHelper(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */