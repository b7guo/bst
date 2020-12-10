#include <iostream>

#include <iostream>

using namespace std;

struct BSTNode /// BinarySearchTreeNode

{
    
    int value;
    
    BSTNode* left = NULL;
    
    BSTNode* right = NULL;
    
};

class BST // BinarySearchTree

{
    
private:
    
    BSTNode* root ;
    
public:
    
    BST (){ root = NULL;}
    
    void insert(int value)
    
    {
        
        BSTNode* t = new BSTNode;
        
        BSTNode* parent;
        
        t->value = value;
        
        t->left = NULL;
        
        t->right = NULL;
        
        parent = NULL;
        
        // new tree?
        
        if (root==NULL) root = t;
        
        else
            
        {
            
            // leaf nodes
            
            BSTNode* curr;
            
            curr = root;
            
            // Node's parent
            
            while (curr)
                
            {
                
                parent = curr;
                
                if (t->value > curr->value) curr = curr->right;
                
                else curr = curr->left;
                
            }
            
            if (t->value < parent->value)
                
                parent->left = t;
            
            else
                
                parent->right = t;
            
        }
        
    }
    
    
    void remove(int value)
    
    {
        
        //Locate the element
        
        bool found = false;
        
        if (root==NULL)
            
        {
            
            cout << " This Tree is empty! " << endl;
            
            return;
            
        }
        
        BSTNode* curr;
        
        BSTNode* parent;
        
        curr = root;
        
        parent = curr;
        
        while (curr != NULL)
            
        {
            
            if (curr->value == value)
                
            {
                
                found = true;
                
                break;
                
            }
            
            else
                
            {
                
                parent = curr;
                
                if (value>curr->value) curr = curr->right;
                
                else curr = curr->left;
                
            }
            
        }
        
        if (!found)
            
        {
            
            cout << " Data not found! " << endl;
            
            return;
            
        }
        
        // 3 cases :
        
        // 1. We're removing a leaf node
        
        // 2. We're removing a node with a single child
        
        // 3. we're removing a node with 2 children
        
        // Node with single child
        
        if ((curr->left == NULL && curr->right != NULL) || (curr->left != NULL
                                                            
                                                            && curr->right == NULL))
            
        {
            
            if (curr->left == NULL && curr->right != NULL)
                
            {
                
                if (parent->left == curr)
                    
                {
                    
                    parent->left = curr->right;
                    
                    delete curr;
                    
                }
                
                else
                    
                {
                    
                    parent->right = curr->right;
                    
                    delete curr;
                    
                }
                
            }
            
            else // left child present, no right child
                
            {
                
                if (parent->left == curr)
                    
                {
                    
                    parent->left = curr->left;
                    
                    delete curr;
                    
                }
                
                else
                    
                {
                    
                    parent->right = curr->left;
                    
                    delete curr;
                    
                }
                
            }
            
            return;
            
        }
        
        //We're looking at a leaf node
        
        if (curr->left == NULL && curr->right == NULL)
            
        {
            
            if (parent->left == curr) parent->left = NULL;
            
            else parent->right = NULL;
            
            delete curr;
            
            return;
            
        }
        
        //Node with 2 children
        
        // replace node with smallest value in right subtree
        
        if (curr->left != NULL && curr->right != NULL)
            
        {
            
            BSTNode* chkr;
            
            chkr = curr->right;
            
            if ((chkr->left == NULL) && (chkr->right == NULL))
                
            {
                
                curr = chkr;
                
                delete chkr;
                
                curr->right = NULL;
                
            }
            
            else // right child has children
                
            {
                
                //if the node's right child has a left child
                
                // Move all the way down left to locate smallest element
                
                if ((curr->right)->left != NULL)
                    
                {
                    
                    BSTNode* lcurr;
                    
                    BSTNode* lcurrp;
                    
                    lcurrp = curr->right;
                    
                    lcurr = (curr->right)->left;
                    
                    while (lcurr->left != NULL)
                        
                    {
                        
                        lcurrp = lcurr;
                        
                        lcurr = lcurr->left;
                        
                    }
                    
                    curr->value = lcurr->value;
                    
                    delete lcurr;
                    
                    lcurrp->left = NULL;
                    
                }
                
                else
                    
                {
                    
                    BSTNode* tmp;
                    
                    tmp = curr->right;
                    
                    curr->value = tmp->value;
                    
                    curr->right = tmp->right;
                    
                    delete tmp;
                    
                }
                
            }
            
            return;
            
        }
        
    }
    
