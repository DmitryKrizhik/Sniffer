CMAKE_MINIMUM_REQUIRED(VERSION 3.5)
project(app)

set (${PROJECT_NAME}_VERSION_MAJOR 1)
set (${PROJECT_NAME}_VERSION_MINOR 2)
set (${PROJECT_NAME}_VERSION_PATCH 3)
set (${PROJECT_NAME}_VERSION_TWEAK 4)
set (${PROJECT_NAME}_VERSION "${${PROJECT_NAME}_VERSION_MAJOR}.${${PROJECT_NAME}_VERSION_MINOR}.${${PROJECT_NAME}_VERSION_PATCH}.${${PROJECT_NAME}_VERSION_TWEAK}")

file(GLOB CPP_SOURCES ${CMAKE_SOURCE_DIR}/SnifferLibrary/src/*.cpp)

add_executable(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/src/main.cpp ${CPP_SOURCES})
add_library(SnifferLib
STATIC ${CMAKE_SOURCE_DIR}/SnifferLibrary/src/App.cpp ${CMAKE_SOURCE_DIR}/SnifferLibrary/src/PacketStats.cpp) 


target_include_directories(${PROJECT_NAME} PUBLIC SnifferLibrary/include)

target_include_directories(SnifferLib PRIVATE 
${CMAKE_SOURCE_DIR}/SnifferLibrary/Logger/ 
)

target_include_directories(SnifferLib PUBLIC
${CMAKE_SOURCE_DIR}/../PcapPlusPlus/Packet++/header
${CMAKE_SOURCE_DIR}/../PcapPlusPlus/Pcap++/header
${CMAKE_SOURCE_DIR}/../PcapPlusPlus/Common++/header
${CMAKE_SOURCE_DIR}/SnifferLibrary/include
${CMAKE_SOURCE_DIR}/SnifferLibrary/Logger
)

target_include_directories(SnifferLib
	PUBLIC ${PROJECT_SOURCE_DIR}/src)

target_link_libraries(${PROJECT_NAME} 
	PUBLIC SnifferLib)
include(FetchContent)
FetchContent_Declare(PcapPlusPlus
	GIT_REPOSITORY https://github.com/seladb/PcapPlusPlus.git
	SOURCE_DIR ${CMAKE_SOURCE_DIR}/external/PcapPlusPlus
	GIT_TAG master)
FetchContent_MakeAvailable(PcapPlusPlus)

target_link_libraries(SnifferLib
Pcap++
Packet++
Common++
)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/SnifferLibrary/Tests)

