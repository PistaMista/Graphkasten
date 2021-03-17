CXXFLAGS:=$(shell pkg-config gtkmm-3.0 --cflags)
LDFLAGS:=$(shell pkg-config gtkmm-3.0 --libs)

#############

CC=g++
EXECUTABLE=zettelkasten-gtk.out
SRCS=main.cpp helloworld.cpp
OBJS=$(patsubst %.cpp,%.o,$(SRCS))

#############

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CC) $(CXXFLAGS) $? $(LDFLAGS) -o $@

install: all
	install $(EXECUTABLE) /usr/bin/$(patsubst %.out,%,$(EXECUTABLE))

clean:
	rm $(EXECUTABLE) $(OBJS)
