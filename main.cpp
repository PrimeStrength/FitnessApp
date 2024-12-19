#include <nlohmann/json.hpp>
#include <string>
#include <iostream>

using json = nlohmann::json;

struct Set {
    int weight{};
    int reps{} ;

    // Define to_json for Address
    friend void to_json(json& j, const Set& set) {
        j = json{
            {"weight", set.weight},
            {"reps", set.reps}
        };
    }

    // Define from_json for Address
    friend void from_json(const json& j, Set& set) {
        j.at("weight").get_to(set.weight);
        j.at("reps").get_to(set.reps);
    }
};

class Exercise {
public:
    std::string m_name{};
    std::string m_metaData{};
    Set set;

    // Define to_json for Exercise
    friend void to_json(json& j, const Exercise& excs) {
        j = json{
            {"name", excs.m_name},
            {"data", excs.m_metaData},
            {"set", excs.set} // Address already has a to_json method
        };
    }

    // Define from_json for Exercise
    friend void from_json(const json& j, Exercise& excs) {
        j.at("name").get_to(excs.m_name);
        j.at("data").get_to(excs.m_metaData);
        j.at("set").get_to(excs.set); // Address already has a from_json method
    }
};

int main() {
    // Create a Exercise object
    Exercise exercise{"Squat" , "Strength", {100,5} };

    // Serialize to JSON
    json j = exercise;
    std::cout << "Serialized JSON: " << j.dump(4) << '\n';

    // Deserialize back to Exercise
    Exercise deserialized_exercise = j.get<Exercise>();
    std::cout << "Deserialized Exercise: " << deserialized_exercise.m_name
        << ", " << deserialized_exercise.m_metaData
        << ", " << deserialized_exercise.set.weight << '\n';

    return 0;
}
