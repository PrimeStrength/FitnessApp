#pragma once
#include "nlohmann/json.hpp"
//#include "tl/expected.hpp"
#include <expected>

using json = nlohmann::json;

namespace storage { 


	std::expected<void, std::string> create(json js);

}

