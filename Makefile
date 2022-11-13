#Makefile
CONTIKI_PROJECT = demo
all: $(CONTIKI_PROJECT)

PROJECT_SOURCEFILES += mytemp.c

CONTIKI = ../../
include $(CONTIKI)/Makefile.include
