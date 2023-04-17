CMAKE_MINIMUM_REQUIRED(VERSION 3.5)
project(app)

set (${PROJECT_NAME}_VERSION_MAJOR 1)
set (${PROJECT_NAME}_VERSION_MINOR 2)
set (${PROJECT_NAME}_VERSION_PATCH 3)
set (${PROJECT_NAME}_VERSION_TWEAK 4)
set (${PROJECT_NAME}_VERSION "${${PROJECT_NAME}_VERSION_MAJOR}.${${PROJECT_NAME}_VERSION_MINOR}.${${PROJECT_NAME}_VERSION_PATCH}.${${PROJECT_NAME}_VERSION_TWEAK}")

file(GLOB CPP_SOURCES ${CMAKE_SOURCE_DIR}/myLib/src/*.cpp)


include_directories("${PROJECT_SOURCE_DIR}/myLib/include")
include_directories("${PROJECT_BINARY_DIR}/../myLib/include")

add_executable(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/src/main.cpp ${CPP_SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE myLib/include)

add_library(${PROJECT_NAME}_lib 
	STATIC ${CMAKE_SOURCE_DIR}/myLib/src/App.cpp ${CMAKE_SOURCE_DIR}/myLib/src/PacketStats.cpp ${CMAKE_SOURCE_DIR}/myLib/src/CollectionStatistics.cpp) 

target_include_directories(${PROJECT_NAME}_lib PUBLIC
${CMAKE_SOURCE_DIR}/../PcapPlusPlus/Packet++/header
${CMAKE_SOURCE_DIR}/../PcapPlusPlus/Pcap++/header
${CMAKE_SOURCE_DIR}/../PcapPlusPlus/Common++/header
${CMAKE_SOURCE_DIR}/myLib/include
)

target_link_libraries(${PROJECT_NAME}_lib PUBLIC
${CMAKE_SOURCE_DIR}/../../../../../usr/local/lib/libPacket++.a 
${CMAKE_SOURCE_DIR}/../../../../../usr/local/lib/libPcap++.a
${CMAKE_SOURCE_DIR}/../../../../../usr/local/lib/libCommon++.a
-lpcap)

target_include_directories(${PROJECT_NAME}_lib 
	PUBLIC ${PROJECT_SOURCE_DIR}/src)

target_link_libraries(${PROJECT_NAME} 
	PUBLIC ${PROJECT_NAME}_lib)

