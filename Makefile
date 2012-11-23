APP = ShiftingBricks

include $(SDK_DIR)/Makefile.defs

OBJS = $(ASSETS).gen.o main.o game.o gamecube.o mapblock.o
ASSETDEPS += *.png $(ASSETS).lua
CDEPS += *.h

include $(SDK_DIR)/Makefile.rules
