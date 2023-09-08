For eg.   
            
            Given BST                 Level Order Traversal        Level
                1           ----->       1                      -    0
              /    \                         
            2       3       ----->       2   3                  -    1
          /  \     /  \
        4     5   6    7    ----->       4   5   6   7          -    2

C++ Code For Level Order Traversal
vector<vector<int>> levelOrder(TreeNode* root) {
        //If Tree is empty print nothing.
        if(root == NULL){
            return ans;
        }
        // Create a queue to use its FIFO property.
        queue<TreeNode*> q;
        // Initialise queue with root and null
        q.push(root);
        // Here NULL indicates the end of level.
        q.push(NULL);
        while(!q.empty()){
            TreeNode* node = q.front();
            // Starting from the front of the q, pop it from the queue and check if it is not NULL.
            q.pop();
            if(node != NULL){
                // Print the value of node which is popped
                cout<<node->val<<" ";
                // if the popped node's left child is not NULL the push it at the end of the queue
                if(node->left)
                q.push(node->left);
                // if the popped node's right child is not NULL the push it at the end of the queue
                if(node->right)
                q.push(node->right);
            }
              // If the popped node is NULL i.e, another level will start if the queue is still not empty. And push this NULL again at the end of the queue
            else if(!q.empty()){
                q.push(NULL);
            }
        }
    }
