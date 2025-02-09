#include <nlohmann/json.hpp>
#include <string>
#include <iostream>
#include "Set.h"
#include "Exercise.h"
#include "crow.h"
#include "storageAPI.h"
#include <format>
#include "Session.h"

using json = nlohmann::json;


std::string storeExercise(std::string s)
{

    auto ex = Exercise(s, {100,5});
    json j = ex;
    std::cout << j.dump(4);
    
    auto result = storage::create(j);
    
    std::string response{};

    if (result.has_value()) {
        response += std::format("Exercise {} created", ex.getName());
    }
    else {
        response += "Unable to store Exercise: " + result.error();
    }

    return response;
}


std::string getSession()
{

	// Returns a hardcoded Session 
    std::chrono::year_month_day ymd = std::chrono::year{ 2025 } / std::chrono::January / 27;
    auto test = Session (ymd, { {"squat",{5,5}}, {"Deadlift", {3,3}} });

    json j{ test };

    return j.dump(4);
}

int main() {
 
   crow::SimpleApp app; //define your crow application

    //define your endpoint at the root directory
    CROW_ROUTE(app, "/createExercise/<string>")([](std::string name){

        return storeExercise(name);

    });
    
    CROW_ROUTE(app, "/getSession")([]() {

        return getSession();

	});

 
    //set the port, set the app to run on multiple threads, and run the app
    app.port(18080).multithreaded().run();

    return 0;
}
