add_library(storage storageAPI.cpp)
target_include_directories(storage PUBLIC .)
target_link_libraries(storage PRIVATE nlohmann_json)
target_compile_features(storage PRIVATE cxx_std_23)
