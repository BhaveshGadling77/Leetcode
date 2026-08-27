/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int helper(TreeNode* node) {
        if (node == NULL) {
            return INT_MIN;
        }
        int lmax = helper(node->left);
        int rmax = helper(node->right);
        return max({node->val, lmax, rmax});
    }
    int countDominantNodes(TreeNode* node) {
        if (node == NULL) 
            return 0;
        
        if (node->left == NULL && node->right == NULL) {
            return 1;
        }
        
        int lmax = INT_MIN, rmax = INT_MIN;
        if (node->left) 
            lmax = helper(node->left);
        
        if (node->right)
            rmax = helper(node->right);
        int ans = 0;
        if (node->val == max({node->val, lmax, rmax}))
            ans++;

        return ans + countDominantNodes(node->left) + countDominantNodes(node->right);
    }
};