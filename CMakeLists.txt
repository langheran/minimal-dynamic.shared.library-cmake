cmake_minimum_required(VERSION 3.2)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE STRING "VSCode Intellisense" FORCE)
set(CMAKE_C_COMPILER "C:/Program Files (x86)/Microsoft Visual Studio 14.0/VC/bin/amd64/cl.exe")
set(CMAKE_CXX_COMPILER "C:/Program Files (x86)/Microsoft Visual Studio 14.0/VC/bin/amd64/cl.exe")

set(target_name module)
project(${target_name} LANGUAGES C CXX)

if(MSVC)
	set(CMAKE_CXX_FLAGS "/FS /EHsc /FC") # No pdb concurrency, no warnings, full paths for $msCompile problemMatcher.
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /ASSEMBLYDEBUG /DEBUG") # Linker flags for debugger.
endif()

set (CMAKE_CXX_STANDARD 11)

set(SOURCE
			module.cpp
	)

set(HEADERS
			module.h
	)

add_library(${target_name} SHARED ${SOURCE} ${HEADERS}) # SHARED libraries are intended for other targets to link against, whereas MODULE libraries are not.

add_executable(debug debug.cpp ${HEADERS})
target_link_libraries(debug ${target_name})

set_target_properties(${target_name} PROPERTIES
 FRAMEWORK TRUE
 PUBLIC_HEADER ${HEADERS}
) # for MacOS