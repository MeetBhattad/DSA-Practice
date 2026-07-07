class Solution {
public:
    int getSum(TreeNode* root, int &res){
        if(root == NULL) return 0;

        int l = max(0, getSum(root->left, res));
        int r = max(0, getSum(root->right, res));

        int temp = max(l, r) + root->val;
        int ans = l+r + root->val;
        res = max(res, ans);

        return temp;
    }
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        getSum(root, res);
        return res;
    }
};
