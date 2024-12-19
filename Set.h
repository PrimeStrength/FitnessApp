#pragma once
#include <nlohmann/json.hpp>
using json = nlohmann::json;

struct Set {

    int weight{};
    int reps{} ;

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

