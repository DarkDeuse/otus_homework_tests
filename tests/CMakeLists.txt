include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


set(COMMON_SRCS
    "../list.hpp"
    "../serial.hpp"
)

add_executable(list_test list_tests.cpp ${COMMON_SRCS})
target_include_directories(list_test PUBLIC ${CMAKE_SOURCE_DIR})
target_link_libraries(list_test PUBLIC gtest gtest_main)
add_executable(serial_test serial_tests.cpp ${COMMON_SRCS})
target_include_directories(serial_test PUBLIC ${CMAKE_SOURCE_DIR})
target_link_libraries(serial_test PUBLIC gtest gtest_main)
