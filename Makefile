CROSS_COMPILE	?= arm-linux-gnueabihf-
TARGET			?= IMX6ULL
OBJ_PATH		:= obj

CC				:= $(CROSS_COMPILE)gcc
LD				:= $(CROSS_COMPILE)ld
OBJCOPY			:= $(CROSS_COMPILE)objcopy
OBJDUMP			:= $(CROSS_COMPILE)objdump

INCDIRS			:= 	imx6ull	\
					bsp/beep \
					bsp/clock \
					bsp/led \
					bsp/gpio \
					bsp/key \
					application/morse \
					application/key \

SRCDIRS			:= 	project \
					bsp/beep \
					bsp/clock \
					bsp/led \
					bsp/gpio \
					bsp/key \
					application/morse \
					application/key \

INCLUDE			:= $(patsubst %, -I %, $(INCDIRS))

SFILES			:= $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.s))
CFILES			:= $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.c))

SFILENDIR		:= $(notdir $(SFILES))
CFILENDIR		:= $(notdir $(CFILES))

SOBJS			:= $(patsubst %, obj/%, $(SFILENDIR:.s=.o))
COBJS			:= $(patsubst %, obj/%, $(CFILENDIR:.c=.o))
OBJS			:= $(SOBJS) $(COBJS)

VPATH			:= $(SRCDIRS)

.PHONY: clean

all : $(OBJ_PATH) $(TARGET).bin

$(OBJ_PATH):
	@if [ ! -d $(OBJ_PATH) ]; then mkdir $(OBJ_PATH); fi

$(TARGET).bin : $(OBJS)
	$(LD) -Tproject.lds -o $(TARGET).elf $^
	$(OBJCOPY) -O binary -S $(TARGET).elf $@
	$(OBJDUMP) -D -m arm $(TARGET).elf > $(TARGET).dis

$(SOBJS) : obj/%.o : %.s
	$(CC) -Wall -nostdlib -c -O2 $(INCLUDE) -o $@ $<

$(COBJS) : obj/%.o : %.c
	$(CC) -Wall -nostdlib -c -O2 $(INCLUDE) -o $@ $<

clean:
	rm -rf $(TARGET).elf $(TARGET.dis) $(TARGET).bin $(COBJS) $(SOBJS)
