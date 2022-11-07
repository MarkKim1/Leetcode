class NumArray {
    vector<int> query;
    vector<int> nums;
    int n;
public:
    NumArray(vector<int>& nums) {
        this->n = nums.size();
        this->nums = nums;
        query.resize(nums.size() * 4,0);
        setquery(0,0,nums.size()-1,nums,query);
    }
    void setquery(int pos, int left, int right, vector<int>& nums, vector<int>& query){
        if(left == right){
            query[pos] = nums[left];
            return;
        }
        int mid = (left + right) / 2;
        setquery(2*pos+1, left, mid,nums,query);
        setquery(2*pos+2,mid+1,right,nums,query);
        query[pos] = query[2*pos+1] + query[2*pos+2];
    }
    
    void update(int index, int val) {
        if(n == 0) return;
        updateUtil(0,n-1,index,val,0);
    }
    void updateUtil(int left, int right, int index, int val,int pos){
        if(index < left || index > right){
            return;
        }
        if(left == right){
            
                query[pos] = val;    
            
            return;
        }
        int mid = (left + right) / 2;
        updateUtil(left, mid,index,val,2*pos+1);
        updateUtil(mid+1, right,index,val,2*pos+2);
        query[pos] = query[2*pos+1] + query[2*pos+2];
    }
    
    int sumRange(int left, int right) {
        if(n == 0) return 0;
        return rangeUtil(left,right,0,n-1,0);
    }
    int rangeUtil(int qlow, int qhigh, int low, int high, int pos){
        if (qlow <= low && qhigh>= high){ // total overlap
            return query[pos];
        }
        if (qlow > high || qhigh < low) { // no overlap
            return 0;
        }
        // partial overlap
        int mid = (high + low)/2;
        return (rangeUtil(qlow, qhigh, low, mid, 2*pos+1) + rangeUtil(qlow, qhigh, mid+1, high, 2*pos+2));
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */