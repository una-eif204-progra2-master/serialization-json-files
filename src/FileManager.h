//
// Created by Maikol Guzman on 10/16/20.
//

#ifndef SERIALIZATION_JSON_FILEMANAGER_H
#define SERIALIZATION_JSON_FILEMANAGER_H

#include <../lib/nlohmann/json.hpp>

#include <string>
#include "Person.h"

using namespace std;
using nlohmann::json;

class FileManager {
public:
    static void save(const string& jsonData, const std::string &filename);
    static string read(const std::string &filename);
    static string serialize(const vector<Person>& _personList);
    static vector<Person> deserialize(const string& _data);
};


#endif //SERIALIZATION_JSON_FILEMANAGER_H
