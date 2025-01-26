# ##############################################################################
# FlightComputer/StateMachine/CMakeLists.txt
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

if(CONFIG_FLIGHTCOMPUTER_STATEMACHINE)

    # Set the base directory for the StateMachine module
    set(BASEDIR ${CMAKE_CURRENT_SOURCE_DIR})

    # Collect sensor source files
    file(GLOB_RECURSE SENSORSRC ${BASEDIR}/sensors/**/*.cxx)

    # Define the application and its properties using nuttx_add_application
    nuttx_add_application(
            NAME ${CONFIG_FLIGHTCOMPUTER_STATEMACHINE_PROGNAME}
            PRIORITY ${CONFIG_FLIGHTCOMPUTER_STATEMACHINE_PRIORITY}
            STACKSIZE ${CONFIG_FLIGHTCOMPUTER_STATEMACHINE_STACKSIZE}
            MODULE ${CONFIG_FLIGHTCOMPUTER_STATEMACHINE}

            # Add the main StateMachine source file and sensor sources
            SRCS
            StateMachine.cxx
            ${SENSORSRC}

            # Specify the include directories
            INCLUDE_DIRECTORIES
            ${APPDIR}/FlightComputer/FlightLib
            ${BASEDIR}                       # Include current directory
            ${NUTTX_INCLUDE_DIRS}            # NuttX system include directories
            ${CMAKE_CXX_IMPLICIT_INCLUDE_DIRECTORIES}
            ${CMAKE_CXX_STANDARD_INCLUDE_DIRECTORIES}
    )

endif()
