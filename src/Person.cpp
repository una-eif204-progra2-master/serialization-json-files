//
// Created by Maikol Guzman on 10/8/20.
//

#include "Person.h"
#include <utility>
#include <sstream>

Person::Person() = default;

Person::Person(int id, std::string name) : id(id), name(std::move(name)) {}

Person::Person(int id, std::string name, std::vector<Course> courseList) : id(id), name(std::move(name)),
                                                                                         courseList(std::move(courseList)) {}

int Person::getId() const {
    return id;
}

void Person::setId(int id) {
    Person::id = id;
}

const std::string &Person::getName() const {
    return name;
}

void Person::setName(const std::string &name) {
    Person::name = name;
}

const std::vector<Course> &Person::getCourseList() const {
    return courseList;
}

void Person::setCourseList(const std::vector<Course> &courseList) {
    Person::courseList = courseList;
}

std::string Person::toString() const {
    std::ostringstream output;
    output << "Person id: " << getId()
           << ", Name: " << getName();

    return output.str();
}

Person::~Person() = default;
