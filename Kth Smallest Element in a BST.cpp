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
    int help(TreeNode* root, int k,int &t){
        if(root==NULL){
            return INT_MAX;
        }
        int x=help(root->left,k,t);
        if(x!=INT_MAX){
            return x;
        }
        t++;
        if(t==k){
            return root->val;
        }
        return help(root->right,k,t);
    }
    int kthSmallest(TreeNode* root, int k) {
        int p=0;
        return help(root,k,p);
    }
};
