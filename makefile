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

visor: tigr.o parser.o xml.o icons.o visor.o
	gcc -o visor visor.o tigr.o parser.o xml.o icons.o $(CFLAGS) $(LDFLAGS)
parser.o: parser.c
	gcc -c parser.c
tigr.o: tigr\tigr.c tigr\tigr.h
	gcc -c tigr\tigr.c
xml.o: xml.c\src\xml.c
	gcc -c xml.c/src/xml.c
icons.o: icons.c
	gcc -c icons.c
visor.o: visor.c
	gcc -c visor.c

clean:
	del visor.exe visor.o tigr.o xml.o parser.o icons.o
