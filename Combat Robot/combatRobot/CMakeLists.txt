set(CORE_ROBOT "${COMBAT_ROBOT}/coreRobot")
set(REMOTE_CONTROLLER "${COMBAT_ROBOT}/remoteController")

set(SOURCE_FILES 
    "${COMBAT_ROBOT}/source/device.cpp"
    "${COMBAT_ROBOT}/source/pins.cpp"
    "${COMBAT_ROBOT}/source/motors.cpp"
)
set(INCLUDE_DIR
    ${COMBAT_ROBOT}
    "${COMBAT_ROBOT}/header"
    "${COMBAT_ROBOT}/source"
)

add_subdirectory(${CORE_ROBOT})
add_subdirectory(${REMOTE_CONTROLLER})