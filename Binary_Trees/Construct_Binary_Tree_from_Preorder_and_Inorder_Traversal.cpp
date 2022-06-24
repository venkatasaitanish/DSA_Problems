class Solution {
public:
    TreeNode* solve(int is, int ie, int ps, vector<int>& pre, unordered_map<int,int>& m){
        if(is>ie) return NULL;
        TreeNode* root = new TreeNode(pre[ps]);
        int ind = m[pre[ps]];
        int nums_left = ind-is;
        root->left = solve(is,ind-1,ps+1,pre,m);
        root->right = solve(ind+1,ie,ps+nums_left+1,pre,m);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[inorder[i]] = i;
        }
        return solve(0,n-1,0,preorder,m);
    }
};

// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
