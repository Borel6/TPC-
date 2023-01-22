
# Makefile with dependencies management (Q4)


CXX        = clang++
CXXFLAGS   = -Wall  -std=c++17
DEPFLAGS   = -MMD
LDFLAGS    =
SRCS       = main1.cpp date.cpp livre.cpp auteur.cpp lecteur.cpp emprunt.cpp bibliotheque.cpp
OBJS       = $(SRCS:.cpp=.o)
TARGET     = a
DEPS	   = $(OBJS:.o=.d)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(DEPFLAGS) -c  $<

clean:
	rm -f *.o *.d

mrproper: clean
	rm -f $(TARGET)

exe: $(TARGET)
	./$(TARGET)

-include $(DEPS)
