# Dependencies ################################################################
include(FetchContent)

# Nlohmann json
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
FetchContent_MakeAvailable(asio)
# CrowCPP complains if this variable is not set.
set(ASIO_INCLUDE_DIR "${asio_SOURCE_DIR}/asio/include/")

# CrowCPP
## Don't package crow files.
set(CROW_INSTALL OFF)
FetchContent_Declare(
  crowcpp
  GIT_REPOSITORY https://github.com/crowcpp/crow.git
  GIT_TAG        v1.2.0
  GIT_SHALLOW    TRUE
)
FetchContent_MakeAvailable(crowcpp)

# FitnessApp ##################################################################

# Define the executable with its translation units
add_executable(FitnessApp
  main.cpp
  Excerise.cpp
  Session.cpp
  Set.cpp
  storageAPI.cpp
  processes.cpp
)

# Link libraries with FitnessApp
target_link_libraries(FitnessApp
  PRIVATE
    nlohmann_json::nlohmann_json
    Crow::Crow
)

install(
  TARGETS FitnessApp
  DESTINATION usr/bin
)
