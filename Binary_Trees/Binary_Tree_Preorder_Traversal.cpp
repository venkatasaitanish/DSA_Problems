// Recursive
class Solution {
public:
    void solve(TreeNode* root, vector<int>& ans){
        if(root==NULL) return;
        ans.push_back(root->val);
        solve(root->left,ans);
        solve(root->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        solve(root,ans);
        return ans;
    }
};

// Iterative
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        while(!s.empty() || root!=NULL){
            if(root!=NULL){
                ans.push_back(root->val);
                s.push(root);
                root = root->left;
            }
            else{
                root = s.top();
                s.pop();
                root = root->right;
            }
        }
        return ans;
    }
};

// https://leetcode.com/problems/binary-tree-preorder-traversal/
