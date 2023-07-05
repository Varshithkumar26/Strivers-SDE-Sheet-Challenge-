/*****************************************************

    Following is the Binary Tree node structure:
    
    class BinaryTreeNode {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/

bool f(BinaryTreeNode<int>* root1,BinaryTreeNode<int>* root2)
{
    if(!root1)
      return root2==NULL;
    if(!root2)
      return root1==NULL;
    
    if(root1->data!=root2->data)
      return false;
    
    bool left=f(root1->left,root2->right);
    bool right=f(root1->right,root2->left);

    if(left&&right)
      return true;
    return false;

}

bool isSymmetric(BinaryTreeNode<int>* root)
{
    // Write your code here. 
    return f(root,root);   
}
