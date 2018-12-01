#define CATCH_CONFIG_MAIN
#include <iostream>
#include <sstream>
#include "catch.hpp"
#include "graph.h"
#include "course.h"

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


  g->getAdjList()[0].insertFirst(1);
  g->getAdjList()[0].insertFirst(7);

  g->getAdjList()[1].insertFirst(2);
  g->getAdjList()[1].insertFirst(3);
  g->getAdjList()[1].insertFirst(4);
  g->getAdjList()[1].insertFirst(8);
  g->getAdjList()[1].insertFirst(9);

  g->getAdjList()[2].insertFirst(5);
  g->getAdjList()[2].insertFirst(6);
  g->getAdjList()[2].insertFirst(9);

}

TEST_CASE("Testing graph with course class") {
  Graph<Course>* g;
  createGraph(g);

  SECTION( "Testing to see if the courses were inserted correctly" ){
    CHECK(g->empty() == 0);

    CHECK(g->getVertices()[6].getCourseNumber() == "CS 2450");
    CHECK(g->getVertices()[6].getCourseName() == "Software Engineering I");
    CHECK(g->getVertices()[6].getCreditHours() == 4);

    std::stringstream sout;

    sout << g->getVertices()[0];
    CHECK(sout.str() == " CS 1030 - Foundations of Computing: (4)\n");
    sout.str("");

    sout << g->getVertices()[4];
    CHECK(sout.str() == " CS 2350 - Client Side Web Development: (4)\n");
    sout.str("");

    sout << g->getVertices()[9];
    CHECK(sout.str() == " CS 2810 - Computer Architecture/Organization: (4)\n");
    sout.str("");
  }

  SECTION( "Testing to see if adjacency's were inserted correctly" ){
    CHECK(g->getAdjList()[0].length() == 2);
    CHECK(g->getAdjList()[1].length() == 5);
    CHECK(g->getAdjList()[2].length() == 3);
    CHECK(g->getAdjList()[3].empty() == 1);
    CHECK(g->getAdjList()[4].empty() == 1);
    CHECK(g->getAdjList()[5].empty() == 1);
    CHECK(g->getAdjList()[6].empty() == 1);
    CHECK(g->getAdjList()[7].empty() == 1);
    CHECK(g->getAdjList()[8].empty() == 1);
    CHECK(g->getAdjList()[9].empty() == 1);

    std::stringstream sout;

    sout << g->getVertices()[g->getAdjList()[0].front()];
    CHECK(sout.str() == " CS 2550 - Introduction to Database Design and SQL: (4)\n");
    sout.str("");
    sout << g->getVertices()[g->getAdjList()[0].back()];
    CHECK(sout.str() == " CS 1400 - Fundamentals of Programming: (4)\n");
    sout.str("");
  }


  SECTION( "Printing the different versions of the graphs, and"
           "finally erasing the graph now that we are done with it"){
    std::cout << " ";
    g->printTopologicalOrder();
    std::cout << " ";
    g->depthFirstTraversal();
    std::cout << std::endl;
    std::cout << " ";
    g->breadthFirstTraversal();


    g->clear();
    CHECK(g->empty() == 1);
  }

}