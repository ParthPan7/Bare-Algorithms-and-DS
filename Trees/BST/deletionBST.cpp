#include <iostream>

using namespace std;

class Node
{
public:
 int value;
 Node* right,*left;
 Node(int value)
 {
    this->value = value;
    this->right = this->left = nullptr;
 }
};

Node* insert(Node* root, int value)
{
	if (!root) { return new Node(value); }
        if (root->value >  value )
        {
	    root->left = insert(root->left,value);
        }
	else
	{
            root->right = insert(root->right, value);
	}
	return root;
}

void inorder(Node* root)
{
   if (!root) { return; }
   inorder(root->left);	
   cout << root->value <<" ";
   inorder(root->right);	
}
Node* deleteNode(Node* root, int key) {
    if (!root) { return root; }
    if (key < root->value)
    {
        root->left = deleteNode(root->left,key);
    }
    else if (key > root->value)
    {
        root->right = deleteNode(root->right,key);
    }
    else
    {
        if (!root->left)
        {
            Node* temp = root->right;
            root->right = nullptr;
            return temp;
        }
        else if(!root->right)
        {
            
            Node* temp = root->left;
            root->left = nullptr;
            return temp;
        }
        else
        {
            Node* successor = root->right;
            Node* successorParent = root;
            while (successor->left != nullptr)
            {
                successorParent = successor;
                successor = successor->left;
            }
            
            if (successorParent!=root)
            {
                successorParent->left = successor->right;
            }
            else
            {
                successorParent->right = successor->right;
            }
            root->value = successor->value;
            successor = nullptr;
        }
    }
    return root;
}
int main()
{
    int x[] = {5,3,6,2,4,7};
    Node* root = nullptr;
    int m;	
    for ( int ele:x  )
    {
//	cout << ele << " ";
	root = insert(root,ele);
    }			
    //inorder(root);
    cout << "enter node to delete";
    
    cout << endl;
    root = deleteNode(root,3);
    inorder(root);
    return 0;	
	
}




