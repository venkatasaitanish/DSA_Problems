// Recursive
class Solution {
public:
    void solve(TreeNode* root, vector<int>& ans){
        if(root==NULL) return;
        solve(root->left,ans);
        ans.push_back(root->val);
        solve(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        solve(root,ans);
        return ans;
    }
};

// Iterative
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> ans;
        while(!s.empty() || root!=NULL){
            if(root){
                s.push(root);
                root = root->left;
            }
            else{
                root = s.top();
                s.pop();
                ans.push_back(root->val);
                root = root->right;
            }
        }
        return ans;
    }
};

// https://leetcode.com/problems/binary-tree-inorder-traversal/
