#include <string>
#include <iostream>
#include "Exercise.h"
#include "storageAPI.h"
#include "processes.h"
#include "Session.h"


std::string processes::storeExercise(const std::string& name)
{

    auto ex = Exercise(name, { 100,5 });
    json j = ex;
    std::cout << j.dump(4);

    auto result = storage::create(j);

    std::string response{};

    if (result.has_value())
    {
        response += std::format("Exercise {} created", ex.getName());
    }
    else
    {
        response += "Unable to store Exercise: " + result.error();
    }

    return response;
}

std::string processes::getSession()
{

    // Returns a hardcoded Session 
    std::chrono::year_month_day ymd = std::chrono::year{ 2025 } / std::chrono::January / 27;
    auto test = Session(ymd, { {"squat",{5,5}}, {"Deadlift", {3,3}} });

    json j{ test };

    return j.dump(4);
}

