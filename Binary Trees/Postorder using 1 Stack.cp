//For every node:
//Go as far left as possible, pushing every node onto the stack.
//Look at the top node.
//If its right child doesn't exist or has already been visited, then it's safe to print the node.
//Otherwise, move to its right child.

vector<int> postorderTraversal(TreeNode* root) {

    vector<int> ans;

    stack<TreeNode*> st;

    TreeNode* curr = root;
    TreeNode* lastVisited = NULL;

    while (curr != NULL || !st.empty()) {

        // Go as left as possible
        while (curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }

        TreeNode* node = st.top();

        // If right child doesn't exist OR has already been processed
        if (node->right == NULL || node->right == lastVisited) {

            ans.push_back(node->val);

            st.pop();

            // Remember this node was processed
            lastVisited = node;
        }
        else {

            // Visit the right subtree
            curr = node->right;
        }
    }

    return ans;
}
