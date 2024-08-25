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

if(CONFIG_FLIGHTCOMPUTER_SENSORPACKAGE)

    # Set the base directory to project folder
    set(BASEDIR ${CMAKE_CURRENT_SOURCE_DIR})

    # Collect source files from sensor libraries
    file(GLOB_RECURSE ICMSRC ${BASEDIR}/ICM42688/*.cxx)
    file(GLOB_RECURSE LPSSRC ${BASEDIR}/LPS25/*.cxx)
    file(GLOB_RECURSE MAGSRC ${BASEDIR}/MS5611/*.cxx)
    file(GLOB_RECURSE GPSSRC ${BASEDIR}/MAX10S/*.cxx)

    # Collect sources
    set(SENSOR_SRCS
            ${ICMSRC}
            ${LPSSRC}
            ${MAGSRC}
            ${GPSSRC}
    )

    nuttx_add_application(
            NAME ${CONFIG_FLIGHTCOMPUTER_SENSORPACKAGE_PROGNAME}
            PRIORITY ${CONFIG_FLIGHTCOMPUTER_SENSORPACKAGE_PRIORITY}
            STACKSIZE ${CONFIG_FLIGHTCOMPUTER_SENSORPACKAGE_STACKSIZE}
            MODULE ${CONFIG_FLIGHTCOMPUTER_SENSORPACKAGE}

            SRCS
            SensorPackage.cxx
            ${SENSOR_SRCS}

            INCLUDE_DIRECTORIES
            ${APPDIR}/FlightComputer/FlightLib
            ${BASEDIR}
            ${NUTTX_INCLUDE_DIRS}
            ${CMAKE_CXX_IMPLICIT_INCLUDE_DIRECTORIES}
            ${CMAKE_CXX_STANDARD_INCLUDE_DIRECTORIES}
    )



endif()