add_library(fit-app Excerise.cpp processes.cpp Session.cpp Set.cpp)
target_include_directories(fit-app PUBLIC .)
target_link_libraries(fit-app PRIVATE nlohmann_json::nlohmann_json storage)
target_compile_features(fit-app PRIVATE cxx_std_23)
