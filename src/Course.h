//
// Created by Maikol Guzman on 10/30/20.
//

#ifndef SERIALIZATION_JSON_FILES_COURSE_H
#define SERIALIZATION_JSON_FILES_COURSE_H

#include <string>

class Course {
private:
    int id{};
    std::string name;

public:
    Course();

    virtual ~Course();

    Course(int id, std::string name);

    int getId() const;

    void setId(int id);

    const std::string &getName() const;

    void setName(const std::string &name);

    virtual std::string toString() const; // virtual method
};


#endif //SERIALIZATION_JSON_FILES_COURSE_H
