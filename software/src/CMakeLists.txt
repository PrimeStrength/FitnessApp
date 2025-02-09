
include(FetchContent)

# Nlohmann
FetchContent_Declare(
  nlohmann
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG        v3.11.3
  GIT_SHALLOW    TRUE
)
FetchContent_MakeAvailable(nlohmann)

# ASIO (For CrowCPP)
FetchContent_Declare(
  asio
  GIT_REPOSITORY https://github.com/chriskohlhoff/asio.git
  GIT_TAG        asio-1-32-0
  GIT_SHALLOW    TRUE
)
set(ASIO_INCLUDE_DIR "${BUILD_DIR}/_deps/asio-src/asio/include/")
FetchContent_MakeAvailable(asio)

# CrowCPP
FetchContent_Declare(
  crowcpp
  GIT_REPOSITORY https://github.com/crowcpp/crow.git
  GIT_TAG        v1.2.0
  GIT_SHALLOW    TRUE
)
FetchContent_MakeAvailable(crowcpp)


add_executable(FitnessApp
  main.cpp
)

target_compile_definitions(FitnessApp PRIVATE ASIO_STANDALONE)

target_link_libraries(FitnessApp
  nlohmann_json::nlohmann_json
  Crow::Crow
)
