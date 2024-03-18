set(TARGET_NAME hello_rect)
add_executable(${TARGET_NAME} "hello_cg.cpp" "hello_cg.h")
target_link_libraries(${TARGET_NAME} PRIVATE $<IF:$<TARGET_EXISTS:FreeGLUT::freeglut>,FreeGLUT::freeglut,FreeGLUT::freeglut_static>)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${TARGET_NAME} PROPERTY CXX_STANDARD 20)
endif()
