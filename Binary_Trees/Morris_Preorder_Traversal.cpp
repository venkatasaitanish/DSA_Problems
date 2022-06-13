class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;
        while(curr!=NULL){
            if(curr->left==NULL){ // if left child is null, push into ans and move right
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* prev = curr->left;
                while(prev->right && prev->right!=curr){ // finding rightmost child for curr left child
                    prev = prev->right;
                }
                if(prev->right==NULL){ // if rightmost child doesn't point to curr, push curr into ans, make a thread to curr and move left
                    ans.push_back(curr->val);
                    prev->right = curr;
                    curr = curr->left;
                }
                else{ // if righmost child points to curr, remove thread and move right
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};
// Time complexity: O(n)
// Space complexity: O(1)

// https://leetcode.com/problems/binary-tree-preorder-traversal/
