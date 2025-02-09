#pragma once
#include <vector>
#include "Exercise.h"
#include <chrono>
#include "nlohmann/json.hpp"



class Session 
{

public:

	Session(std::chrono::year_month_day date, std::string name , std::vector<Exercise> initList = { {} } );
	Session(std::chrono::year_month_day date, std::vector<Exercise> initList = { {} });


	void getExercises();

	friend void to_json(json& j, const Session& ex);
	friend void from_json(const json& j, Session& ex);

private:
	std::chrono::year_month_day m_date{};
	std::vector<Exercise> m_exList{};
	std::string m_name{};

};
