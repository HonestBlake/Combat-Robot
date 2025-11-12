set(ELF_FILE "${ROOT_DIR}/build/remoteController.elf")
set(HEX_FILE "${ROOT_DIR}/remoteController.hex")

set(REMOTE_CONTROLLER_INCLUDE_DIR
    "${REMOTE_CONTROLLER}"
    "${REMOTE_CONTROLLER}/header"
    "${REMOTE_CONTROLLER}/source"
)
set(REMOTE_CONTROLLER_SOURCE_FILES
    "${REMOTE_CONTROLLER}/main.cpp"
    "${REMOTE_CONTROLLER}/source/remote.cpp"
)
    
add_executable(RemoteController
    ${REMOTE_CONTROLLER_SOURCE_FILES}
    ${SOURCE_FILES}
)
target_include_directories(RemoteController PRIVATE
    ${REMOTE_CONTROLLER_INCLUDE_DIR}
    ${INCLUDE_DIR}
)
set_target_properties(RemoteController PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${ROOT_DIR}/build"
    OUTPUT_NAME "remoteController"
    SUFFIX ".elf"
)

# Add a custom command to generate the RemoteController.hex file from the RemoteController.elf file
add_custom_command(
    OUTPUT "${HEX_FILE}"
    COMMAND "${CMAKE_OBJCOPY}" -O ihex "${ELF_FILE}" "${HEX_FILE}"
    DEPENDS RemoteController
    COMMENT "Converting remoteController.elf to remoteController.hex"
    VERBATIM
)
find_program(CMAKE_OBJCOPY NAMES msp430-elf-objcopy PATHS "C:/ti/msp430-gcc/bin" REQUIRED)
add_custom_target(RemoteControllerHex ALL DEPENDS "${HEX_FILE}")