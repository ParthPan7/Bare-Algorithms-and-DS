#include <iostream>
#include <vector>
using namespace std;
class Node
{
public:
 int value;
 Node *left,*right;
 Node(int value)
 {
   this->value = value;
   this->left = this->right = nullptr;
 }

};

Node* insertBST(Node* root, int data)
{
  if (!root) { return new Node(data); }
  
  else if (root->value >= data )
  {
    root->left = insertBST(root->left, data);
  }
  else 
  {
    root->right = insertBST(root->right, data);
  }
  return root;
}


void inorder(Node* root)
{
   if (!root) { return; }
   inorder(root->left);
   cout << root->value << " "<<endl;
   inorder(root->right);
}

int main()
{
  
   int nums[] = {1,35,96,109};
   Node* root=nullptr;
   for (int ele: nums)
   {
    root =  insertBST(root,ele);
   }
   inorder(root);
   return 0;
}


