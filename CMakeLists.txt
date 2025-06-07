cmake_minimum_required(VERSION 3.16)
project(koralibc VERSION 1.0.0 LANGUAGES C)

# Set C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Compiler flags for freestanding C (only for the library, not tests)
set(KORALIBC_C_FLAGS -nostdlib -ffreestanding -fno-builtin -Wall -Wextra -Werror -pedantic)

# Include directories
include_directories(include)

# Source files (will be populated as we add more modules)
set(KORALIBC_SOURCES
    src/string.c
    src/ctype.c
    src/stdlib.c
)

# Create static library
add_library(koralibc STATIC ${KORALIBC_SOURCES})
target_compile_options(koralibc PRIVATE ${KORALIBC_C_FLAGS})

# Create shared library
add_library(koralibc_shared SHARED ${KORALIBC_SOURCES})
set_target_properties(koralibc_shared PROPERTIES OUTPUT_NAME koralibc)
target_compile_options(koralibc_shared PRIVATE ${KORALIBC_C_FLAGS})

# Install headers
install(DIRECTORY include/kora DESTINATION include)

# Install libraries
install(TARGETS koralibc koralibc_shared
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)

# Testing
enable_testing()

# Find CMocka
find_package(PkgConfig)
if(PKG_CONFIG_FOUND)
    pkg_check_modules(CMOCKA cmocka)
endif()

if(CMOCKA_FOUND)
    # Test executables
    set(TEST_SOURCES
        tests/test_string.c
        tests/test_ctype.c
        tests/test_stdlib.c
    )

    foreach(test_source ${TEST_SOURCES})
        get_filename_component(test_name ${test_source} NAME_WE)
        add_executable(${test_name} ${test_source})
        
        # Link with our library and CMocka
        target_link_libraries(${test_name} 
            PRIVATE 
                koralibc 
                ${CMOCKA_LIBRARIES}
        )
        
        # Add include directories
        target_include_directories(${test_name} 
            PRIVATE 
                ${CMOCKA_INCLUDE_DIRS}
        )
        
        # Add compiler flags (normal compilation for tests)
        target_compile_options(${test_name} 
            PRIVATE 
                ${CMOCKA_CFLAGS_OTHER}
                -Wall -Wextra
        )
        
        # Register test
        add_test(NAME ${test_name} COMMAND ${test_name})
    endforeach()
    
    message(STATUS "CMocka found - tests will be built")
else()
    message(WARNING "CMocka not found - tests will not be built")
endif() 
