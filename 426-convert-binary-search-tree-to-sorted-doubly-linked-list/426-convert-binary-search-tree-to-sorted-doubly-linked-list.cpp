/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* head = NULL;
    Node* tail = NULL;
    Node* treeToDoublyList(Node* root) { 
        if(!root)return NULL;
        inorder(root);
        tail->right = head;
        head->left = tail;
        return head;
    }
    void inorder(Node* curr){
        if(curr){
            inorder(curr->left);
            if(head){
                tail->right = curr;
                curr->left = tail;
            }else{
                head = curr;
            }
            tail = curr;
            inorder(curr->right);
        }
    }
};