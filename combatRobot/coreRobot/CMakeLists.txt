set(ELF_FILE "${ROOT_DIR}/build/coreRobot.elf")
set(HEX_FILE "${ROOT_DIR}/coreRobot.hex")

set(CORE_ROBOT_INCLUDE_DIR
    "${CORE_ROBOT}"
    "${CORE_ROBOT}/header"
    "${CORE_ROBOT}/source"
)
set(CORE_ROBOT_SOURCE_FILES
    "${CORE_ROBOT}/main.cpp"
    "${CORE_ROBOT}/source/robot.cpp"
)

add_executable(CoreRobot
    ${CORE_ROBOT_SOURCE_FILES}
    ${SOURCE_FILES}
)
target_include_directories(CoreRobot PRIVATE
    ${CORE_ROBOT_INCLUDE_DIR}
    ${INCLUDE_DIR}
)
set_target_properties(CoreRobot PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${ROOT_DIR}/build"
    OUTPUT_NAME "coreRobot"
    SUFFIX ".elf"
)

# Add a custom command to generate the CoreRobot.hex file from the CoreRobot.elf file
add_custom_command(
    OUTPUT "${HEX_FILE}"
    COMMAND "${CMAKE_OBJCOPY}" -O ihex "${ELF_FILE}" "${HEX_FILE}"
    DEPENDS CoreRobot
    COMMENT "Converting combatRobot.elf to combatRobot.hex"
    VERBATIM
)
find_program(CMAKE_OBJCOPY NAMES msp430-elf-objcopy PATHS "C:/ti/msp430-gcc/bin" REQUIRED)
add_custom_target(CoreRobotHex ALL DEPENDS "${HEX_FILE}")