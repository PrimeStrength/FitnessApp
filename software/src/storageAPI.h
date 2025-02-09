#pragma once
#include "nlohmann/json.hpp"
#include <expected>


namespace storage { 
    using json = nlohmann::json;
    std::expected<void, std::string> create(json js);
}
