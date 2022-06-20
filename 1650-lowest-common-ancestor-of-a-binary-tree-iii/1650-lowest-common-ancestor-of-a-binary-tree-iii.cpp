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
        Node* pCopy = p;
        int pNum = 0;
        Node* qCopy = q;
        int qNum = 0;
        
        //find distance from the root
        while(pCopy->parent != nullptr){
            pCopy = pCopy->parent;
            pNum++;
        }
        while(qCopy->parent != nullptr){
            qCopy = qCopy->parent;
            qNum++;
        }
        
        //Put both pointers at the same depth
        while(qNum > pNum){
            q = q -> parent;
            qNum--;
        }
        while(pNum > qNum){
            p = p -> parent;
            pNum--;
        }
        
        //keep going to the next parent until you have the same parent
        while(p != q){
            p = p->parent;
            q = q->parent;
        }
        return p;
    }
};