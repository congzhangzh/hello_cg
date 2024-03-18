set(TARGET_NAME hello_animation)
add_executable(${TARGET_NAME} "hello_animation.cpp" "hello_animation.h" ../include/common/thunks.hpp)
target_link_libraries(${TARGET_NAME} PRIVATE $<IF:$<TARGET_EXISTS:FreeGLUT::freeglut>,FreeGLUT::freeglut,FreeGLUT::freeglut_static>)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${TARGET_NAME} PROPERTY CXX_STANDARD 20)
endif()
