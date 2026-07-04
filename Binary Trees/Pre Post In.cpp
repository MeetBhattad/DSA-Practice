class Solution {
public:

    vector<vector<int>> treeTraversal(TreeNode* root) {

        vector<int> pre;
        vector<int> in;
        vector<int> post;

        if (root == NULL)
            return {pre, in, post};

        // Stack stores {node, state}
        stack<pair<TreeNode*, int>> st;

        st.push({root, 1});

        while (!st.empty()) {

            auto it = st.top();
            st.pop();

            TreeNode* node = it.first;
            int state = it.second;

            // ---------------- PREORDER ----------------
            if (state == 1) {

                pre.push_back(node->val);

                // Next time this node comes, it'll be state 2
                st.push({node, 2});

                // Visit left subtree
                if (node->left)
                    st.push({node->left, 1});
            }

            // ---------------- INORDER ----------------
            else if (state == 2) {

                in.push_back(node->val);

                // Next time this node comes, it'll be state 3
                st.push({node, 3});

                // Visit right subtree
                if (node->right)
                    st.push({node->right, 1});
            }

            // ---------------- POSTORDER ----------------
            else {

                post.push_back(node->val);
            }
        }

        return {pre, in, post};
    }
};
