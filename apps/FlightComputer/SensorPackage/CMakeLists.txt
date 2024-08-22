# ##############################################################################
# FlightComputer/SensorPackage/CMakeLists.txt
#
# Licensed to the Apache Software Foundation (ASF) under one or more contributor
# license agreements.  See the NOTICE file distributed with this work for
# additional information regarding copyright ownership.  The ASF licenses this
# file to you under the Apache License, Version 2.0 (the "License"); you may not
# use this file except in compliance with the License.  You may obtain a copy of
# the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
# License for the specific language governing permissions and limitations under
# the License.
#
# ##############################################################################

if(CONFIG_FLIGHTCOMPUTER_SENSORPACKAGE)

  # Collect sensor source files from each directory
  file(GLOB ICMSRC ${CMAKE_CURRENT_SOURCE_DIR}/ICM42688/*.cxx)
  file(GLOB LPSSRC ${CMAKE_CURRENT_SOURCE_DIR}/LPS25/*.cxx)
  file(GLOB MSSRC  ${CMAKE_CURRENT_SOURCE_DIR}/MS5611/*.cxx)
  file(GLOB GPSSRC ${CMAKE_CURRENT_SOURCE_DIR}/MAX10S/*.cxx)

  # Define the application and its properties
  nuttx_add_application(
    NAME
    ${CONFIG_FLIGHTCOMPUTER_SENSORPACKAGE_PROGNAME}
    PRIORITY
    ${CONFIG_FLIGHTCOMPUTER_SENSORPACKAGE_PRIORITY}
    STACKSIZE
    ${CONFIG_FLIGHTCOMPUTER_SENSORPACKAGE_STACKSIZE}
    MODULE
    ${CONFIG_FLIGHTCOMPUTER_SENSORPACKAGE}
    
    # Main source file
    SRCS
    SensorPackage.cxx
    ${ICMSRC}
    ${LPSSRC}
    ${MSSRC}
    ${GPSSRC}
  )

  # Add include directories
  target_include_directories(${CONFIG_FLIGHTCOMPUTER_SENSORPACKAGE_PROGNAME} PRIVATE
    ${APPDIR}/FlightComputer/FlightLib
  )

  # Link against the FlightLib library if necessary
  target_link_libraries(${CONFIG_FLIGHTCOMPUTER_SENSORPACKAGE_PROGNAME} PRIVATE
    flightlib
  )
  
endif()
