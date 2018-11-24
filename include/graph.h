#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <fstream>
#include "linked_list.h"
#include "linked_queue.h"

template <typename T>
class Graph{
public:
  Graph(int sz): size(sz), graph(new LinkedList<int>[sz]()), vertices(new T[sz]){}
  ~Graph() { clear(); }

  bool empty() const { return size == 0; }

  T* getVertices() { return vertices; }
  LinkedList<int>* getGraph() { return graph; }

  void clear(){
    for (int index = 0; index < size; index++) {
      graph[index].destroy();
    }

    size = 0;
  } 

  void print() const {
    for (int index = 0; index < size; index++) {
      std::cout << index << " ";
      graph[index].print();
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

          for (it = graph[u].begin(); it != graph[u].end(); ++it) {
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

  void printTopologicalOrder() {
    //TODO
  }

protected:
  int size; 
  LinkedList<int> *graph; 
  T* vertices;

private:
  void dft(int v, bool visited[]) {
    visited[v] = true;
    std::cout << " " << vertices[v] << " ";  

    LinkedListIterator<int> it;

    for (it = graph[v].begin(); it != graph[v].end(); ++it) {
      int w = *it;
      if (!visited[w]) { dft(w, visited); }
    } 
  } 

};

#endif