#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
  //first check root is empty or not
  if(root !=NULL){
    traverseInOrder(root->left);
    cout<<root->key<<" ";
    traverseInOrder(root->right);
  }


}

// Insert a node
struct node *insertNode(struct node *node, int key) {
    // If the tree is empty, create a new node
    if (node == NULL) {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->key = key;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    // if the tree is not empty, find the place to put the key
    if (node->key>key) {
        node->left = insertNode(node->left, key);
    } else if (node->key<key) {
        node->right = insertNode(node->right, key);
    }
    // Return the root of the tree
    return node;

  }

  //create a new function to get minimum value node
  struct node *minValueNode(struct node *node) {
    struct node *current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}
// Deleting a node
struct node *deleteNode(struct node *root, int key) {


// If the tree is empty
    if (root == NULL) {
        return NULL;
    }

    // Traverse the tree to find the node to be deleted
    if (root->key>key) {
        root->left = deleteNode(root->left, key);
    } else if (root->key<key) {
        root->right = deleteNode(root->right, key);



    } else {
        // Node found, determine the case of deletion
        if (root->left == NULL && root->right == NULL) {
            // Case 1: Node has no children, simply delete it
            free(root);
            return NULL;
      } 
        else if (root->left == NULL) {
            // Case 2: Node has one child (right), replace it with the child
            struct node *temp = root->right;
            free(root);
            return temp;
      } else if (root->right == NULL) {

            // Case 2: Node has one child (left), replace it with the child
            struct node *temp = root->left;
            free(root);
            return temp;
      } else {

            // Case 3: Node has two children, replace it with the successor node
            struct node *temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    // Return the root of the modified tree
    return root;  

  



}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}