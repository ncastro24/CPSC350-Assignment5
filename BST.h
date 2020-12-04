//binary search tree header file
#include "node.h"
#include <iostream>
#include <fstream>
using namespace std;

template <class type>
class BST{
public:
  BST();
  ~BST();

  bool searchNode(int k);
  void insertNode(int k, type node);
  bool deleteNode(int k);
  type returnData(int k);

  bool isEmpty();
  node<type> *min(); //get the minimum
  node<type> *max(); //get the maximum

  void printOrder(node<type> *node);
  void printTree(); //print the bst

  void printPreorder(node<type> *node);
  void preorderPrint();

  void printPreorderFile(node<type> *node, ofstream& out);
  void preorderFile(ofstream& out);

  node<type> *getSuccessor(node<type> *d);

private:
  node<type> *root;
};

//constructor
template <class type>
BST<type>::BST(){
  root = NULL;
}

//destructor
template <class type>
BST<type>::~BST(){
  delete root;
}

//checking if tree is empty
template <class type>
bool BST<type>::isEmpty(){
  if(root == NULL){
    return true;
  }
  else{
    return false;
  }
}

//return node w lowest key value
template <class type>
node<type>* BST<type>::min(){
  node<type> *curr = root;
  if(curr == NULL){ //if tree is empty
    return NULL;
  }
  while(curr->left != NULL){
    curr = curr->left;
  }
  return curr;
}

//return node w greater key value
template <class type>
node<type>* BST<type>::max(){
  node<type> *curr = root;
  if(curr == NULL){ //if tree is empty
    return NULL;
  }
  while(curr->right != NULL){
    curr = curr->right;
  }
  return curr;
}

//print tree in order
template <class type>
void BST<type>::printOrder(node<type> *node){
  if(node == NULL){
    return;
  }
  printOrder(node->left);
  cout << node->data << endl;
  printOrder(node->right);
}

//calls recPrint on root
template <class type>
void BST<type>::printTree(){
  printOrder(root);
}

//prints the tree pre order
template <class type>
void BST<type>::printPreorder(node<type> *node){
  if(node == NULL){
    return;
  }
  cout << node->data << endl;
  printPreorder(node->left);
  printPreorder(node->right);
}

//calls printPreorder on root
template <class type>
void BST<type>::preorderPrint(){
  printPreorder(root);
}

//prints tree to file preorder
template <class type>
void BST<type>::printPreorderFile(node<type> *node, ofstream& out){
  if(node == NULL){
    return;
  }
  out << node->data << endl;
  printPreorderFile(node->left, out);
  printPreorderFile(node->right, out);
}

//calls printPreorderToFile on root
template <class type>
void BST<type>::preorderFile(ofstream& out){
  printPreorderFile(root, out);
}

//insert object into tree & assign it to a key
template <class type>
void BST<type>::insert(int k, type node){
  node<type> *temp = new node<type>(node, k);

  if(root == NULL){ //if empty tree
    root = temp;
  }
  else{ //if not empty... find location
    node<type> *curr = root;
    node<type> *parent = NULL;
    while(curr != NULL){
      parent = curr;
      if(temp->key < curr->key){
        curr = curr->left; //going to left child
        if(curr == NULL){ //if found insertion point
          parent->left = temp;
          break;
        }
      }
      else{
        curr = curr->right;//going to right child
        if(curr == NULL){ //if found insertion point
          parent->right = temp;
          break;
        }
      }
    }
  }
}

//return bool if there is node w certain key in tree
template <class type>
bool BST<type>::searchNode(int k){
  if(root == NULL){ //if empty tree
    return false;
  }
  else{ //if tree is not empty
    node<type> *curr = root;
    while(curr->key != k){
      if(k < curr->key){/ /going left
        curr = curr->left;
      }
      else{ //going right
        curr = curr->right;
      }
      if(curr == NULL){ //if value couldnt be found when end of tree is reached
        return false;
      }
    }
  }
  return true;
}

//return data of node when given key
template <class type>
type BST<type>::returnData(int k){
  node<type> *curr = root;
  while(curr->key != k){
    if(k < curr->key){ //going left
      curr = curr->left;
    }
    else{ //going right
      curr = curr->right;
    }
  }
  return curr->data;
}

//deletes node w certain key from tree & return bool
template <class type>
bool BST<type>::deleteNode(int k){ //return true if deleted, false if key doesnt exist
  if(root == NULL){ //if the tree is empty
    return false;
  }
  else{ //if not empty
    node<type> *curr = root;
    node<type> *parent = root;
    bool isLeft = true; //if the node is left child
    while(curr->key != k){
      parent = curr;
      if(k < curr->key){ //going left
        isLeft = true;
        curr = curr->left;
      }
      else{ //going right
        isLeft = false;
        curr = curr->right;
      }
      if(curr == NULL){ //if value not found
        return false;
      }
    }
    //if node that needs to be deleted has been found
    if(curr->left == NULL && curr->right == NULL){ //if no children
      if(curr == root){
        root = NULL;
      }
      else if(isLeft){
        parent->left = NULL;
      }
      else{
        parent->right = NULL;
      }
      delete curr;
    }
    else if(curr->right == NULL){ //if has left child
      if(curr == root){
        root = curr->left;
      }
      else if(isLeft){
        parent->left = curr->left;
      }
      else{
        parent->right = curr->left;
      }
      delete curr;
    }
    else if(curr->left == NULL){ //if has right child
      if(curr == root){
        root = curr->right;
      }
      else if(isLeft){
        parent->left = curr->right;
      }
      else{
        parent->right = curr->right;
      }
      delete curr;
    }
    else{ //if node has 2 children
      node<type> *successor = getSuccessor(curr);
      if(curr == root){
        root = successor;
      }
      else if(isLeft){
        parent->left = successor;
      }
      else{
        parent->right = successor;
      }
      successor->left = curr->left;
      delete curr;
    }
  }
  return true;
}

//find node's successor
template <class type>
node<type>* BST<type>::getSuccessor(node<type> *d){
  node<type> *sp = d; //sp = successor's parent
  node<type> *successor = d;
  node<type> *curr = d->right; //start right

  while(curr !=NULL){
    sp = successor;
    successor = curr;
    curr = curr->left;
  }

  if(successor != d->right){ //if successor descendant of right child
    sp->left = successor->right;
    successor->right = d->right;
  }
  return successor;
}
