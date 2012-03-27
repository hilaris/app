
CC_HOST = g++
CC_TARGET = bfin-uclinux-g++

CCFLAG_T = -Wall -c -Iincludes/oscar -Iincludes -DOSC_TARGET
CCFLAG_H = -Wall -c -m32 -Iincludes/oscar -Iincludes -DOSC_HOST

LD_HOST := $(CC_HOST) -fPIC -m32
LD_TARGET := $(CC_TARGET) -elf2flt="-s 1048576"

BUILD = build


SOURCES := $(patsubst sources/%.cpp,%,$(wildcard sources/*.cpp))

all: host target

host: $(addsuffix .o, $(addprefix build/host_, $(SOURCES)))
	$(LD_HOST) -o app_host $^ -Llibrary -lhilaris_host -losc_host -lpthread

target: $(addsuffix .o, $(addprefix build/target_, $(SOURCES)))
	$(LD_TARGET) -o app_target  $^ -Llibrary -lhilaris_target -losc_target -lpthread
	
build/target_%.o: sources/%.cpp
	$(CC_TARGET) $(CCFLAG_T) $? -o $@
	
build/host_%.o: sources/%.cpp
	$(CC_HOST) $(CCFLAG_H) $? -o $@

clean:
	rm -f $(BUILD)/*
	rm -f app_*


