# paths
# LIB = ../../lib
INCLUDE = ..

# compiler
CC = g++

# Compile options. Το -I<dir> λέει στον compiler να αναζητήσει εκεί include files
CXXFLAGS = -Wall  -g -I$(INCLUDE)
# LDFLAGS = -lm

# Αρχεία .o
OBJS =  Ergasia.o Outside.o People.o Spells.o Items.o #$(LIB)/k08.a

# Το εκτελέσιμο πρόγραμμα
EXEC = teliki

# Παράμετροι για δοκιμαστική εκτέλεση
#ARGS = paradeigma.txt

$(EXEC): $(OBJS)
	#valgrind#
	 $(CC) $(OBJS) -o $(EXEC) $(LDFLAGS)

# Για να φτιάξουμε το k08.a, τρέχουμε το make στο lib directory.
# $(LIB)/k08.a:
# 	$(MAKE) -C $(LIB) k08.a

clean:
	rm -f $(OBJS) $(EXEC)

run: $(EXEC)
	./$(EXEC) $(ARGS)
