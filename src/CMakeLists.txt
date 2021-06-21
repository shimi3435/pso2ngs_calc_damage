file(GLOB libraries *.cpp)
add_library(calc_attack_damage STATIC ${libraries})

target_include_directories(calc_attack_damage PRIVATE ${PROJECT_SOURCE_DIR}/include)
