#include <nlohmann/json.hpp>
#include <string>
#include <iostream>
#include "Set.h"
#include "Exercise.h"
#include "crow.h"
#include "storageAPI.h"
#include <format>
#include "processes.h"

using json = nlohmann::json;

int main() {
 
   crow::SimpleApp app; //define your crow application

    //define your endpoint at the root directory
    CROW_ROUTE(app, "/createExercise/<string>")([](std::string name){

        return processes::storeExercise(name);

    });
    
    CROW_ROUTE(app, "/getSession")([]() {

        return processes::getSession();

	});

 
    //set the port, set the app to run on multiple threads, and run the app
    app.port(18080).multithreaded().run();

    return 0;
}
