cmake_minimum_required(VERSION 3.22)

#
# This file is generated only once,
# and is not re-generated if converter is called multiple times.
#
# User is free to modify the file as much as necessary
#

# Setup compiler settings
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)


# Define the build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

# Set the project name
set(CMAKE_PROJECT_NAME wired_mouse)

# Enable compile command to ease indexing with e.g. clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

# Core project settings
project(${CMAKE_PROJECT_NAME})
message("Build type: " ${CMAKE_BUILD_TYPE})

# Enable CMake support for ASM and C languages
enable_language(C ASM)

# Create an executable object type
add_executable(${CMAKE_PROJECT_NAME}
        bsp/Inc/bsp_key.h
        bsp/Inc/bsp.h
        bsp/Src/bsp.c
        bsp/Src/bsp_key.c
        bsp/Inc/bsp_encoder.h
        bsp/Src/bsp_encoder.c
        bsp/Inc/bsp_ws2812.h
        bsp/Src/bsp_ws2812.c
        bsp/Inc/bsp_delay.h
        bsp/Src/bsp_delay.c
        bsp/Inc/bsp_spi.h
        bsp/Src/bsp_spi.c
        bsp/Inc/bsp_paw3395.h
        bsp/Src/bsp_paw3395.c
        User/Src/threadx_tasks.c
        User/Inc/threadx_tasks.h
        User/Src/threadx_ws2812.c
        User/Inc/threadx_ws2812.h
        User/Inc/threadx_encoder.h
        User/Src/threadx_encoder.c
        User/Inc/threadx_key.h
        User/Src/threadx_key.c
        User/Inc/threadx_pc.h
        User/Src/threadx_pc.c
        bsp/Inc/bsp_cathe.h
        bsp/Src/bsp_cathe.c
)

# Add STM32CubeMX generated sources
add_subdirectory(cmake/stm32cubemx)

# Link directories setup
target_link_directories(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined library search paths
)

# Add sources to executable
target_sources(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user sources here
        bsp/Src/bsp.c
        bsp/Src/bsp_key.c
        bsp/Src/bsp_encoder.c
        bsp/Src/bsp_ws2812.c
        bsp/Src/bsp_delay.c
        bsp/Src/bsp_spi.c
        bsp/Src/bsp_paw3395.c
        User/Src/threadx_encoder.c
        User/Src/threadx_key.c
        User/Src/threadx_pc.c
        User/Src/threadx_tasks.c
        User/Src/threadx_ws2812.c
)

# Add include paths
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined include paths
        bsp/Inc
        User/Inc
)

# Add project symbols (macros)
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined symbols
)

# Remove wrong libob.a library dependency when using cpp files
list(REMOVE_ITEM CMAKE_C_IMPLICIT_LINK_LIBRARIES ob)

# Add linked libraries
target_link_libraries(${CMAKE_PROJECT_NAME}
    stm32cubemx

    # Add user defined libraries
)
