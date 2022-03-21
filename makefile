CFLAGS = -I../..
ifeq ($(OS),Windows_NT)
        LDFLAGS = -s -lopengl32 -lgdi32
else
        UNAME_S := $(shell uname -s)
        ifeq ($(UNAME_S),Darwin)
                LDFLAGS = -framework OpenGL -framework Cocoa
        else ifeq ($(UNAME_S),Linux)
                LDFLAGS = -s -lGLU -lGL -lX11
        endif
endif

visorGUI: tigr.o GUIXML.o xml.o GUIICONS.o visorGUI.o
	gcc -o visorGUI visorGUI.o tigr.o GUIXML.o xml.o GUIICONS.o $(CFLAGS) $(LDFLAGS)
GUIXML.o: GUIXML.c
	gcc -c GUIXML.c
tigr.o: tigr\tigr.c tigr\tigr.h
	gcc -c tigr\tigr.c
xml.o: xml.c\src\xml.c
	gcc -c xml.c/src/xml.c
GUIICONS.o: GUIICONS.c
	gcc -c GUIICONS.c
visorGUI.o: visorGUI.c
	gcc -c visorGUI.c

clean:
	del visorGUI.exe visorGUI.o tigr.o xml.o GUIXML.o GUIICONS.o
