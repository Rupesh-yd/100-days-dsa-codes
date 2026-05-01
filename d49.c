//BST Insert
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert into BST
struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    // If tree is empty → create node
    if (root == NULL) {
        return createNode(val);
    }

    // If value is smaller → go left
    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    }
    // If value is greater → go right
    else {
        root->right = insertIntoBST(root->right, val);
    }

    return root;
}