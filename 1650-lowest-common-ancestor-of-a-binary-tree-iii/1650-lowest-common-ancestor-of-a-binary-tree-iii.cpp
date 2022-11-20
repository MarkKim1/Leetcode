/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        int pdepth = getdepth(p);
        int qdepth = getdepth(q);
        if(pdepth > qdepth){
            swap(p,q);
        }
        int diff = abs(pdepth - qdepth);
        for(int i = 0; i < diff; i++){
            q = q->parent;
        }
        while(p != q){
            p = p->parent;
            q = q->parent;
        }
        return q;
    }
    int getdepth(Node* node){
        int depth = 0;
        while(node->parent){
            depth++,node = node->parent;
        }
        return depth;
    }
};