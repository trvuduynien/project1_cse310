#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>
using namespace std;

// Node template
template <typename T>
class Node
{
private:
  T data;
  Node<T> *next;

  Node() : next(nullptr) {} //Initialize next in constructor

public:
  // Constructor
  Node();
  Node(T data);
  ~Node();

  // Getters and Setters
  T getData();
  void setData(T dataNew);
  Node<T> *getNext();
  void setNext(Node<T> *dataNext);
};

// Constructor
template <typename T>
Node<T>::Node() : data(T()), next(nullptr) {}

template <typename T>
Node<T>::Node(T data) : data(data), next(nullptr) {}

// Destructor
template <typename T>
Node<T>::~Node()
{
  next = nullptr;
  data = T();
}

// Get and set method
template <typename T>
T Node<T>::getData()
{
  return data;
}

template <typename T>
void Node<T>::setData(T dataNew)
{
  data = dataNew;
}

template <typename T>
Node<T> *Node<T>::getNext()
{
  return next;
}

template <typename T>
void Node<T>::setNext(Node<T> *dataNext)
{
  next = dataNext;
}

// LinkedList template
template <typename T>
class LinkedList
{
private:
  Node<T> *head;
  int size;

public:
  // Constructor
  LinkedList();
  // Destructor
  ~LinkedList();

  // Add and remove methods
  void AddNode(T data);
  T RemoveNode();

  // Other methods
  Node<T> *Find(T data);
  T Retrieve(int index);
  int Length();
};

// Constructor
template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), size(0) {}

// Destructor
template <typename T>
LinkedList<T>::~LinkedList()
{
  while (head != nullptr)
  {
    Node<T> *temp = head->getNext();
    delete head;
    head = temp;
  }
}

// Add to the head, tail, or at a random index
template <typename T>
void LinkedList<T>::AddNode(T data)
{
  if (this->head == nullptr)
  {
    this->head = new Node<T>(data);
  }
  else
  {
    Node<T> *temp = this->head;
    for (int i = 0; i < this->size - 1; i++)
    {
      temp = temp->getNext();
    }
    Node<T> *node_to_add = new Node<T>(data);
    temp->setNext(node_to_add);
  }
  this->size++;
}

template <typename T>
T LinkedList<T>::RemoveNode()
{
  if (this->head == nullptr)
  {
    throw std::out_of_range("Attempted to remove from an empty list");
  }

  if (this->size == 1)
  {
    T temp_data = this->head->getData();
    delete this->head;
    this->head = nullptr;
    this->size--;
    return temp_data;
  }

  Node<T> *temp = this->head;
  for (int i = 0; i < this->size - 2; i++)
  {
    temp = temp->getNext();
  }
  T temp_data = temp->getNext()->getData();
  delete temp->getNext();
  temp->setNext(nullptr);

  this->size--;
  return temp_data;
}

template <typename T>
Node<T> *LinkedList<T>::Find(T data)
{
  Node<T> *temp = this->head;
  for (int i = 0; i < this->size; i++)
  {
    if (temp->getData() == data)
    {
      return temp;
    }
    temp = temp->getNext();
  }
  return nullptr;
}

template <typename T>
int LinkedList<T>::Length()
{
  return this->size;
}

template <typename T>
T LinkedList<T>::Retrieve(int index)
{
  if ((index < 0) || (index >= this->size))
  {
    throw out_of_range("OUT OF RANGE");
  }

  Node<T> *temp = this->head;
  for (int i = 0; i < index; i++)
  {
    temp = temp->getNext();
  }

  return temp->getData();
}

#endif