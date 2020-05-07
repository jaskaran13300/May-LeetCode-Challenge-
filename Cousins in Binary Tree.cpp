/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sibb(TreeNode * root,int x,int y){
        if(!root){
            return 0;
        }
        if(root->left==NULL){
            return sibb(root->right,x,y);
        }
        if(root->right==NULL){
            return sibb(root->left,x,y);
        }
        if((root->left->val==x && root->right->val==y) || (root->left->val==y && root->right->val==x)){
            return true;
        }
        return sibb(root->left,x,y) || sibb(root->right,x,y);
    }
    int level(TreeNode * root,int x,int l){
        if(!root){
            return 0;
        }
        if(root->val==x){
            return l;
        }
        return level(root->right,x,l+1)+level(root->left,x,l+1);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if((level(root,x,0)==level(root,y,0)) && !sibb(root,x,y)){
            return true;
        }
        return false;
    }
};
