CROSS = arm-linux-
CC = g++
CFLAGS = -g -Wall
SRCDIR = src
BUILDDIR = build
ifndef CROSS
	TARGET = bin/tracker
else
	TARGET = /opt/FriendlyARM/mini2440/rootfs_qtopia_qt4/opt/share/tracker/bin/tracker
endif

SRCEXT = cc
SOURCES = $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS = $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
LIB = #-pthread -lmongoclient -L lib -lboost_thread-mt -lboost_filesystem-mt -lboost_system-mt
INC = -I include

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
