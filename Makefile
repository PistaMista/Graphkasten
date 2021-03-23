CXXFLAGS:=$(shell pkg-config gtkmm-3.0 --cflags) -Isrc -g -Wall -std=c++20
LDFLAGS:=$(shell pkg-config gtkmm-3.0 --libs)

#############

CC=g++
EXECUTABLE=zettelkasten-gtk.out
SRCS=$(shell find src/ -type f | grep -P '.+\.cpp$$')
OBJS=$(patsubst %.cpp,%.o,$(SRCS))

#############

$(EXECUTABLE): $(OBJS)
	$(CC) $(CXXFLAGS) $^ $(LDFLAGS) -o $@

run: $(EXECUTABLE)
	./$(EXECUTABLE)

debug: $(EXECUTABLE)
	gdb -tui $(EXECUTABLE)

install: $(EXECUTABLE)
	install $(EXECUTABLE) /usr/bin/$(patsubst %.out,%,$(EXECUTABLE))

clean:
	rm $(EXECUTABLE) $(OBJS)
