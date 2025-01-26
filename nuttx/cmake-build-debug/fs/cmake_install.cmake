# Install script for directory: /Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/fs

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/fs/libfs.a")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/fs/aio/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/fs/binfs/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/fs/cromfs/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/fs/driver/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/fs/event/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/fs/fat/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/fs/hostfs/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/fs/inode/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/fs/littlefs/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/fs/mmap/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/fs/mnemofs/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/fs/mount/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/fs/mqueue/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/fs/nfs/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/fs/notify/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/fs/nxffs/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/fs/partition/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/fs/procfs/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/fs/romfs/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/fs/rpmsgfs/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/fs/semaphore/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/fs/shm/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/fs/smartfs/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/fs/socket/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/fs/spiffs/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/fs/tmpfs/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/fs/unionfs/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/fs/userfs/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/fs/v9fs/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/fs/vfs/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/fs/zipfs/cmake_install.cmake")
endif()

