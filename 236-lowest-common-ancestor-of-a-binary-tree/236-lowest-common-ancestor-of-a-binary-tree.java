/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    TreeNode ans;
    public Solution(){
        this.ans = null;
    }
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        found(root,p,q);
        return ans;
    }
    public boolean found(TreeNode root, TreeNode p, TreeNode q){
        if(root == null){
            return false;
        }
        
        int left = this.found(root.left,p,q) ? 1: 0;
        int right = this.found(root.right,p,q) ? 1: 0;
        
        int mid = (root.val == p.val || root.val == q.val) ? 1 : 0;
        
        if(mid + left + right >= 2){
            this.ans = root;
        }
        
        return (mid + left + right) > 0;
        
    }
}