#include "Workout.h"
#include <chrono>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>

// ** Change to different file
std::string dateToString(const std::chrono::year_month_day& ymd)
{
    // Extract year, month, and day from the year_month_day
    auto year = static_cast<int>(ymd.year()); 
    auto month = static_cast<unsigned>(ymd.month());
    auto day = static_cast<unsigned>(ymd.day()); 

    // Create a string stream and format it
    std::ostringstream oss;
    oss << std::setw(4) << std::setfill('0') << year << "-"
        << std::setw(2) << std::setfill('0') << month << "-"
        << std::setw(2) << std::setfill('0') << day;

    return oss.str();
}

// ** Chnange to different file?
namespace nlohmann {
    // template <>: Declares a full specialization for a specific type.
    // here,  specifically for std::chrono::year_month_day
    template <>
    struct adl_serializer<std::chrono::year_month_day> {

        static void from_json(const json& j, std::chrono::year_month_day& ymd) {
            std::string date_str = j.get<std::string>();
            int year{};
            unsigned int month{};
            unsigned int day{};

            if (sscanf(date_str.c_str(), "%d-%d-%d", &year, &month, &day) == 3) {
                ymd = std::chrono::year{ year } / std::chrono::month{ month } / std::chrono::day{ day };
            }
            else {
                throw std::invalid_argument("Invalid date format");
            }
        }

        static void to_json(json& j, const std::chrono::year_month_day& ymd) {

            j = dateToString(ymd);
        }


    };
}

exercise::Workout::Workout(std::chrono::year_month_day date, std::string name , std::vector<exercise::Set> initList )
	: m_date{date}
    , m_sets{initList}
    , m_name{name}
{
}

exercise::Workout::Workout(std::chrono::year_month_day date, std::vector<Set> initList)
    :Workout{date ,dateToString(date), initList}
{
}


void to_json(json& j, const exercise::Workout& workout) {
    j = json{
        {"date", workout.m_date},
        {"exercises", workout.m_sets}, 
        {"name", workout.m_name}
    };
}

void from_json(const json& j, exercise::Workout& wrkt) {
    j.at("date").get_to(wrkt.m_date);
    j.at("sets").get_to(wrkt.m_sets);
    j.at("name").get_to(wrkt.m_name);
}
