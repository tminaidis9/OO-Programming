# paths
LIB = ../../lib
INCLUDE = ../../include

# compiler
CC = g++

# Compile options. Το -I<dir> λέει στον compiler να αναζητήσει εκεί include files
CXXFLAGS = -Wall  -g -I$(INCLUDE)
# LDFLAGS = -lm

# Αρχεία .o
OBJS =  askisi1.o #$(LIB)/k08.a

# Το εκτελέσιμο πρόγραμμα
EXEC = askisi1

# Παράμετροι για δοκιμαστική εκτέλεση
# ARGS = input-file

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC) $(LDFLAGS)

# Για να φτιάξουμε το k08.a, τρέχουμε το make στο lib directory.
# $(LIB)/k08.a:
# 	$(MAKE) -C $(LIB) k08.a

clean:
	rm -f $(OBJS) $(EXEC)

run: $(EXEC)
	./$(EXEC) $(ARGS)
