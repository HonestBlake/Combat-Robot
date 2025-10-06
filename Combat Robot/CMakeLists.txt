cmake_minimum_required(VERSION 4.0.2)
project(
    "CombatRobot"
    VERSION 0.0.0
    DESCRIPTION "Combat Robot"
    LANGUAGES CXX C
)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_USE_RESPONSE_FILE_FOR_INCLUDES OFF)

set(ELF_FILE "${CMAKE_CURRENT_BINARY_DIR}/CombatRobot.elf")
set(HEX_FILE "${CMAKE_CURRENT_SOURCE_DIR}/CombatRobot.hex")

set(SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/combatRobot/source")
set(SOURCE_FILES 
    "${SOURCE_DIR}/device.cpp"
    "${SOURCE_DIR}/pins.cpp"
    "${SOURCE_DIR}/pwm.cpp"
    "${SOURCE_DIR}/motors.cpp"
)
set(INCLUDE_DIR
    "${CMAKE_CURRENT_SOURCE_DIR}/combatRobot/header"
    "${CMAKE_CURRENT_SOURCE_DIR}/combatRobot/source"
    "${CMAKE_CURRENT_SOURCE_DIR}/combatRobot"
)
add_executable(CombatRobot 
    "combatRobot/main.cpp"
    ${SOURCE_FILES}
)
target_include_directories(CombatRobot PRIVATE ${INCLUDE_DIR})
set_target_properties(CombatRobot PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build"
    OUTPUT_NAME "CombatRobot"
    SUFFIX ".elf"
)


# Add a custom command to generate the .hex file from the .elf file
add_custom_command(
    OUTPUT "${HEX_FILE}"
    COMMAND "${CMAKE_OBJCOPY}" -O ihex "${ELF_FILE}" "${HEX_FILE}"
    DEPENDS CombatRobot
    COMMENT "Converting CombatRobot.elf to CombatRobot.hex"
    VERBATIM
)

find_program(CMAKE_OBJCOPY NAMES msp430-elf-objcopy PATHS "C:/ti/msp430-gcc/bin" REQUIRED)
add_custom_target(hex ALL DEPENDS "${HEX_FILE}")