TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#=============================
# xxxRecord.h will be created from xxxRecord.dbd

#=============================
# build an ioc application

LIBRARY_IOC = vittara
# vittara.dbd will be created and installed
DBD += vittara.dbd

# vittara.dbd will be made up from these files:
vittara_DBD += base.dbd
#vittara_DBD += epidSupport.dbd <- now comes from std module
vittara_DBD += std.dbd
vittara_DBD += aCalcoutRecord.dbd
vittara_DBD += calcSupport.dbd
#vittara_DBD += compressStats.dbd Obsolete

# <name>_registerRecordDeviceDriver.cpp will be created from <name>.dbd
vittara_SRCS += vittara_registerRecordDeviceDriver.cpp
vittara_SRCS_DEFAULT += vittaraMain.cpp
vittara_SRCS_vxWorks += -nil-

# Add locally compiled object code
#vittara_SRCS += compressStats.c Obsolete

#vittara_SRCS += epidRecord.c <- now comes from std module
#vittara_SRCS += devEpidSoft.c
#vittara_SRCS += devEpidSoftCallback.c
#vittara_SRCS += devEpidFast.c

# required libraries
vittara_LIBS += std seq pv

#vittara_LIBS += $(EPICS_BASE_IOC_LIBS)

PROD_SYS_LIBS_Linux += pcre

#===========================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

# Parallel build sometimes fails.
# Make dependences on epidRecord.h explicit.
#epidRecord$(OBJ):          $(COMMON_DIR)/epidRecord.h
#devEpidSoft$(OBJ):         $(COMMON_DIR)/epidRecord.h
#devEpidSoftCallback$(OBJ): $(COMMON_DIR)/epidRecord.h
#devEpidFast$(OBJ):         $(COMMON_DIR)/epidRecord.h
