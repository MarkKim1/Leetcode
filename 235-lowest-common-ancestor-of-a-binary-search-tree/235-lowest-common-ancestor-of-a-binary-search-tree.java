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
    
    public boolean found(TreeNode currentRoot, TreeNode p, TreeNode q){
        if(currentRoot == null){
            return false;
        }
        int left = found(currentRoot.left,p,q) ? 1 : 0;
        int right = found(currentRoot.right,p,q) ? 1: 0;
        
        int mid = (currentRoot.val == p.val || currentRoot.val == q.val) ? 1: 0;
        
        if(left + right + mid >= 2){
            this.ans = currentRoot;
        }
        return mid+right+left > 0;
    }
}