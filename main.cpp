#include <nlohmann/json.hpp>
#include <string>
#include <iostream>
#include "Set.h"
#include "Exercise.h"

using json = nlohmann::json;

int main() {
    // Create a Exercise object
    Exercise exercise{"Squat" ,  {100,5} , "Strength"};

    // Serialize to JSON
    json j = exercise;
    std::cout << "Serialized JSON: " << j.dump(4) << '\n';

    // Deserialize back to Exercise
    Exercise deserialized_exercise = j.get<Exercise>();
    std::cout << "Deserialized Exercise: " << deserialized_exercise.getName()
        << ", " << deserialized_exercise.getMetaData()
        << ", " << deserialized_exercise.getSet().weight << '\n';

    return 0;
}
