#include "Set.h"
#include <string_view>
#include "Exercise.h"

Exercise::Exercise(std::string name, Set sets, std::string data)
	:m_name{ name }
	, m_metaData{ data }
	, m_sets{ sets }
{
}

void to_json(json& j, const Exercise& excs) {
	j = json{
		{"name", excs.m_name},
		{"data", excs.m_metaData},
		{"set", excs.m_sets} 
	};
}

void from_json(const json& j, Exercise& excs) {
	j.at("name").get_to(excs.m_name);
	j.at("data").get_to(excs.m_metaData);
	j.at("set").get_to(excs.m_sets); 
}
