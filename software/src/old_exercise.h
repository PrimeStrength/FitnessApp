#pragma once

#include <nlohmann/json.hpp>
#include <string>
#include <utility>

namespace exercise
{

enum class modality : std::uint8_t
{
    strength,
    cardio,
    sport,
    hybrid
};

class exercise
{
public:
    explicit exercise(std::string name, std::string description, modality md)
        : _name(std::move(name)), _description(std::move(description)), _md(md)
    {
    }

    explicit exercise(
        std::string name,
        std::string description,
        modality md,
        nlohmann::json metadata)
        : _name(std::move(name))
        , _description(std::move(description))
        , _md(md)
        , _metadata(metadata)
    {
    }

    std::string get_name() const;
    std::string get_description() const;

private:
    std::string _name;
    std::string _description;
    modality _md;
    std::optional<nlohmann::json> _metadata;
};
} // namespace exercise
