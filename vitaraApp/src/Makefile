TOP=../..
include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#========================================
# build a support library
LIBRARY_IOC += laserLocking

# install devGenVar.dbd into <top>/dbd
DBD         += laserLocking.dbd

# specify all source files to be compiled and added to the library
laserLocking_SRCS += laserLocking.c

laserLocking_LIBS += $(EPICS_BASE_IOC_LIBS)

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