    /// ------------------------------------------
    
    BSTNode* finMin() const
    
    {
        
        BSTNode* current = root;
        
        if (root == NULL )
            
            return NULL;
        
        while (current->left != NULL) {
            
            current = current->left;
            
        }
        
        return(current);
        
    }
    
    /// ------------------------------------------
    
    BSTNode* finMax() const
    
    {
        
        BSTNode* current = root;
        
        if (root == NULL )
            
            return NULL;
        
        while (current->right != NULL) {
            
            current = current->right;
            
        }
        
        return(current);
        
    }
    
    /// ------------------------------------------
    
    void preOrderTraversal() const
    
    {
        
        cout << "preOrderTraversal: ";
        
        preOrderTraversal(root);
        
        cout << endl;
        
    }
    
    void preOrderTraversal(BSTNode* node) const
    
    {
        
        if (node != NULL) {
            
            cout << node->value << " ";
            
            preOrderTraversal(node->left);
            
            preOrderTraversal(node->right);
            
        }
        
    }
    
    /// ------------------------------------------
    
    void inOrderTraversal() const
    
    {
        
        cout << "inOrderTraversal: ";
        
        inOrderTraversal(root);
        
        cout << endl;
        
    }
    
    void inOrderTraversal(BSTNode* node) const
    
    {
        
        if (node != NULL) {
            
            inOrderTraversal(node->left);
            
            cout << node->value << " ";
            
            inOrderTraversal(node->right);
            
        }
        
    }
    
    /// ------------------------------------------
    
    void postOrderTraversal() const
    
    {
        
        cout << "postOrderTraversal: ";
        
        postOrderTraversal(root);
        
        cout << endl;
        
    }
    
    void postOrderTraversal(BSTNode* node) const
    
    {
        
        if (node != NULL) {
            
            postOrderTraversal(node->left);
            
            postOrderTraversal(node->right);
            
            cout << node->value << " ";
            
        }
        
    }
    
};

const int SIZE =15;

int main()

{
    
    BST bst;
    
    int values[SIZE] = {5, 2, 12, -4, 3, 9, 21, -7, 19, 25, -8, -6, -4, 3, 12};
    
    for (int i = 0; i < SIZE; i++)
        
        bst.insert(values[i]);
    
    bst.preOrderTraversal(); /// should be 5 2 -4 -7 -8 -6 3 12 9 21 19 25
    
    bst.inOrderTraversal(); /// should be -8 -7 -6 -4 2 3 5 9 12 19 21 25
    
    bst.postOrderTraversal(); /// should be -8 -6 7 -4 3 2 9 19 25 21 12 5
    
    bst.remove(3); /// Node 3 has 0 children --> delete the node and make it NULL;
    
    bst.remove(-4); /// Node -4 has 1 children --> Link parent to child --> delete the node and make it NULL;
    
    bst.remove(12); /// Node 12 has 2 children --> findMin for the right subtree --> swap value -> delete
    
    bst.preOrderTraversal(); /// should be 5 2 -7 -8 -6 19 9 21 25
    
    bst.inOrderTraversal(); /// should be -8 -7 -6 2 5 9 19 21 25
    
    bst.postOrderTraversal(); /// should be -8 -6 7 2 9 25 21 19 5
    
    return 0;
    
}
