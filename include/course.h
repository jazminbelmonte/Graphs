#ifndef _COURSE_H_
#define _COURSE_H_

#include <string>
#include <iomanip>
#include "graph.h"

class Course {
protected:
  int size;
  std::string number;
  std::string name;
  int creditHours;

public:

  friend std::ostream &operator<<(std::ostream &out, const Course &c) {
    out << std::setw(8) << c.number << " - " << c.name << ": (" << c.creditHours << ")";
    return out;
  }

  //Setters
  void setSize(int s) {
    this->size = s;
  }
  void setCourseNumber(std::string cnum) {
    this->number = cnum;
  }
  void setCourseName(std::string cn) {
    this->name = cn;
  }
  void setCreditHours(int ch) {
    this->creditHours = ch;
  }

  //Getters
  int getSize() {
    return size;
  }
  std::string getCourseNumber() const{
    return number;
  }
  std::string getCourseName() const{
    return name;
  }
  int getCreditHours() const{
    return creditHours;
  }

};

#endif