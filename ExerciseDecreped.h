#pragma once
#include <nlohmann/json.hpp>
#include <string>
#include "Set.h"

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

