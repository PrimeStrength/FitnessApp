#include "Set.h"
#include <string_view>
#include "Exercise.h"


Exercise::Exercise(std::string name, Set sets, std::string data)
	:m_name{ name }
	, m_sets{ sets }
	, m_metaData{ data }
{
};

void Exercise::to_json(json& j, const Exercise& ex)
{
	j = json{{"name", ex.m_name},
			 {"set", ex.m_sets},
			{"metaData", ex.m_metaData }};
}

void Exercise::from_json(const json& j, Exercise& ex) {
    j.at("name").get_to(ex.m_name);
    j.at("set").get_to(ex.m_sets);
	j.at("metaData").get_to(ex.m_metaData);
}


