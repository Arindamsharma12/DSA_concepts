class solution{
  public:
      int count_nodes(TreeNode* root){
            if(root == NULL) return 0;
            int leftCount = count_nodes(root->left);
            int rightCount = count_nodes(root->right);
            return leftCount + rightCount + 1;
      }
};
