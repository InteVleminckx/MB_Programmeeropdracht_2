set(SRC CFG.cpp main.cpp)
add_executable(MB ${SRC})
install(TARGETS MB DESTINATION ${PROJECT_SOURCE_DIR}/bin)

