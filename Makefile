
CC_HOST = g++
CC_TARGET = bfin-uclinux-g++

CCFLAG_T = -Wall -c -Iincludes/oscar -Iincludes -DOSC_TARGET
CCFLAG_H = -Wall -c -Iincludes/oscar -Iincludes -DOSC_HOST

LD_HOST := $(CC_HOST) -fPIC
LD_TARGET := $(CC_TARGET) -elf2flt="-s 1048576"

BUILD = build


SOURCES := $(patsubst sources/%.cpp,%,$(wildcard sources/*.cpp))

all: host target

host: $(addsuffix .o, $(addprefix build/host_, $(SOURCES)))
	$(LD_HOST) -o app_host $^ -Llibrary -losc_host -lhilaris_host

target: $(addsuffix .o, $(addprefix build/target_, $(SOURCES)))
	$(LD_TARGET) -o app_target $^ -Llibrary -losc_target -lhilaris_target
	
build/target_%.o: sources/%.cpp
	$(CC_TARGET) $(CCFLAG_T) $? -o $@
	
build/host_%.o: sources/%.cpp
	$(CC_HOST) $(CCFLAG_H) $? -o $@

clean:
	rm -f $(BUILD)*
	rm -f app_*


