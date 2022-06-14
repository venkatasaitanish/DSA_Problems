// Recursive
class Solution {
public:
    void solve(TreeNode* root, vector<int>& ans){
        if(root==NULL) return;
        solve(root->left,ans);
        solve(root->right,ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        solve(root,ans);
        return ans;
    }
};

// Iterative, push node 2 times into stack
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        while(!s.empty() || root!=NULL){
            if(root!=NULL){
                s.push(root);
                s.push(root);
                root = root->left;
            }
            else{
                root = s.top();
                s.pop();
                if(!s.empty() && s.top()==root){
                    root = root->right;
                }
                else{
                    ans.push_back(root->val);
                    root = NULL; // should make NULL or you will end up pushing the same node again & again
                }
            }
        }
        return ans;
    }
};

// Iterative, maintain last node
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode* last = NULL;
        while(!s.empty() || root!=NULL){
            if(root!=NULL){
                s.push(root);
                root = root->left;
            }
            else{
                root = s.top();
                if(root->right && last!=root->right){ // still right is not visited
                    root = root->right;
                }
                else{
                    ans.push_back(root->val);
                    last = root;
                    root = NULL;
                    s.pop();
                }
            }
        }
        return ans;
    }
};

// Iterative, Reverse preorder
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        while(!s.empty() || root!=NULL){
            if(root!=NULL){
                s.push(root);
                ans.push_back(root->val);
                root = root->right;
            }
            else{
                root = s.top();
                s.pop();
                root = root->left;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// https://leetcode.com/problems/binary-tree-postorder-traversal/
