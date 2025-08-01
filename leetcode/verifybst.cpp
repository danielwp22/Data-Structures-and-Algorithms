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

 // Breadth first search .. 
 // Start at root node
 // For nodes in this layer, do any of them have children? 
 // Lets push these children into a new array. 
 // Go through these children
 // Are all of these values smaller than the original nodeS? 
 // Original node -> is it bigger than all of the children? 
 // 5
 //4 6
 //  3 7
 
class Solution {
public:

    std::vector<int> checkValues(TreeNode* root, std::vector<int> list){
        if (root == NULL){
            return list;
        }
        list = checkValues(root->left, list);
        list.push_back(root->val);
        list = checkValues(root->right, list);
        return list;

    }

    bool isValidBST(TreeNode* root) {      
        if (root == NULL){
            return true;
        }
        std::vector<int> empty_list = {};
        std::vector<int> sorted_list = checkValues(root, empty_list);
        for (int i=0; i<sorted_list.size()-1; i++){
            if (sorted_list[i] >= sorted_list[i+1]){
                return false;
            } 
        }
        return true;
    }

    
    // std::vector<int> checkValues(TreeNode* root, std::vector<int> list){
    //     if (root == NULL){
    //         return list;
    //     }
    //     list = checkValues(root->left, list);
    //     list.push_back(root->val);
    //     list = checkValues(root->right, list);
    //     return list;

    // }

    // bool isValidBST(TreeNode* root) {        
    //     if (root == NULL){
    //         return true;
    //     }
    //     if (root->left == NULL && root->right == NULL){
    //         return true;
    //     }

    //     if (root->left == NULL){
    //         if (root->right->val > root->val){
    //             if (isValidBST(root->left)&&isValidBST(root->right)){
    //                 return true;
    //             }
    //             else{
    //                 return false;
    //             }
    //         }
    //         else{
    //             return false;
    //         }
    //     }

    //     if (root->right == NULL){
    //         if (root->left->val < root->val){
    //             if (isValidBST(root->left)&&isValidBST(root->right)){
    //                 return true;
    //             }
    //             else{
    //                 return false;
    //             }
    //         }
    //         else{
    //             return false;
    //         }
    //     }

    //     std::vector<int> starting_list = {};
    //     std::vector<int> sorted_list = checkValues(root, starting_list);

    //     for (int i=0; i<sorted_list.size()-1; i++){
    //         if (sorted_list[i] > sorted_list[i+1]){
                
    //             return false;
    //         } 
    //     }

    //     if ((root->left->val < root->val) && (root->right->val > root->val)){
    //         if (isValidBST(root->left)&&isValidBST(root->right)){
    //             return true;
    //         }
    //         else{
    //             return false;
    //         }
    //     }
    //     else{
    //         return false;
    //     }
    // }
};