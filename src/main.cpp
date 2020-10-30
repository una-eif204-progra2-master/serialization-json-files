//
// Created by Maikol Guzman on 9/28/20.
//

// https://github.com/nlohmann/json (Library to handle JSON)

#include <iostream>
#include "Person.h"
#include "FileManager.h"
#include "Course.h"

using namespace std;

/**
 * Example to Serializing JSON objects
 * @return null
 */
int main() {

    vector<Course> courseList1;
    vector<Course> courseList2;

    vector<Person> personList;

    Course course1 = Course(1, "Progra 1");
    Course course2 = Course(2, "Progra 2");
    Course course3 = Course(3, "Progra 3");

    courseList1.push_back(course1);
    courseList1.push_back(course2);
    courseList1.push_back(course3);

    courseList2.push_back(course1);
    courseList2.push_back(course3);

    Person person1 = Person(1, "Mike", courseList1);
    Person person2 = Person(2, "Carlos", courseList2);

    personList.push_back(person1);
    personList.push_back(person2);

    cout << "Serialización del Json" << endl;
    cout << FileManager::serialize(personList);

    // Save the data into Person.json
    FileManager::save(FileManager::serialize(personList), "Person.json");

    vector<Person> personListFromJson;
    cout << "\n\nDeserialización del Json" << endl;

    string dataFromJSonFile;
    dataFromJSonFile = FileManager::read("Person.json");

    personListFromJson = FileManager::deserialize(R"([{"id":1,"name":"Mike"},{"id":2,"name":"Carlos"}])");
    for (const Person &person: personListFromJson) {
        std::cout << person.toString() << std::endl;
    }
}