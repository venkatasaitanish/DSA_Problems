// Recursive
class Solution {
public:
    int solve(TreeNode* root, bool& ans){
        if(root==NULL) return 0;
        int lh = solve(root->left,ans);
        int rh = solve(root->right,ans);
        if(abs(lh-rh)>1) ans = false;
        return max(lh,rh)+1;
    }
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        solve(root,ans);
        return ans;
    }
};

// Iterative postorder
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        stack<TreeNode*> s;
        TreeNode* last = NULL;
        unordered_map<TreeNode*,int> m;
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
                    int l = m[root->left];
                    int r = m[root->right];
                    if(abs(l-r)>1) return false;
                    m[root] = 1+max(l,r);
                    last = root;
                    root = NULL;
                    s.pop();
                }
            }
        }
        return true;
    }
};

// https://leetcode.com/problems/balanced-binary-tree/
