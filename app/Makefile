CROSS = arm-linux-
CC = g++

SRCEXT = cc
HDREXT = h

SRCDIR = src
HDRDIR = include
BUILDDIR = build
DEPDIR = dep

ifndef CROSS
	ROOT = /.
	TARGET = ./bin/tracker
	PREFIX = $(ROOT)/usr/local
else
	ROOT = /opt/FriendlyARM/mini2440/rootfs_qtopia_qt4
	TARGET = $(ROOT)/opt/share/tracker/bin/tracker
	PREFIX = $(ROOT)/usr
endif

$(shell mkdir -p $(SRCDIR) >/dev/null)
$(shell mkdir -p $(HDRDIR) >/dev/null)
$(shell mkdir -p $(BUILDDIR) >/dev/null)
$(shell mkdir -p $(DEPDIR) >/dev/null)

SOURCES = $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS = $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
LIB = -L $(PREFIX)/lib -lyaml-cpp
INC = -I$(HDRDIR) -I $(PREFIX)/include

CFLAGS = -g -Wall
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.Td



$(TARGET): $(OBJECTS)
	@echo " Linking..."
	@echo " $(CROSS)$(CC) $^ -o $(TARGET) $(LIB)";
	$(CROSS)$(CC) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT) $(DEPDIR)/%.d
	@mkdir -p $(BUILDDIR)
	@echo " $(CROSS)$(CC) $(DEPFLAGS) $(CFLAGS) $(INC) -c -o $@ $<";
	$(CROSS)$(CC) $(DEPFLAGS) $(CFLAGS) $(INC) -c -o $@ $<
	mv -f $(DEPDIR)/$*.Td $(DEPDIR)/$*.d


clean:
	@echo " Cleaning...";
	@echo " $(RM) -r $(BUILDDIR) $(TARGET) $(DEPDIR)"; $(RM) -r $(BUILDDIR) $(TARGET) $(DEPDIR)


tester:
	$(CROSS)$(CC) $(CFLAGS) test/tester.cpp $(INC) $(LIB) -o bin/tester

.PHONY: clean

$(DEPDIR)/%.d: ;
.PRECIOUS: $(DEPDIR)/%.d

-include $(patsubst $(SRCDIR)/%,$(DEPDIR)/%.d,$(basename $(SOURCES)))

