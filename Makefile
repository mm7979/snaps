#
# Ubunutu Core test program for wiringpi.
# WiringPi Version tested: 2.46
# Hardware used: Berryclip 6
# Code from:
# https://www.raspberrypi-spy.co.uk/2013/04/berryclip-6-led-board-testing-in-c/

src = $(wildcard *.c)
obj = $(src:.c=.o)

LDFLAGS =  -pthread -lwiringPi -lm -lrt -lcrypt
CFLAGS  = --std=c99

test1: $(obj)
	$(CC)  $(CFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(obj) test1

#.PHONY: install
install: test1
#	current working directory is parts/test1/build
#	place the binary so it will be included in the snap
	cp $<  ../install/bin
