# CMakeList.txt: hello_cg 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

# 如果支持，请为 MSVC 编译器启用热重载。
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("hello_cg")

enable_testing()

find_package(FreeGLUT CONFIG REQUIRED)

# find_package(gtest CONFIG REQUIRED)
# target_link_libraries(main PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)
# add_test(AllTestsInMain main)

find_package(GTest REQUIRED)
find_package(boost REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(0_test)
add_subdirectory(1_show_rect)
add_subdirectory(2_bounce_animation)

# TODO: 如有需要，请添加测试并安装目标。
