#include <nlohmann/json.hpp>
#include <string>
#include <iostream>
#include "Set.h"
#include "Exercise.h"
#include "crow.h"
#include "storageAPI.h"
#include <format>

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

int main() {
 
       crow::SimpleApp app; //define your crow application

    //define your endpoint at the root directory
    CROW_ROUTE(app, "/createExercise/<string>")([](std::string name){

        return storeExercise(name);

    });

    //set the port, set the app to run on multiple threads, and run the app
    app.port(18080).multithreaded().run();

    return 0;
}
