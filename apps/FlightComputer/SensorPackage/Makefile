include $(APPDIR)/Make.defs

PROGNAME = $(CONFIG_FLIGHTCOMPUTER_SENSORPACKAGE_PROGNAME)
PRIORITY = $(CONFIG_FLIGHTCOMPUTER_SENSORPACKAGE_PRIORITY)
STACKSIZE = $(CONFIG_FLIGHTCOMPUTER_SENSORPACKAGE_STACKSIZE)
MODULE = $(CONFIG_FLIGHTCOMPUTER_SENSORPACKAGE)

# State Machine
MAINSRC = SensorPackage.cxx
BASEDIR = $(APPDIR)/FlightComputer/SensorPackage

# Subdirectories
#SENSORDIR = $(BASEDIR)/sensors
ICMDIR = $(BASEDIR)/ICM42688
LPSDIR = $(BASEDIR)/LPS25
MSDIR = $(BASEDIR)/MS5611
GPSDIR = $(BASEDIR)/MAX10S

# Shared Directories and Library Linking
SHAREDIR = $(APPDIR)/FlightComputer/FlightLib

# Include Sensors and Build
ICMSRC = $(wildcard $(ICMDIR)/*.cxx)
LPSSRC = $(wildcard $(LPSDIR)/*.cxx)
MSSRC  = $(wildcard $(MSDIR)/*.cxx)
GPSSRC = $(wildcard $(GPSDIR)/*.cxx)

# Add Sensors to the CXX Compiler
CXXSRCS += $(ICMSRC)
CXXSRCS += $(LPSSRC)
CXXSRCS += $(MSSRC)
CXXSRCS += $(GPSSRC)

VPATH += $(ICMDIR)
VPATH += $(LPSDIR)
VPATH += $(MSDIR)
VPATH += $(SHAREDIR)
VPATH += $(GPSDIR)

INCLUDES += -I$(APPDIR)/FlightComputer/FlightLib

CXXFLAGS += $(INCLUDES)

include $(APPDIR)/Application.mk