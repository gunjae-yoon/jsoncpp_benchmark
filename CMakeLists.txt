cmake_minimum_required(VERSION 3.8)
project(jcbm CXX) #[J] JSON, [C] C++, [B] Benchmark, [M] Measure

set(CMAKE_CXX_STANDARD 17)

#add_compile_options(-fpermissive)

# automatic code generations
set(GEN_SRC
	${PROJECT_SOURCE_DIR}/src/version.cpp
)
add_custom_command(
	OUTPUT ${GEN_SRC}
	COMMAND bash "${PROJECT_SOURCE_DIR}/script/version.sh"
	COMMENT "Try to update version"
)
add_custom_target(GEN_TARGET DEPENDS ${GEN_SRC})

# build main applicaiton
set(MAIN_APP "jcbm")
add_executable(${MAIN_APP}
	${GEN_SRC}
	src/main.cpp
)
add_dependencies(${MAIN_APP} GEN_TARGET)
target_include_directories(${MAIN_APP} PRIVATE
	src
)
