cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project("stress_spawn-ebbrt" C CXX)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
set(CMAKE_CXX_FLAGS_DEBUG          "-O0 -g3")
set(CMAKE_CXX_FLAGS_MINSIZEREL     "-Os -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE        "-O4 -flto -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g3")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++14 -Wall -Werror")

set(HOSTED_SOURCES
      src/hosted/stress_spawn.cc
      src/hosted/Printer.cc)

set(BAREMETAL_SOURCES
      src/baremetal/stress_spawn.cc
      src/baremetal/Printer.cc)

# Baremetal  ========================================================
if( ${CMAKE_SYSTEM_NAME} STREQUAL "EbbRT")
  add_executable(stress_spawn.elf ${BAREMETAL_SOURCES})
  add_custom_command(TARGET stress_spawn.elf POST_BUILD
    COMMAND objcopy -O elf32-i386 stress_spawn.elf stress_spawn.elf32 )

# Hosted  ===========================================================
elseif( ${CMAKE_SYSTEM_NAME} STREQUAL "Linux" )
  find_package(EbbRT REQUIRED)
  find_package(Boost 1.53.0 REQUIRED COMPONENTS
    filesystem system coroutine context )
  find_package(Capnp REQUIRED)
  find_package(TBB REQUIRED)
  find_package(Threads REQUIRED)

  include_directories(${EBBRT_INCLUDE_DIRS})
  add_executable(stress_spawn ${HOSTED_SOURCES})
  target_link_libraries(stress_spawn ${EBBRT_LIBRARIES}
    ${CAPNP_LIBRARIES_LITE} ${CMAKE_THREAD_LIBS_INIT}
    ${Boost_LIBRARIES} ${TBB_LIBRARIES}
  )
else()
  message(FATAL_ERROR "System name unsupported: ${CMAKE_SYSTEM_NAME}")
endif()
