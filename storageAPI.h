#pragma once
#include "nlohmann/json.hpp"
#include "tl/expected.hpp"

using json = nlohmann::json;

namespace storage { 


	tl::expected<void, std::string> create(json js);

}

