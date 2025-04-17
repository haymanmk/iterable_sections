function(add_linker_subsection subsection_name)
    set_property(
        TARGET linker
        APPEND
        PROPERTY SUB_SECT_NAME
        ${subsection_name}
    )

    # print the subsection name
    get_property(_subsection_name TARGET linker PROPERTY SUB_SECT_NAME)
    message(STATUS "linker subsection name: ${_subsection_name}")
endfunction()

# create linker script
function(create_linker_script)
    get_property(_subsection_name TARGET linker PROPERTY SUB_SECT_NAME)
    
    # path to linker script template
    set(LINKER_SCRIPT_TEMPLATE "${CMAKE_CURRENT_SOURCE_DIR}/rom_sections.ld.in")
    # path to linker script output
    set(LINKER_SCRIPT_OUTPUT "${CMAKE_CURRENT_SOURCE_DIR}/rom_sections.ld")

    set(SUB_SECTIONS "")

    # iterate over the subsection names
    foreach(subsect_name ${_subsection_name})
        string(APPEND SUB_SECTIONS
            "${subsect_name} :\n"
            "{\n"
            "  __${subsect_name}_start = .;\n"
            "  KEEP(*(${subsect_name}*))\n"
            "  __${subsect_name}_end = .;\n"
            "} > FLASH\n"
        )
    endforeach()

    # replace the placeholder in the linker script template
    configure_file(
        ${LINKER_SCRIPT_TEMPLATE}
        ${LINKER_SCRIPT_OUTPUT}
    )
endfunction()