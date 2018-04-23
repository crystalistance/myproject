struct TreeNode {
    struct TreeNode *left;
    struct TreeNode *right;
    int                val;
};

vector<int> preorder(TreeNode* root) {
    vector<int> res;

    stack<TreeNode*> st;
    if (root != NULL) {
        st.push(root);
    }

    while(!st.empty()) {
        TreeNode *t = st.top();
        st.pop();

        res.push_back(t->val);

        if (t->right != NULL) {
            st.push(t->right);
        }

        if (t->left != NULL) {
            st.push(t->left);
        }
    }

    return res;    
}

vector<int> inorder(TreeNode *root) {
    vector<int> res;

    stack<TreeNode *> st;
    TreeNode *cur = root;

    while (!st.empty() || cur != NULL) {
        while (cur) {
            st.push(cur);
            cur = cur->left;
        }

        if (!st.empty()) {
            cur = st.top();
            st.pop();

            res.push_back(cur->val);

            cur = cur->right;
        }
    }

    return res;
}

vector<int> postorder(TreeNode *root) {
    vector<int> res;

    stack<TreeNode*> st;
    if (root != NULL) {
        st.push(root);
    }
    
    while(!st.empty()) {
        TreeNode *t = st.top();
        st.pop();

        res.push_back(t->val);

        if (t->left) {
            st.push(t->left);
        }

        if (t->right) {
            st.push(t->right);
        }
    }

    res.reverse(res.begin(), res.end());

    return res;
}

TreeNode *createTree(const char *str) {
    
}


