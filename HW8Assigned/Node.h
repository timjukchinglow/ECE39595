#ifndef NODE_H_
#define NODE_H_
#include <iostream>

template <class T> class Node { 
private:
   T data;
   Node* left = nullptr;
   Node* right = nullptr;
public:
   Node( );
   Node(T val);
   void print( ) const;

   Node<T>* insertNode(T n);
};

template <class T> Node<T>::Node( ) { }

template <class T> Node<T>::Node(T val) {
   data = val;
}

template <class T> void Node<T>::print( ) const {
   if (this->left != nullptr) {
      this->left->print( );
   }
   std::cout << data << " ";
   if (this->right != nullptr) {
      this->right->print( );
   }
}

template <class T> Node<T>* Node<T>::insertNode(T n) {
   if (this->data == n) return this;
   if (n < this->data) {
      if (left != nullptr) return left->insertNode(n); 
      else {
         left = new Node(n);
         return left;
      }
   }
   if (n > this->data) {
      if (right != nullptr) return right->insertNode(n); 
      else {
         right = new Node<T>(n);
         return left;
      }
   }
   return nullptr;
}

#endif /* NODE_H_ */
