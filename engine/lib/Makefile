##
## EPITECH PROJECT, 2019
## OmegaEngine
## File description:
## Makefile
##

all:
		$(MAKE) -C jsmn/ && cp jsmn/libjsmn.a ./ && cp jsmn/jsmn.h ../include/lib/

clean:
		$(MAKE) -C jsmn/ clean && rm -f libjsmn.a && rm -f ../include/lib/jsmn.h

.PHONY: all clean