# Install script for directory: /Users/frostydev/workspace/MQP/Vanguard-RTOS/apps/fsutils

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

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/preapps/fsutils/flash_eraseall/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/preapps/fsutils/inifile/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/preapps/fsutils/inih/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/preapps/fsutils/ipcfg/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/preapps/fsutils/libtinycbor/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/preapps/fsutils/mkfatfs/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/preapps/fsutils/mkgpt/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/preapps/fsutils/mkmbr/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/preapps/fsutils/mksmartfs/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/preapps/fsutils/passwd/cmake_install.cmake")
endif()

