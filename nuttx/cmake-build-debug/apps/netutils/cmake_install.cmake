# Install script for directory: /Users/frostydev/workspace/MQP/Vanguard-RTOS/apps/netutils

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

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/netutils/chat/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/netutils/cjson/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/netutils/codecs/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/netutils/connectedhomeip/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/netutils/dhcp6c/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/netutils/dhcpc/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/netutils/dhcpd/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/netutils/discover/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/netutils/esp8266/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/netutils/ftpc/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/netutils/ftpd/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/netutils/iperf/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/netutils/jsoncpp/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/netutils/libcoap/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/netutils/libcurl4nx/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/netutils/netcat/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/netutils/netinit/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/netutils/netlib/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/netutils/ntpclient/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/netutils/ping/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/netutils/pppd/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/netutils/rexec/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/netutils/rexecd/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/netutils/smtp/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/netutils/telnetc/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/netutils/telnetd/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/netutils/tftpc/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/netutils/thttpd/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/netutils/wakaama/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/netutils/wakeonlan/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/netutils/webclient/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/netutils/webserver/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/apps/netutils/xmlrpc/cmake_install.cmake")
endif()

