//
// Created by Maikol Guzman on 10/16/20.
//
#include <iomanip>
#include <fstream>
#include <sstream>
#include <iostream>
#include "FileManager.h"


/**
 * Custom to_json method automatically called.
 * @param _json the Json Object
 * @param _person the Model
 */
void to_json(json &_json, const Person &_person) {
    json jCourse;
    auto jCourseList = json::array();

    // this method is necessary to serialize tha information from the vector
    for(const Course& course : _person.getCourseList()) {
        jCourse["id"] = course.getId();
        jCourse["name"] = course.getName();
        jCourseList.push_back(jCourse);
    }

    _json["id"] = _person.getId();
    _json["name"] = _person.getName();
    _json["courses"] = jCourseList;

}

/**
 * Custom from_json method automatically called.
 * @param _json  the Json Object
 * @param _person the Model
 */
void from_json(const json &_json, Person &_person) {
    vector<Course> courseList;
    json courseData = _json["courses"];

    // this method is necessary to deserialize tha information from the vector
    for (auto & data : courseData) {
        Course course;
        course.setId(data.at("id").get<int>());
        course.setName(data.at("name").get<std::string>());
        courseList.push_back(course);
    }

    _person.setId(_json.at("id").get<int>());
    _person.setName(_json.at("name").get<std::string>());
    _person.setCourseList(courseList);
}

/**
 * This method will serialize the vector
 * @param _personList
 * @return the string with the json array
 */
string FileManager::serialize(const vector<Person>& _personList) {
    json jsonData(_personList);
    string jsonArray = jsonData.dump();
    return jsonArray;
}

/**
 * This method deserialize the string to object
 * @param _data the string json data
 * @return the array of objects
 */
vector<Person> FileManager::deserialize(const string& _data) {
    json jsonData = json::parse(_data);
    vector<Person> personList = jsonData;

    return personList;
}

/**
 * This method will save a serialized string into JSON File
 * @param jsonData the string data
 * @param filename the name of the file
 */
void FileManager::save(const string& jsonData, const string &filename) {
    std::ofstream file (filename, std::ofstream::out);
    file << jsonData;
    file.close();
}

/**
 * This method will read the information from a JSON File
 * @param filename the name of the file
 * @return the JSON Data
 */
string FileManager::read(const string &filename) {
    std::string txtContent;

    try {
        std::ifstream file (filename);
        file.exceptions ( std::ifstream::failbit | std::ifstream::badbit );

        stringstream buffer;
        buffer << file.rdbuf();
        std::string fileContent(buffer.str());
        txtContent = fileContent;
    }
    catch (std::ifstream::failure e) {
        throw std::runtime_error("Exception opening/reading/closing file");
    }

    return txtContent;
}
