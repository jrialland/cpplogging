cmake_minimum_required(VERSION 3.5)

#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "--std=c++17 -Wfatal-errors")

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 

find_package(Boost 1.45.0 COMPONENTS regex) 

file(GLOB_RECURSE SOURCES
    ./src/*.cpp
)

file(GLOB_RECURSE TEST_SOURCES
    ./test/*.cpp
)

INCLUDE_DIRECTORIES(
    ./src
)

add_library(cpplogging STATIC ${SOURCES})

add_executable(unittests ${TEST_SOURCES})
target_link_libraries(unittests cpplogging)
target_link_libraries(unittests dl)
target_link_libraries(unittests Threads::Threads)
target_link_libraries(unittests ${Boost_LIBRARIES})

enable_testing()
add_test(NAME UnitTests COMMAND ./unittests)