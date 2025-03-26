add_subdirectory(fit-app)
add_subdirectory(storage)
add_executable(fitness-app main.cpp)
target_link_libraries(fitness-app PRIVATE fit-app storage Crow::Crow)
target_compile_features(fitness-app PRIVATE cxx_std_23)

include(FetchContent)
FetchContent_Declare(
    asio 
    GIT_REPOSITORY https://github.com/chriskohlhoff/asio
    GIT_TAG asio-1-34-0
)
FetchContent_MakeAvailable(asio)

set(ASIO_INCLUDE_DIR "${asio_SOURCE_DIR}/asio/include")

FetchContent_Declare(
    crow
    GIT_REPOSITORY https://github.com/CrowCpp/Crow
    GIT_TAG v1.2.1.2
)
FetchContent_MakeAvailable(crow)

FetchContent_Declare(
    nlohmann
    GIT_REPOSITORY https://github.com/nlohmann/json
    GIT_TAG v3.11.3
)
FetchContent_MakeAvailable(nlohmann)

target_link_libraries(fitness-app PRIVATE Crow::Crow nlohmann_json::nlohmann_json)
