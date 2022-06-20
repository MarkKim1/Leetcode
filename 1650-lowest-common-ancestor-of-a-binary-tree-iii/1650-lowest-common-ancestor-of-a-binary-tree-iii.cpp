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
        Node* qCopy = q;
        int pNum = 0;
        int qNum = 0;
        
        while(pCopy != NULL){
            pCopy = pCopy->parent;
            pNum++;
        }
        while(qCopy != NULL){
            qCopy = qCopy->parent;
            qNum++;
        }
        while(qNum > pNum){
            q = q->parent;
            qNum--;
        }
        while(pNum > qNum){
            p = p->parent;
            pNum--;
        }
        while(p != q){
            p = p->parent;
            q = q->parent;
        }
        return p;
    }
};