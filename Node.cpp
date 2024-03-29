#include <string>
#include "Node.h"

template <typename T>
Node<T>::Node(T v) {
  value = v;
  balance = 0;
  leftChild = 0;
  rightChild = 0;
}

template <typename T>
T Node<T>::getValue() {
  return value;
}

template <typename T>
int Node<T>::getBalance() {
 return balance;
 }

template <typename T>
void Node<T>::setBalance(int b) {
  balance = b;
 }

template <typename T>
void Node<T>::setValue(T v) {
  value = v;
 }



template <typename T>
Node<T>*& Node<T>::getLeftChild() {
  return leftChild;
}

template <typename T>
void Node<T>::setLeftChild(Node<T>& lc) {
  leftChild = &lc;
}

template <typename T>
Node<T>*& Node<T>::getRightChild() {
  return rightChild;
}

template <typename T>
void Node<T>::setRightChild(Node<T>& rc) {
  rightChild = &rc;
}

template class Node<int>;
template class Node<double>;
template class Node<std::string>;

