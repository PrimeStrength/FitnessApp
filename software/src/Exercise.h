#pragma once
#include <string>
#include <vector>
#include "Set.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;


class Exercise {

private:
    std::string m_name{};
    std::string m_metaData{};
	std::vector<Set> m_sets{};
public:

	Exercise(std::string name, Set sets, std::string data="");
	Exercise() = default;

	friend void to_json(json& j, const Exercise& ex);
	friend void from_json(const json& j, Exercise& ex);

	std::string getName() const { return m_name; }
	std::string getMetaData() const { return m_metaData; }
	std::vector<Set> getSets() const { return m_sets; }

};

