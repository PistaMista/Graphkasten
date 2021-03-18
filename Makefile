CXXFLAGS:=$(shell pkg-config gtkmm-3.0 --cflags) -Isrc
LDFLAGS:=$(shell pkg-config gtkmm-3.0 --libs)

#############

CC=g++
EXECUTABLE=zettelkasten-gtk.out
SRCS=$(shell find src/ -type f | grep -P '.+\.cpp$$')
OBJS=$(patsubst %.cpp,%.o,$(SRCS))

#############

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CC) $(CXXFLAGS) $? $(LDFLAGS) -o $@

install: all
	install $(EXECUTABLE) /usr/bin/$(patsubst %.out,%,$(EXECUTABLE))

clean:
	rm $(EXECUTABLE) $(OBJS)
