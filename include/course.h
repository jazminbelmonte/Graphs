#ifndef _COURSE_H_
#define _COURSE_H_

#include <string>
#include <iomanip>
#include "graph.h"

class Course{
protected:
  std::string number, name;
  int creditHours, size;

public:
  friend std::ostream& operator<<(std::ostream& out, const Course& c){

    return out;
  }
};

#endif