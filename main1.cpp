#include <iostream>
#include <nlohmann/json.hpp>
#include  "Exercise.h"
#include "Set.h"
//#include <json.hpp>

using json = nlohmann::json;
#if 0
/* int main() {
 
    std::string Data
    { R"({
        "name": "squat",
            "set" : {
            "weight": 100,
                "reps" : 2
	}})" };

    json Doc{json::parse(Data)};

    Exercise exercise;
    
    Doc.get_to(exercise);

   // std::cout << "Name: " << Player.Name;
    //std::cout << "\nLevel: " << Player.Level;
    */

    // Create a Person object
    Exercise exercise{ "Squat", {3,120},"strength"};

    std::cout << exercise.getName();


    // Serialize to JSON
   // json j = exercise;
  //  std::cout << "Serialized JSON: " << j.dump(4) << std::endl;
/*
    // Deserialize back to Person
    Person deserialized_person = j.get<Person>();
    std::cout << "Deserialized Person: " << deserialized_person.name
        << ", " << deserialized_person.age
        << ", " << deserialized_person.address.city << std::endl;

#end 
