#ifndef _COURSE_H_
#define _COURSE_H_

#include <string>
#include <iomanip>
#include "graph.h"

class Course {
protected:
  std::string number;
  std::string name;
  int creditHours;

public:
  //default
  Course(): number("none"), name("none"), creditHours(0) {}

  //using constructor to set the course values
  Course(std::string num, std::string n,int ch): number(num), name(n), creditHours(ch){}

  //overloaded << operator
  friend std::ostream &operator<<(std::ostream &out, const Course &c) {
    out << std::setw(8) << c.number << " - " << c.name << ": (" << c.creditHours << ")" << std::endl;
    return out;
  }

  //Getters
  std::string getCourseNumber() const{ return number; }
  std::string getCourseName() const{ return name; }
  int getCreditHours() const{ return creditHours; }

};

#endif