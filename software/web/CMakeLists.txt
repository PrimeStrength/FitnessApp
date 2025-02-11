# To prevent running npm install every time we run CMake, we check for
# the existence of a file that we make only after running npm install.

if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/node_modules/sentinel.txt")
  message("-- Running npm install")
  execute_process(
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMAND npm install
    OUTPUT_VARIABLE __npm_output
    ERROR_VARIABLE __npm_error
    ECHO_OUTPUT_VARIABLE
  )
  execute_process(
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMAND touch "${CMAKE_CURRENT_SOURCE_DIR}/node_modules/sentinel.txt"
  )
endif()


# There are no nice ways to integrate NPM into CMake, so we do it by
# hand.
#
# We create a target consisting of the build artefacts

file(GLOB_RECURSE public  "${CMAKE_CURRENT_SOURCE_DIR}/public/*")
file(GLOB_RECURSE web_src  "${CMAKE_CURRENT_SOURCE_DIR}/src/*")

set(web_build_dir "${CMAKE_CURRENT_BINARY_DIR}/dist")
file(MAKE_DIRECTORY ${web_build_dir})
add_custom_command(
  OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/dist/index.html"
  COMMAND npm run build
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  DEPENDS "${web_src};${public};${CMAKE_CURRENT_SOURCE_DIR}/index.html;${CMAKE_CURRENT_SOURCE_DIR}/package.json"
)

message(${CMAKE_CURRENT_BINARY_DIR}/dist/index.html)

add_custom_target(web
  DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/dist/index.html
)
