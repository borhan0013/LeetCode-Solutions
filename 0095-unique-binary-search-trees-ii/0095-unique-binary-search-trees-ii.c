#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode** generateTreesHelper(int start, int end, int* returnSize) {
    if (start > end) {
        struct TreeNode** result = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
        result[0] = NULL;
        *returnSize = 1;
        return result;
    }

    struct TreeNode** allTrees = NULL;
    int totalCount = 0;

    for (int i = start; i <= end; i++) {
        int leftSize = 0;
        struct TreeNode** leftTrees = generateTreesHelper(start, i - 1, &leftSize);

        int rightSize = 0;
        struct TreeNode** rightTrees = generateTreesHelper(i + 1, end, &rightSize);

        int newSize = totalCount + (leftSize * rightSize);
        allTrees = (struct TreeNode**)realloc(allTrees, newSize * sizeof(struct TreeNode*));

        for (int l = 0; l < leftSize; l++) {
            for (int r = 0; r < rightSize; r++) {
                struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
                root->val = i;
                root->left = leftTrees[l];
                root->right = rightTrees[r];
                allTrees[totalCount++] = root;
            }
        }
        free(leftTrees);
        free(rightTrees);
    }

    *returnSize = totalCount;
    return allTrees;
}

struct TreeNode** generateTrees(int n, int* returnSize) {
    if (n == 0) {
        *returnSize = 0;
        return NULL;
    }
    return generateTreesHelper(1, n, returnSize);
}