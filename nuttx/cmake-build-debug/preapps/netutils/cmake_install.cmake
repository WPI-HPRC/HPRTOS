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

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/preapps/netutils/chat/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/preapps/netutils/cjson/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/preapps/netutils/codecs/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/preapps/netutils/connectedhomeip/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/preapps/netutils/dhcp6c/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/preapps/netutils/dhcpc/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/preapps/netutils/dhcpd/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/preapps/netutils/discover/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/preapps/netutils/esp8266/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/preapps/netutils/ftpc/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/preapps/netutils/ftpd/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/preapps/netutils/iperf/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/preapps/netutils/jsoncpp/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/preapps/netutils/libcoap/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/preapps/netutils/libcurl4nx/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/preapps/netutils/netcat/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/preapps/netutils/netinit/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/preapps/netutils/netlib/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/preapps/netutils/ntpclient/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/preapps/netutils/ping/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/preapps/netutils/pppd/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/preapps/netutils/rexec/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/preapps/netutils/rexecd/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/preapps/netutils/smtp/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/preapps/netutils/telnetc/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/preapps/netutils/telnetd/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/preapps/netutils/tftpc/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/preapps/netutils/thttpd/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/preapps/netutils/wakaama/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/preapps/netutils/wakeonlan/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/preapps/netutils/webclient/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/preapps/netutils/webserver/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/frostydev/workspace/MQP/Vanguard-RTOS/nuttx/cmake-build-debug/preapps/netutils/xmlrpc/cmake_install.cmake")
endif()

