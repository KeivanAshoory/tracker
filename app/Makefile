CROSS = arm-linux-
CC = g++
CFLAGS = -g -Wall
SRCDIR = src
BUILDDIR = build
ifndef CROSS
	ROOT = /.
	TARGET = ./bin/tracker
	PREFIX = $(ROOT)/usr/local
else
	ROOT = /opt/FriendlyARM/mini2440/rootfs_qtopia_qt4
	TARGET = $(ROOT)/opt/share/tracker/bin/tracker
	PREFIX = $(ROOT)/usr
endif

SRCEXT = cc
SOURCES = $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS = $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
LIB = -L $(PREFIX)/lib -lyaml-cpp
INC = -I./include -I $(PREFIX)/include

$(TARGET): $(OBJECTS)
	@echo " Linking..."
	@echo " $(CROSS)$(CC) $^ -o $(TARGET) $(LIB)"; $(CROSS)$(CC) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " $(CROSS)$(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CROSS)$(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning...";
	@echo " $(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)

# Tests
tester:
	$(CROSS)$(CC) $(CFLAGS) test/tester.cpp $(INC) $(LIB) -o bin/tester

.PHONY: clean
