//
// Created by Maikol Guzman on 10/8/20.
//

#ifndef SERIALIZATION_JSON_PERSON_H
#define SERIALIZATION_JSON_PERSON_H


#include <string>
#include <vector>
#include "Course.h"

class Person {
private:
    int id{};
    std::string name;
    std::vector<Course> courseList;
public:
    Person();

    Person(int id, std::string name);

    Person(int id, std::string name, std::vector<Course> courseList);

    virtual ~Person();

    int getId() const;

    void setId(int id);

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::vector<Course> &getCourseList() const;

    void setCourseList(const std::vector<Course> &courseList);

    virtual std::string toString() const; // virtual method
};


#endif //SERIALIZATION_JSON_PERSON_H
