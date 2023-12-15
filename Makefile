MODEL ?= Z10

CFLAGS  = -std=gnu11 -Wall ## -Werror
CFLAGS += -I/opt/redpitaya/include -D$(MODEL)
LDFLAGS = -L/opt/redpitaya/lib
LDLIBS = -static -lrp -lrp-hw-calib -lrp-hw-profiles

INCLUDE += -I/opt/redpitaya/include/api250-12
LDLIBS += -lrp-gpio -lrp-i2c
LDLIBS += -lrp-hw -lm -lstdc++ -lpthread -li2c

# List of compiled object files (not yet linked to executable)

PRGS =  laser \
        analog_out \
        analog_in \
        analog_dual \
        hello \
        laserv2

OBJS := $(patsubst %,%.o,$(PRGS))
SRC := $(patsubst %,%.c,$(PRGS))

all: $(PRGS)

$(PRGS): %: %.c
        $(CC) $< $(CFLAGS) $(LDFLAGS) $(LDLIBS) -o $@

clean:
        $(RM) *.o
        $(RM) $(OBJS)
