int sum_at_kth_level(Node* root, int k){
    if(root == NULL){
        return 0;
    }
    queue<Node*> q;
    int level = 0;
    int sum = 0;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node * node = q.front();
        q.pop();
        if(node != NULL){
            if(level == k){
                sum += node->data;
            }
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
            level++;
        }
    }
    return sum;
}
