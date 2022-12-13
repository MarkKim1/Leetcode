/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    int index = 0;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr) return "";
        string str = "";
        vector<string> vals;
        serializeDFS(root,str,vals);
        for(string val : vals){
            str += val + ',';
        }
        str.pop_back();
        return str;
    }
    void serializeDFS(TreeNode* root, string& str,vector<string>& vals){
        if(!root){
            vals.push_back("N");
            return;
        }
        vals.push_back(to_string(root->val));
        serializeDFS(root->left,str,vals);
        serializeDFS(root->right,str,vals);
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;
        vector<string> vals;
        stringstream ss(data);
        string sub;
        while(getline(ss,sub,',')){
            vals.push_back(sub);
            //cout << "fasdf" << endl;
        }
        return deserializeDFS(vals);
        
    }
    TreeNode* deserializeDFS(vector<string>& vals){
        if(vals[index] == "N"){
            index+=1;
            return NULL;
        }
        TreeNode* node = new TreeNode(stoi(vals[index]));
        index+=1;
        node->left = deserializeDFS(vals);
        node->right = deserializeDFS(vals);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));