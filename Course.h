//
// Created by jacob on 9/18/21.
//

#ifndef PROJECTONE_COURSE_H
#define PROJECTONE_COURSE_H

#include <string>
#include <vector>
#include <iostream>

class Course {

public:
    Course();
    //Constructor
    Course(std::string section, std::string name);
    //Getters
    std::string getSection();
    std::string getName();
    void addPreq(std::string preq);
    void printCourse();

private:
    //Fields
    std::string section;
    std::string name;
    std::vector<std::string> prerequisites;

};


#endif //PROJECTONE_COURSE_H
