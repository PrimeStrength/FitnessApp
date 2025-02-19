#include <string>
#include "Exercise.h"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

exercise::Exercise::Exercise(
    std::string name,
    std::optional<exercise::modality> md,
    std::optional<json> data,
    std::optional<std::string> descript)
    : m_name{name}, m_md{md}, m_metadata{data}, m_descript{descript}
{
}

void to_json(json& j, const exercise::Exercise& excs)
{
    j = json{
        {"name", excs.m_name}, {"data", excs.m_metaData}, {"modality", m_md}, {"descripton", m_descript};
}

void from_json(const json& j, exercise::Exercise& excs)
{
    j.at("name").get_to(excs.m_name);
    j.at("data").get_to(excs.m_metadata);
    j.at("modality").get_to(excs.m_md);
    j.at("description").get_to(excs.m_descript);
}
