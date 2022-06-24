class Solution {
public:
    TreeNode* solve(int is, int ie, int pe, vector<int>& pos, unordered_map<int,int>& m){
        if(is>ie) return NULL;
        TreeNode* root = new TreeNode(pos[pe]);
        int ind = m[pos[pe]];
        int nums_right = ie-ind;
        root->left = solve(is,ind-1,pe-nums_right-1,pos,m);
        root->right = solve(ind+1,ie,pe-1,pos,m);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[inorder[i]] = i;
        }
        return solve(0,n-1,n-1,postorder,m);
    }
};

class Solution {
public:
    int pe=0;
    TreeNode* solve(int is, int ie, vector<int>& pos, unordered_map<int,int>& m){
        if(is>ie) return NULL;
        TreeNode* root = new TreeNode(pos[pe]);
        int ind = m[pos[pe]];
        pe--;
        root->right = solve(ind+1,ie,pos,m);
        root->left = solve(is,ind-1,pos,m);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[inorder[i]] = i;
        }
        pe = n-1;
        return solve(0,n-1,postorder,m);
    }
};

// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
