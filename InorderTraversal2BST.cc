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
    
    void inorderTraversal(TreeNode* root, vector<int>& elements) {
        if (!root) return;
        inorderTraversal(root->left, elements);
        elements.push_back(root->val);
        inorderTraversal(root->right, elements);
    }
    
    vector<int> merge(vector<int>& first, vector<int>& second) {
        int i = 0;
        int j = 0;
        vector<int> result;
        while(i < first.size() && j < second.size()) {
            if (first[i] > second[j]) {
                result.push_back(second[j]);
                ++j;
            }
            else {
                result.push_back(first[i]);
                ++i;
            }
        }
        while(i < first.size()) {
            result.push_back(first[i]);
        }
        
        while(j < second.size()) {
            result.push_back(second[j]);
        }
        
        return result;
    }
    

       
    void inorderTraversal(TreeNode* root) {
        if (root == nullptr) return;
        
        stack<TreeNode*> stack;
        //vector<int> results;
        
        TreeNode* curr = root;    
        
        while(curr != nullptr || !stack.empty()) {
            
            while(curr) {
                stack.push(curr);
                curr = curr->left;
            }

            curr = stack.top();
            stack.pop();
            
            //results.push_back(curr->val);
            //cout << curr->val << " ";
            
            curr = curr->right;
        }
    }
    
    void inorderTraversal(TreeNode* root1, TreeNode* root2, vector<int>& result) {
        stack<TreeNode*> stack1, stack2;
        
        TreeNode* curr1 = root1;
        TreeNode* curr2 = root2;
        bool firstSturn = true;
        bool secondSturn = true;
        while((curr1 != nullptr || !stack1.empty()) && (curr2 != nullptr || !stack2.empty())) {
            if (firstSturn) {
                while(curr1) {
                    stack1.push(curr1);
                    curr1 = curr1->left;
                }
                
                curr1 = stack1.top();
                stack1.pop();
            }
            
            if (secondSturn) {
                while(curr2) {
                    stack2.push(curr2);
                    curr2 = curr2->left;
                }
            
                curr2 = stack2.top();
                stack2.pop();
            }
            
            if (curr1 && curr2) {
              if (curr1->val < curr2->val) {
                result.push_back(curr1->val);
                secondSturn = false;
                firstSturn = true;
                curr1 = curr1->right;
              }
              else {
                firstSturn = false;
                secondSturn = true;
                result.push_back(curr2->val);
                curr2 = curr2->right;
              }
            }
        }
        
        if (root2 && root1 && curr2) {
            result.push_back(curr2->val);
            curr2 = curr2->right;
        }
        
        if (root1 && root2 && curr1) {
            result.push_back(curr1->val);
            curr1 = curr1->right;
        }
        
        while(curr1 != nullptr || !stack1.empty()) {      
            while(curr1) {
                stack1.push(curr1);
                curr1 = curr1->left;
            }
            curr1 = stack1.top();
            stack1.pop();
    
            result.push_back(curr1->val);

            curr1 = curr1->right;
        }
        
        
        while(curr2 != nullptr || !stack2.empty()) {      
            while(curr2) {
                stack2.push(curr2);
                curr2 = curr2->left;
            }
            curr2 = stack2.top();
            stack2.pop();
    
            result.push_back(curr2->val);

            curr2 = curr2->right;
        }
    }
    
    
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        //inorder traversal as well as merge two sorted
        //vector<int> elements1;
        //vector<int> elements2;
        
        //inorderTraversal(root1, elements1);
        //inorderTraversal(root2, elements2);
        
        vector<int> result;
        inorderTraversal(root1,root2, result);
        return result;
        //return merge(elements1, elements2);
    }
};