TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#=============================
# xxxRecord.h will be created from xxxRecord.dbd

#=============================
# build an ioc application

LIBRARY_IOC = vitara
# vitara.dbd will be created and installed
DBD += vitara.dbd

# vitara.dbd will be made up from these files:
vitara_DBD += base.dbd
#vitara_DBD += epidSupport.dbd <- now comes from std module
#vitara_DBD += std.dbd <- needed, but comes from the app using this module. Dependency problems otherwise.
vitara_DBD += aCalcoutRecord.dbd
vitara_DBD += calcSupport.dbd
#vitara_DBD += compressStats.dbd Obsolete

# <name>_registerRecordDeviceDriver.cpp will be created from <name>.dbd
vitara_SRCS += vitara_registerRecordDeviceDriver.cpp
vitara_SRCS_DEFAULT += vitaraMain.cpp
vitara_SRCS_vxWorks += -nil-

# Add locally compiled object code
#vitara_SRCS += compressStats.c Obsolete

#vitara_SRCS += epidRecord.c <- now comes from std module
#vitara_SRCS += devEpidSoft.c
#vitara_SRCS += devEpidSoftCallback.c
#vitara_SRCS += devEpidFast.c

# required libraries
# vitara_LIBS += std seq pv

#vitara_LIBS += $(EPICS_BASE_IOC_LIBS)

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
