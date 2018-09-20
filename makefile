PROGRAM  = $(BINDIR)/struct_example
OBJDIR   = obj
BINDIR   = bin
$(shell mkdir -p $(OBJDIR) $(BINDIR))

CC       = g++
CFLAGS   = -Wall -std=c++11
LINC     =
LIBS     =
OBJS     = struct_example.cpp

ALLOBJS = $(OBJS:%.cpp=$(OBJDIR)/%.o)

ALL: $(PROGRAM)

debug: CFLAGS += -DDEBUG -g
debug: $(PROGRAM)

$(PROGRAM): $(ALLOBJS)
	$(CC) $(CFLAGS) -o $@ $(ALLOBJS) $(LINC) $(LIBS)

$(OBJDIR)/%.o : %.cpp
	$(CC) $(CFLAGS) -c $*.cpp -o $(OBJDIR)/$*.o

data:
	$(CC) -DDEBUG -o $(BINDIR)/create_data create-data.cpp

clean:
	rm -rf $(OBJDIR) $(BINDIR)
