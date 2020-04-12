#include <iostream>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

int maxChildDiaOfBinaryTree(TreeNode* root, int& max) {
        if (!root) return 0;
        if (root->left == nullptr && root->right == nullptr) return 0;
        int len_left = 0;
        int len_right = 0;
        if (root->left) {
            len_left = 1 + maxChildDiaOfBinaryTree(root->left, max);
        }
        if (root->right) {
            len_right = 1 + maxChildDiaOfBinaryTree(root->right, max);
        }
        if( len_right + len_left > max)
            max = len_right + len_left;
        
        int ret = (len_right > len_left ? len_right : len_left);
        return ret;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int sumMax = 0;
        int maxChildDia = maxChildDiaOfBinaryTree(root, sumMax);
        return maxChildDia > sumMax ? maxChildDia : sumMax;
    }

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    cout << diameterOfBinaryTree(root) << endl;
    return 0;
}
