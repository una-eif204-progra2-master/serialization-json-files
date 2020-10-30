//
// Created by Maikol Guzman on 10/30/20.
//

#include "Course.h"
#include <utility>
#include <sstream>

Course::Course() = default;

Course::Course(int id, std::string name) : id(id), name(std::move(name)) {}

int Course::getId() const {
    return id;
}

void Course::setId(int id) {
    Course::id = id;
}

const std::string &Course::getName() const {
    return name;
}

void Course::setName(const std::string &name) {
    Course::name = name;
}

std::string Course::toString() const {
    std::ostringstream output;
    output << "Course id: " << getId()
           << ", Name: " << getName();

    return output.str();}

Course::~Course() = default;
