#pragma once

#include <optional>
#include "nlohmann/json.hpp"

namespace exercise
{

class Rep
{
    using json = nlohmann::json;

public:
    explicit Rep(int weight) : m_weight{weight} {}

    Rep(int weight, int duration)
        : m_weight{weight}
        , m_duration_secs{duration}
    {
    }

    friend void to_json(json& j, const Rep& rep);
    friend void from_json(const json& j, Rep& rep);

    int get_weight() const;
    std::optional<int> get_duration_s() const;

private:
    // m_weight could be renamed to m_intensity,
    // but weight is more explicit for the current cycle of the project
    int m_weight{};
    // Storinig the duration of a rep unlikely used
    std::optional<int> m_duration_secs{};
};

} // namespace exercise
