#include "Exercise.h"
#include <string>
#include "nlohmann/json.hpp"

using json = nlohmann::json;
namespace exercise
{

Exercise::Exercise(
    std::string name,
    std::optional<modality> md,
    std::optional<json> data,
    std::optional<std::string> descript)
    : m_name{name}, m_md{md}, m_metadata{data}, m_descript{descript}
{
}

void to_json(json& j, const Exercise& excs)
{
    json foo{};
    j = json{
        {"name", excs.m_name},
        {"data", excs.m_metadata ? *excs.m_metadata : json{}},
        {"modality", excs.m_md ? json{excs.m_md.value()} : json{}},
        {"descripton",
         excs.m_descript ? json{excs.m_descript.value()} : json{}}};
}

void from_json(const json& j, exercise::Exercise& excs)
{
    j.at("name").get_to(excs.m_name);
    try
    {
        excs.m_metadata = j.at("data");
    }
    catch (const json::out_of_range&)
    {
        excs.m_metadata = std::nullopt;
    }

    try
    {
        excs.m_md = j.at("modality");
    }
    catch (const json::out_of_range&)
    {
        excs.m_md = std::nullopt;
    }

    try
    {
        excs.m_md = j.at("descript");
    }
    catch (const json::out_of_range&)
    {
        excs.m_md = std::nullopt;
    }
}
} // namespace exercise
