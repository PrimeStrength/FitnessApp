#include "Rep.h"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

void to_json(json& j, const exercise::Rep& rep)
{
    j = json 
    {
        {"rep", rep.m_weight},
        {"duration",rep.m_duration_secs}
    };
}

void from_json(const json& j,exercise::Rep& rep)
{
    j.at("rep").get_to(rep.m_weight);
    j.at("duration").get_to(rep.m_duration_secs);
}