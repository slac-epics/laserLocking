TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

# build an ioc application
LIBRARY_IOC = vitara
DBD += vitara.dbd

# vitara.dbd will be made up from these files:
vitara_DBD += base.dbd
vitara_DBD += calcSupport.dbd

# <name>_registerRecordDeviceDriver.cpp will be created from <name>.dbd
vitara_SRCS += vitara_registerRecordDeviceDriver.cpp
vitara_SRCS_DEFAULT += vitaraMain.cpp
vitara_SRCS_vxWorks += -nil-

vitara_LIBS += $(EPICS_BASE_IOC_LIBS)

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE
#
# End of file
