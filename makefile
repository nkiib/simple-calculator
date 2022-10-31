CC  = g++
CFLAGS    = -std=c++17
TARGET  = tlooks-simple-calculator
SRCS    = main.cpp
OBJS    = $(SRCS:.cpp=.o)

INCDIR  = 
 
LIBDIR  = 
 
LIBS    = 

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LIBDIR) $(LIBS)
	
$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) $(INCDIR) -c $(SRCS)
all: clean $(OBJS) $(TARGET) *.o
clean:
	-rm -f $(OBJS) $(TARGET) *.d *.o