project("memcached-ebbrt" CXX)
cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
set(CMAKE_CXX_FLAGS_DEBUG          "-O0 -g3")
set(CMAKE_CXX_FLAGS_MINSIZEREL     "-Os -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE        "-O4 -flto -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g3")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++14 -Wall -Werror")

include_directories(${PROJECT_SRC_DIR})
add_executable(netpipek.elf src/netpipek.cc)

add_custom_command(TARGET netpipek.elf POST_BUILD 
  COMMAND objcopy -O elf32-i386 netpipek.elf netpipek.elf32 )
