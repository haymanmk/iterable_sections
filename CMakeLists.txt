cmake_minimum_required(VERSION 3.20)

project(IterableSections
    VERSION 1.0
    LANGUAGES C
)

add_custom_target(linker)

include(extensions.cmake)

# add subsections
add_linker_subsection("service_1")
add_linker_subsection("service_2")
create_linker_script()

# include source files
file(GLOB_RECURSE SOURCES
    "src/*.c"
)

# set the path to a custom linker script
set(LINKER_SCRIPT "${CMAKE_SOURCE_DIR}/rom_sections.ld")

# add the executable target
add_executable(${PROJECT_NAME}
    ${SOURCES}
)

target_link_options(
    ${PROJECT_NAME}
    PRIVATE
    -T${LINKER_SCRIPT}
    LINKER:-Map=${CMAKE_SOURCE_DIR}/build/${PROJECT_NAME}.map
)