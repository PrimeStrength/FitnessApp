#pragma once
#include <vector>
#include <chrono>
#include "nlohmann/json.hpp"
#include "Set.h"

//#include <initializer_list>

namespace exercise
{

class Workout 
{

public:

	// Implement Constructor
	// Workout(std::initializer_list<Set> sets) : m_sets(sets) {}


	Workout(std::chrono::year_month_day date, std::string name, std::vector<Set> initList = {{}} );
	Workout(std::chrono::year_month_day date, std::vector<Set> initList = { {} });


	std::vector<Set> get_set();
	void add_set(Set);

	friend void to_json(json& j, const Workout& wrkt);
	friend void from_json(const json& j, Workout& wrkt);

private:
	std::chrono::year_month_day m_date{};
	// std::vector<Exercise> m_exList{};
	std::vector<Set> m_sets{};
	std::string m_name{};

};

} //namespace exercise