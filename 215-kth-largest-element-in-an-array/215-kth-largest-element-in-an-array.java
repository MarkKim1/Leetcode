class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> maxHeap = new PriorityQueue(Collections.reverseOrder());
        for(int i = 0; i < nums.length; i++){
            maxHeap.add(nums[i]);
        }
        int toPop = k-1;
        for(int i =0; i < toPop; i++){
            maxHeap.poll();
        }
        return maxHeap.peek();
    }
}