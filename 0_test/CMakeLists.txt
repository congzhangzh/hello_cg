set(TARGET_NAME learn_by_test)

add_executable(${TARGET_NAME} thunks_test.cc ../include/common/thunks.hpp)
target_link_libraries(${TARGET_NAME} PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)

add_test(${TARGET_NAME} ${TARGET_NAME})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${TARGET_NAME} PROPERTY CXX_STANDARD 20)
endif()
