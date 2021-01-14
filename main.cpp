/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void AddTree(int startIndex, int endIndex, vector<int>& nums, bool isLeft, TreeNode *root) {
        if (startIndex <= endIndex) {
            int mid = startIndex + ((endIndex - startIndex) / 2);
            
            int val = nums[mid];
            
            TreeNode *newNode = new TreeNode(val);
            
            if (isLeft) {
                root->left = newNode;
            }
            else {
                root->right = newNode;
            }
            
            AddTree(startIndex, mid - 1, nums, true, newNode);
            AddTree(mid + 1, endIndex, nums, false, newNode);
        }   
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *root = nullptr;
        
        if (nums.size() > 0) {
            int mid = (nums.size() - 1) / 2;
            
            int val = nums[mid];
            root = new TreeNode(val);
            
            AddTree(0, mid - 1, nums, true, root);
            AddTree(mid + 1, nums.size() - 1, nums, false, root);            
        }
        
        return root;
    }
};
