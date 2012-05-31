
CC_HOST = g++
CC_TARGET = bfin-uclinux-g++

CCFLAG_T = -Wall -c -Iincludes/oscar -Iincludes -DOSC_TARGET
CCFLAG_H = -Wall -c -m32 -Iincludes/oscar -Iincludes -DOSC_HOST

LD_HOST := $(CC_HOST) -fPIC -m32
LD_TARGET := $(CC_TARGET) -elf2flt="-s 2145728"

BUILD = build


SOURCES := $(patsubst sources/%.cpp,%,$(wildcard sources/*.cpp))
PROCESSORS := $(patsubst sources/processors/%.cpp,%,$(wildcard sources/processors/*.cpp))

IP=192.168.1.10
NAME=hilaris

all: host target

host: $(addsuffix .o, $(addprefix build/host_, $(SOURCES))) $(addsuffix .o, $(addprefix build/processors/host_, $(PROCESSORS)))
	$(LD_HOST) -o app_host $^ -Llibrary -lhilaris_host -losc_host -losc_overlay_host -lpthread 

target: $(addsuffix .o, $(addprefix build/target_, $(SOURCES))) $(addsuffix .o, $(addprefix build/processors/target_, $(PROCESSORS)))
	$(LD_TARGET) -o app_target  $^ -Llibrary -lhilaris_target -losc_target -losc_overlay_target -lpthread
	
build/target_%.o: sources/%.cpp
	$(CC_TARGET) $(CCFLAG_T) $? -o $@
	
build/host_%.o: sources/%.cpp
	$(CC_HOST) $(CCFLAG_H) $? -o $@
	
build/processors/target_%.o: sources/processors/%.cpp
	$(CC_TARGET) $(CCFLAG_T) $? -o $@
	
build/processors/host_%.o: sources/processors/%.cpp
	$(CC_HOST) $(CCFLAG_H) $? -o $@

clean:
	rm -f $(BUILD)/*.o $(BUILD)/processors/*.o
	rm -f app_*
	
deploy: target
	@ mkdir -p deploy/$(NAME)
	@ cp app_target deploy/$(NAME)/app
	@ cp Font_System.bmp deploy/$(NAME)/
	@ cp deploy/run.sh deploy/$(NAME)/
	scp -r deploy/$(NAME) root@$(IP):/mnt/app/


