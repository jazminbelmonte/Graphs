#include <iostream>
#include "course.h"
#include "graph.h"

using namespace std;

void createGraph(Graph<Course>* &g) {
  g = new Graph<Course>(10);

  Course c1030("CS 1030", "Foundations of Computing", 4);
  Course c1400("CS 1400", "Fundamentals of Programming", 4);
  Course c1410("CS 1410", "Object-Oriented Programming", 4);
  Course c2130("CS 2130", "Computational Structures", 4);
  Course c2350("CS 2350", "Client Side Web Development", 4);
  Course c2420("CS 2420", "Introduction to Data Structures and Algorithms", 4);
  Course c2450("CS 2450", "Software Engineering I", 4);
  Course c2705("CS 2705", "Network Fundamentals and Design", 4);
  Course c2550("CS 2550", "Introduction to Database Design and SQL", 4);
  Course c2810("CS 2810", "Computer Architecture/Organization", 4);

  g->getVertices()[0] = c1030;
  g->getVertices()[1] = c1400;
  g->getVertices()[2] = c1410;
  g->getVertices()[3] = c2130;
  g->getVertices()[4] = c2350;
  g->getVertices()[5] = c2420;
  g->getVertices()[6] = c2450;
  g->getVertices()[7] = c2550;
  g->getVertices()[8] = c2705;
  g->getVertices()[9] = c2810;

  //Courses that have CS 1030 as a prereq
  g->getAdjList()[0].insertFirst(1); //CS 1400
  g->getAdjList()[0].insertFirst(7); //CS 2550

  /*
  Course CS 2705 should not be put as an adjacency to 1030
  because to take the course you must have taken both 1030
  AND 1400, and to take 1400 you must be taking 1030 in the
  first place, you cannot go directly from 1030
  to 2705
  */

  //Courses that have CS 1400 as a prereq
  g->getAdjList()[1].insertFirst(2); //CS 1410
  g->getAdjList()[1].insertFirst(3); //CS 2130
  g->getAdjList()[1].insertFirst(4); //CS 2350
  g->getAdjList()[1].insertFirst(8); //CS 2705
  g->getAdjList()[1].insertFirst(9); //CS 2810

  //Courses that have CS 1410 as a prereq
  g->getAdjList()[2].insertFirst(5); //CS 2420
  g->getAdjList()[2].insertFirst(6); //CS 2450
  g->getAdjList()[2].insertFirst(9); //CS 2810
}

int main(){
  Graph<Course>* g;

  createGraph(g);

  std::cout << " ";
  g->printTopologicalOrder();
  std::cout << " ";
  g->depthFirstTraversal();
  std::cout << std::endl;
  std::cout << " ";
  g->breadthFirstTraversal();

  return 0;
}