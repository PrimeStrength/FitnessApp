#include <string>
#include <iostream>
#include <nlohmann/json.hpp>
#include "storageAPI.h"
#include <expected>
#include <fstream>

using json = nlohmann::json;

/*
 // Create a Exercise object
 Exercise exercise{"Squat" ,  {100,5} , "Strength"};

 // Serialize to JSON
 json j = exercise;
 std::cout << "Serialized JSON: " << j.dump(4) << '\n';

 // Deserialize back to Exercise
 Exercise deserialized_exercise = j.get<Exercise>();
 std::cout << "Deserialized Exercise: " << deserialized_exercise.getName()
     << ", " << deserialized_exercise.getMetaData()
     << ", " << deserialized_exercise.getSet().weight << '\n';
*/


	auto storage::create(json ex) -> std::expected<void,std::string> 
	{
		try {

			std::fstream file;
			file.open(R"(.\Exercise.json)", std::ios::out);

			file << ex;

			return {};

		}
		catch (const std::exception& e) {
			return std::unexpected("Unable to add Exercise");
		}

		

	}

