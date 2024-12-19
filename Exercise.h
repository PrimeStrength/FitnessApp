#pragma once
#include <string>
#include <vector>
#include "Set.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class Exercise
{
private:
	 std::string m_name{};
	// metrics Metric{};
	 Set m_sets{};
	 std::string m_metaData{};

public:
	Exercise(std::string name, Set sets, std::string data="");
	Exercise() = default;
	
	void to_json(json& j, const Exercise& ex);
	void from_json(const json& j, Exercise& ex);

	std::string getName() const { return m_name; }
};

