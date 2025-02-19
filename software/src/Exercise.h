#pragma once
#include <nlohmann/json.hpp>
#include <optional>
#include <string>
#include "nlohmann/json_fwd.hpp"

using json = nlohmann::json;

namespace exercise
{

enum class modality : std::uint8_t
{
    strength,
    power,
    hypertrophy,
    muscluarEndurence,
    cardio,
    sport,
    hybrid
};

class Exercise
{
using json = nlohmann::json;

public:
    explicit Exercise(
        std::string name,
        std::optional<modality> mode = std::nullopt,
        std::optional<json> data = std::nullopt,
        std::optional<std::string> descript = std::nullopt);
    
    
    //Exercise() = default;

    friend void to_json(json& j, const Exercise& ex);
    friend void from_json(const json& j, Exercise& ex);

    std::string getName() const
    {
        return m_name;
    }
    std::optional<json> getMetaData() const
    {
        return m_metadata;
    }

private:
    std::string m_name{};
    std::optional<modality> m_md{};
    std::optional<json> m_metadata{}; // Why nlohmann json ?
    std::optional<std::string> m_descript{};// std::string m_metadata{};
};

} // namespace exercise
