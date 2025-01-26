# Install script for directory: /Users/frostydev/workspace/MQP/Vanguard-RTOS/apps

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "TRUE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "arm-none-eabi-objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/libapps.a")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/benchmarks/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/boot/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/canutils/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/crypto/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/fsutils/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/games/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/graphics/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/industry/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/interpreters/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/logging/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/lte/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/math/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/mlearning/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/modbus/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/netutils/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/nshlib/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/platform/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/sdr/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/system/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/testing/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/tools/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/wireless/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/FlightComputer/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/examples/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/builtin/cmake_install.cmake")
endif()

