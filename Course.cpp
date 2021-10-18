//
// Created by jacob on 9/18/21.
//

#include "Course.h"
/**
 * Default constructor for course
 */
Course::Course() {

    this->section = "";
    this->name = "";

}
/**
 * Creates a new course given a section and name
 * @param section
 * @param name
 */
Course::Course(std::string section, std::string name) {

    this->section = section;
    this->name = name;

}
/**
 * Gets the name of course
 * @return name
 */
std::string Course::getName() {

    return this->name;

}
/**
 * Gets the section of course
 * @return section
 */
std::string Course::getSection() {

    return this->section;

}
/**
 * Prints this class
 */
void Course::printCourse() {

    std::cout << "=========================" << std::endl;
    std::cout << this->section << std::endl;
    std::cout << this->name << std::endl;
    std::cout << "Prerequisites:" << std::endl;
    for(std::string preq : prerequisites){

        std::cout << preq << std::endl;

    }
    std::cout << "=========================" << std::endl;

}
/**
 * Adds a prerequisite to the course
 * @param preq
 */
void Course::addPreq(std::string preq) {

    this->prerequisites.push_back(preq);

}