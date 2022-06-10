// BFS Iterative
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            vector<int> level;
            while(sz--){
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};

// DFS Recursive
class Solution {
public:
    
    void solve(TreeNode* root, int level, vector<vector<int>>& ans){
        if(root==NULL) return;
        if(level==ans.size()){
            vector<int> temp;
            temp.push_back(root->val);
            ans.push_back(temp);
        }
        else{
            ans[level].push_back(root->val);
        }
            
        solve(root->left,level+1,ans);
        solve(root->right,level+1,ans);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        solve(root,0,ans);
        return ans;
    }
};

// https://leetcode.com/problems/binary-tree-level-order-traversal/
