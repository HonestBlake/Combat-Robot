# # Toolchain file for MSP430 GCC
# set(CMAKE_SYSTEM_NAME Generic)
# set(CMAKE_SYSTEM_PROCESSOR msp430)

# # Specify compilers
# set(CMAKE_C_COMPILER   "msp430-elf-gcc")
# set(CMAKE_CXX_COMPILER "msp430-elf-g++")
# set(CMAKE_ASM_COMPILER "msp430-elf-gcc")

# # Specify flags
# set(CMAKE_C_FLAGS "-mmcu=msp430fr6989 -I\"C:\\Program Files\\ti\\msp430-GCC\\include\"")
# set(CMAKE_CXX_FLAGS "-mmcu=msp430fr6989 -I\"C:\\Program Files\\ti\\msp430-GCC\\include\"")
# set(CMAKE_EXE_LINKER_FLAGS "-mmcu=msp430fr6989")

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR msp430)

set(MSP430_TOOLCHAIN_PATH "C:/Program Files/ti/msp430-GCC")

set(CMAKE_C_COMPILER   "${MSP430_TOOLCHAIN_PATH}/bin/msp430-elf-gcc.exe")
set(CMAKE_CXX_COMPILER "${MSP430_TOOLCHAIN_PATH}/bin/msp430-elf-g++.exe")
set(CMAKE_AR          "${MSP430_TOOLCHAIN_PATH}/bin/msp430-elf-ar.exe")
set(CMAKE_RANLIB      "${MSP430_TOOLCHAIN_PATH}/bin/msp430-elf-ranlib.exe")

set(CMAKE_C_FLAGS_INIT "-mmcu=msp430fr6989 -I\"C:\\Program Files\\ti\\msp430-GCC\\include\" -L\"C:\\Program Files\\ti\\msp430-GCC\\include\"")
set(CMAKE_CXX_FLAGS_INIT "-mmcu=msp430fr6989 -I\"C:\\Program Files\\ti\\msp430-GCC\\include\" -L\"C:\\Program Files\\ti\\msp430-GCC\\include\"")

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)