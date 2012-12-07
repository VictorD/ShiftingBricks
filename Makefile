APP = ShiftingBricks

include $(SDK_DIR)/Makefile.defs

OBJS = $(ASSETS).gen.o main.o game.o mapblock.o player.o
ASSETDEPS += *.png $(ASSETS).lua
CDEPS += *.h

include $(SDK_DIR)/Makefile.rules
