cmake_minimum_required(VERSION 3.11)
project(jcbm CXX) #[J] JSON, [C] C++, [B] Benchmark, [M] Measure

##########################################################################
# general settings
##########################################################################
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#add_compile_options(-fpermissive)

##########################################################################
# dependent packages
##########################################################################
include(FetchContent)
message(STATUS "Fetch RapidJSON")
FetchContent_Declare(
	rapidjson
	GIT_REPOSITORY "https://github.com/Tencent/rapidjson"
	GIT_TAG        "v1.1.0"
)
message(STATUS "Fetch RapidJSON - done")

message(STATUS "Make RapidJSON available")
FetchContent_GetProperties(rapidjson)
if(NOT rapidjson_POPULATED)
	FetchContent_Populate(rapidjson)

	# Set build options for RapidJSON
	set(RAPIDJSON_BUILD_DOC OFF CACHE BOOL "" FORCE)
	set(RAPIDJSON_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
	set(RAPIDJSON_BUILD_TESTS OFF CACHE BOOL "" FORCE)
	set(RAPIDJSON_BUILD_THIRDPARTY_GTEST OFF CACHE BOOL "" FORCE)
	set(RAPIDJSON_BUILD_CXX11 OFF CACHE BOOL "" FORCE)
	set(RAPIDJSON_BUILD_CXX17 ON CACHE BOOL "" FORCE)
	set(RAPIDJSON_BUILD_CXX20 OFF CACHE BOOL "" FORCE)
	set(RAPIDJSON_BUILD_ASAN OFF CACHE BOOL "" FORCE)
	set(RAPIDJSON_BUILD_UBSAN OFF CACHE BOOL "" FORCE)

	add_subdirectory(${rapidjson_SOURCE_DIR} ${rapidjson_BINARY_DIR})
endif()
message(STATUS "Make RapidJSON available - done")

##########################################################################
# automatic code generations
##########################################################################
set(GEN_SRC
	${PROJECT_SOURCE_DIR}/src/version.cpp
)
add_custom_command(
	OUTPUT ${GEN_SRC}
	COMMAND bash "${PROJECT_SOURCE_DIR}/script/version.sh"
	COMMENT "Try to update version"
)
add_custom_target(GEN_TARGET DEPENDS ${GEN_SRC})

##########################################################################
# build main applicaiton
##########################################################################
set(MAIN_APP "jcbm")
add_executable(${MAIN_APP}
	${GEN_SRC}
	src/main.cpp
	src/base/functional.cpp
	src/impl/rapidjson.cpp
)
add_dependencies(${MAIN_APP} GEN_TARGET)
target_include_directories(${MAIN_APP} PRIVATE
	${rapidjson_SOURCE_DIR}/include
	src
)
