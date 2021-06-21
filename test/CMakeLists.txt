add_executable(calc_damage.exe main.cpp)
target_include_directories(calc_damage.exe PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(calc_damage.exe calc_attack_damage)

install(TARGETS calc_damage.exe RUNTIME DESTINATION ./)
