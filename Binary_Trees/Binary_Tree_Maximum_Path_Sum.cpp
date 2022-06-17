class Solution {
public:
    int ans = INT_MIN;
    int solve(TreeNode* root){
        if(root==NULL) return 0;
        int l = solve(root->left);
        int r = solve(root->right);
        
        int curr = max({root->val,root->val+l,root->val+r,root->val+l+r});
        ans = max(ans,curr);
        
        return max({root->val,root->val+l,root->val+r});
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
};
