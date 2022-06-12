// Recursive
class Solution {
public:
    bool solve(TreeNode* x, TreeNode* y){
        if(x==NULL && y==NULL) return true;
        if(x==NULL || y==NULL) return false;
        if(x->val!=y->val) return false;
        return solve(x->left,y->right) && solve(x->right,y->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return solve(root->left,root->right);
    }
};

// Iterative
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        queue<TreeNode*> q1,q2;
        q1.push(root->left);
        q2.push(root->right);
        while(!q1.empty()){
            TreeNode* node1 = q1.front();
            q1.pop();
            TreeNode* node2 = q2.front();
            q2.pop();
            if(node1==NULL && node2==NULL) continue;
            if(node1==NULL || node2==NULL) return false;
            if(node1->val != node2->val) return false;
            
            q1.push(node1->left);
            q2.push(node2->right);
            q1.push(node1->right);
            q2.push(node2->left);
        }
        return true;
    }
};

// https://leetcode.com/problems/symmetric-tree/
