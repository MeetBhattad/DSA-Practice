class Solution{
public:
    void addLeftbd(TreeNode* root, vector<int> &res){
        TreeNode* curr = root->left;
        while(curr){
        if(!isLeaf(curr)){
            res.push_back(curr->val);
        }
        if(curr->left) curr= curr->left;
        else curr = curr->right;
        }
    }

    void addRightbd(TreeNode* root, vector<int> &res){
        TreeNode* curr = root->right;
        vector<int> temp;
        while(curr){
            if(!isLeaf(curr)) temp.push_back(curr->val);
            if(curr->right) curr = curr->right;
            else curr = curr->left;
        }
        for(int i = temp.size()-1; i>= 0; i--){
            res.push_back(temp[i]);
        }
    }

    void addLeaves(TreeNode* root, vector<int> &res){
        if(isLeaf(root)){
            res.push_back(root->val);
            return;
        }
        if(root->left) addLeaves(root->left, res);
        if(root->right) addLeaves(root->right, res);
    }

    bool isLeaf(TreeNode* root){
        return !root->left && !root->right;
    }

    vector <int> boundary(TreeNode* root){
        vector<int> res;
        if(root == NULL) return res;
        if(!isLeaf(root)) res.push_back(root->val);
        addLeftbd(root, res);
        addLeaves(root, res);
        addRightbd(root, res);
        
        return res;
    }
};
