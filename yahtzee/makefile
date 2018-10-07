PROGRAM  = $(BINDIR)/yahtzee
OBJDIR   = obj
BINDIR   = bin
$(shell mkdir -p $(OBJDIR) $(BINDIR))

CC       = g++
CFLAGS   = -Wall -std=c++11
LINC     =
LIBS     =
OBJS     = command.cpp \
           common.cpp \
           roll.cpp \
           scorecard.cpp \
           yahtzee.cpp

ALLOBJS = $(OBJS:%.cpp=$(OBJDIR)/%.o)

ALL: $(PROGRAM)

debug: CFLAGS += -DDEBUG -g
debug: $(PROGRAM)

$(PROGRAM): $(ALLOBJS)
	$(CC) $(CFLAGS) -o $@ $(ALLOBJS) $(LINC) $(LIBS)

$(OBJDIR)/%.o : %.cpp
	$(CC) $(CFLAGS) -c $*.cpp -o $(OBJDIR)/$*.o

clean:
	rm -rf $(OBJDIR) $(BINDIR)
