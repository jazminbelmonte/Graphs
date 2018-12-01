#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <fstream>
#include "linked_list.h"
#include "linked_queue.h"

template <typename T>
class Graph{
public:
  Graph(int sz): size(sz), adjList(new LinkedList<int>[sz]()), vertices(new T[sz]){}
  ~Graph() { clear(); }

  bool empty() const { return size == 0; }

  T* getVertices() { return vertices; }

  LinkedList<int>* getAdjList() { return adjList; }

  void clear(){
    for (int index = 0; index < size; index++) {
      adjList[index].destroy();
    }

    size = 0;
  }

  void print() const {
    for (int index = 0; index < size; index++) {
      std::cout << index << " ";
      adjList[index].print();
      std::cout << std::endl;
    }
    std::cout << std::endl;
  }

  void depthFirstTraversal() {
    bool *visited = new bool[size]();
    for (int index = 0; index < size; index++)	{
      if (!visited[index])  { dft(index, visited); }
    }

    delete [] visited;
  }

  void breadthFirstTraversal() {
    LinkedQueue<int> queue;
    bool *visited = new bool[size]();

    LinkedListIterator<int> it;
    for (int index = 0; index < size; index++) {
      if (!visited[index]) {
        queue.enqueue(index);
        visited[index] = true;
        std::cout << " " << vertices[index] << " ";

        while (!queue.empty()) {
          int u = queue.peekFront();
          queue.dequeue();

          for (it = adjList[u].begin(); it != adjList[u].end(); ++it) {
            int w = *it;
            if (!visited[w]) {
              queue.enqueue(w);
              visited[w] = true;
              std::cout << " " << vertices[w] << " ";
            }
          }
        }
      }
    }
    delete [] visited;
  }

  //implemented from the book
  void printTopologicalOrder() {
    //initializing linked list queue
    LinkedQueue<int> queue;

    //pointer to the array that stores topological ordering
    int *topOrder;
    topOrder = new int[size];

    int topIndex = 0;

    //initializing linked list iter
    LinkedListIterator<int> adjIt;

    //pointer to the array that stores predecessor count
    int *predCount;
    predCount = new int[size];

    for (int i = 0; i < size; i++)
    {
      predCount[i] = 0;
    }

    //get predecessor count of all vertices
    for (int i = 0; i < size; i++)
    {
      for (adjIt = adjList[i].begin(); adjIt != adjList[i].end(); ++adjIt)
      {
        int w = *adjIt;
        predCount[w]++;
      }

    }

    //begin working with queue
    for (int i = 0; i < size; i++)
    {
      if (predCount[i] == 0)
      {
        queue.enqueue(i);
      }
    }

    while (!queue.empty()) {
      int u = queue.peekFront();
      queue.dequeue();
      topOrder[topIndex++] = u;

      for (adjIt = adjList[u].begin(); adjIt != adjList[u].end(); ++adjIt){
        int w = *adjIt;
        predCount[w]--;
        if (predCount[w] == 0) {queue.enqueue(w);}
      }
    }

    for (int i = 0; i < size; i++) { std::cout << " " << vertices[topOrder[i]] << " "; }
    std::cout << std::endl;

    delete[] topOrder;
    delete[] predCount;
  }

protected:
  int size;
  LinkedList<int> *adjList;
  T* vertices;

private:
  void dft(int v, bool visited[]) {
    visited[v] = true;
    std::cout << " " << vertices[v] << " ";

    LinkedListIterator<int> it;

    for (it = adjList[v].begin(); it != adjList[v].end(); ++it) {
      int w = *it;
      if (!visited[w]) { dft(w, visited); }
    }
  }

};

#endif