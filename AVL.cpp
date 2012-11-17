#include "AVL.h"
#include <iostream>

template <typename T>
BST<T>::BST() {
  root = 0;
}

template <typename T>
BST<T>::~BST() {
  
}


template <typename T>
bool BST<T>::find(T v) {
  Node<T>* temp = new Node<T>(v);
  root = temp;  
  return true;
}

template <typename T>
void BST<T>::insert(T v) {
  Node<T>* temp = new Node<T>(v);
  Node<T>** curr = &root;
  Node<T>** crit = 0;
  Node<T>** child = 0;
  Node<T>** childOfC = 0;
  Node<T>** endChild = 0;  
  int dira = 0;
  int dirb = 0;
  int dirc = 0;

  while ((*curr != 0) && (*curr->getValue != v)) {
   if ((*curr)->getBalance() != 0) {  
      crit = curr; }
   if (v < (*curr)->getValue) {
     curr = (*curr)->getLeftChild(); }
   else {
     curr = (*curr)->getRightChild(); }
   }   

  if (curr != 0) {
     (*curr)->setValue(v);
     return;
    }
  
  *curr = temp;
 
  if (*crit == 0) {
   endChild = &root; }
 
  else  {
    if (v = (*crit)->getValue()) {
     dira = 0;
     *child = curr; }
    else if ( v < (*crit)->getValue()) {
     dira = -1;
     *child = &((*crit)->getLeftChild()); }
    else {
     dira = 1;
     *child = &((*crit)->getRightChild()); }
   
    if ((*crit)->getBalance != dira) {
       (*crit)->setBalance(0);
       endChild = curr;
     }
    else {
      if (v = (*child)->getValue()) {
        dirb = 0;
        *childOfC = child; }
      else if ( v < (*child)->getValue()) {
        dirb = -1;
        *childOfC = &((*child)->getLeftChild()); }
      else {
         dirb = 1;
        *childOfC = &((*child)->getRightChild()); }
      
      if (dirb = dira) {
         (*crit)->setBalance(0);
         endChild = childOfC;
        rotate(crit , -dira);
       }
      else {
        if (v = (*childOfC)->getValue()) {
          dirc = 0;
          *endChild = childOfC; }
        else if ( v < (*childOfC)->getValue()) {
          dirc = -1;
          *endChild = &((childOfC)->getLeftChild()); }
        else { 
          dirc = 1;
          *endChild = &((childOfC)->getRightChild()); }
            
         if (dirc = dirb) {
            (*crit)->setBalance(0);
            (*child)->setBalance(dira); }
         else if (dirc = (-dirb)) {
           (*crit)->setBalance(dirb); }
         else {
          (*crit)->setBalance(0);
          rotate(*child , (-dirb));
          rotate(*crit , (-dira)); }  
       }  //close third else
     }  //close second else
   }  //close 1st else
  
}

template <typename T>
void BST<T>::remove(T v) {

  Node<T>** curr = &root;
  Node<T>** succ = 0;
  while ( curr != 0) {
   if (v < (*curr)->getValue()) {
    curr = &((*curr)->getLeftChild()); }
   else { 
     curr = &((*curr)->getRightChild()) ; }
   } //close while
  
  if (curr == 0) {
     return; }

  if ((*curr)->getRightChild() == 0) {
    curr = &((*curr)->getLeftChild()); }
  else if ((*curr)->getLeftChild() == 0 ) {
     curr = &((*curr)->getRightChild()); }
  else {
   succ = &((*curr)->getRightChild());
   while ((*succ)->getLeftChild() != 0) {
    succ = ((*succ)->getLetChild()); }
   curr = succ;
   succ = ((*succ)->getRightChild());
  // succ
  }


 // Node<T>* temp = new Node<T>(v);

 // root = temp;
}

template <typename T>
void BST<T>::print() {
  traversalPrint(root);
}

template <typename T>
void BST<T>::traversalPrint(Node<T>* root) {
  if(root != 0) {
    traversalPrint(root->getLeftChild());
    std::cout << root->getValue() << std::endl;
    traversalPrint(root->getRightChild());
  }
}


template <typename T>
void BST<T>::rotate(Node<T>** c, int d) {
 if (d == -1) {
  c = &((*c)->getRightChild()); 
  (*c)->setRightChild(&(*c)->getRightChild(->getLeftChild()));
  (*c)->getRightChild(setLeftChild(c));
  } 
 else {
  c = &((*c)->getLeftChild()); 
  (*c)->setLeftChild(&(*c)->getLeftChild(->getRightChild()));
  (*c)->getLeftChild(setRightChild(c));
 }
}

//template class BST<int>;
//template class BST<double>;
//template class BST<std::string>;
