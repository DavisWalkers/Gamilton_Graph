CXX = g++
CXXFLAGS = -g -Wall
SRCMODULES = is_gamilton.cpp test.cpp
OBJMODULES = $(SRCMODULES:.c=.o)

%.o:	%.cpp %.h
			$(CXX) $(CXXFLAGS) -c $< -o $@

main:	main.cpp $(OBJMODULES)
			$(CXX) $(CXXFLAGS) $^ -o $@

ifneq (clean, $(MAKECMDGOALS))
-include deps.mk
endif

deps.mk:  $(SRCMODULES)
		$(CXX) -MM $^ > $@

clean:
		rm -f *.o main
		rm -f *.swp main	
