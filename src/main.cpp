#include <iostream>
#include "course.h"
#include "graph.h"

using namespace std;

void createGraph(Graph<Course>* &g) {

  g = new Graph<Course>(10);

  Course("CS 1030", "Foundations of Computing", 4);




}

int main(){
  Graph<Course>* g;

  createGraph(g);

  g->printTopologicalOrder();

  return 0;
}