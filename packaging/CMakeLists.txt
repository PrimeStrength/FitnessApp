set(CPACK_PACKAGE_CONTACT "Andrew Dalley")
set(CPACK_STRIP_FILES TRUE)
set(CPACK_PACKAGE_VENDOR "PrimeStrength")
set(CPACK_PACKAGE_DEPENDS "")

add_subdirectory(debian)
add_subdirectory(archive)

include(CPack)
