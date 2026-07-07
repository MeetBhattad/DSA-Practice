class Solution {
public:
    int ans = 0;

    int getheight(TreeNode* root){
        if(root == NULL) return 0;
        int lh = getheight(root->left);
        int rh = getheight(root->right);

        ans = max(ans, lh+rh);

        return 1 + max(lh, rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        getheight(root);
        return ans;
    }
};
