//Recursive
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int lh = maxDepth(root->left)+1;
        int rh = maxDepth(root->right)+1;
        return max(lh,rh);
    }
};

//Iterative
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while(!q.empty()){
            int sz = q.size();
            ans++;
            while(sz--){
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return ans;
    }
};

// https://leetcode.com/problems/maximum-depth-of-binary-tree/
