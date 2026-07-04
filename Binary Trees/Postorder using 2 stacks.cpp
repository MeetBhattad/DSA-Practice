vector<int> postOrder(Node* root) {
    vector<int> postorder; // Vector to store the postorder traversal

    // If the tree is empty, return an empty traversal
    if(root == NULL){
        return postorder;
    }

    // Two stacks for iterative traversal
    stack<Node*> st1, st2;

    // Push the root node onto the first stack
    st1.push(root);

    // Iterative traversal to populate st2 with nodes in postorder
    while(!st1.empty()){
        // Get the top node from st1
        root = st1.top();
        st1.pop();

        // Push the node onto st2
        st2.push(root);

        // Push left child onto st1 if exists
        if(root->left != NULL){
            st1.push(root->left);
        }

        // Push right child onto st1 if exists
        if(root->right != NULL){
            st1.push(root->right);
        }
    }

    // Populate the postorder traversal vector by popping st2
    while(!st2.empty()){
        postorder.push_back(st2.top()->data);
        st2.pop();
    }

    // Return the postorder traversal
    return postorder;
}
