void traverse(struct TreeNode* root, int* res, int* index) {
    if (root == NULL) return;
    traverse(root->left, res, index);
    res[(*index)++] = root->val;
    traverse(root->right, res, index);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* res = (int*)malloc(100 * sizeof(int));
    int index = 0;
    traverse(root, res, &index);
    *returnSize = index;
    return res;
}