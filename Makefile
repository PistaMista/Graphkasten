CXXFLAGS:=$(shell pkg-config gtkmm-3.0 --cflags) -Isrc
LDFLAGS:=$(shell pkg-config gtkmm-3.0 --libs)

#############

CC=g++
EXECUTABLE=zettelkasten-gtk.out
SRCS=$(shell find src/ -type f | grep -P '.+\.cpp$$')
OBJS=$(patsubst %.cpp,%.o,$(SRCS))

#############

$(EXECUTABLE): $(OBJS)
	$(CC) $(CXXFLAGS) $? $(LDFLAGS) -o $@

run: $(EXECUTABLE)
	./$(EXECUTABLE)

install: $(EXECUTABLE)
	install $(EXECUTABLE) /usr/bin/$(patsubst %.out,%,$(EXECUTABLE))

clean:
	rm $(EXECUTABLE) $(OBJS)
