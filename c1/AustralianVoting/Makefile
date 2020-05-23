EXECUTABLE = a.out
TEST_CMD = $(sh runTests.sh)

.PHONY: release
.PHONY: debug
.PHONY: clean
.PHONY: test
.PHONY: distrib    

CXX = g++
CXXFLAGS = -std=c++11 -Wconversion -Wall -Werror -Wextra -pedantic 
OPTIMIZATION=-O2
# OPTIMIZATION=-O3

# list of sources used in project
SOURCES = $(wildcard *.cpp)

release: $(SOURCES)
release: CXXFLAGS += -O3 -DNDEBUG
release:
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(EXECUTABLE)

debug: $(SOURCES)
debug: CXXFLAGS += -g3 -DDEBUG
debug:
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(EXECUTABLE)_debug

test:
	chmod +x runTests.sh
	./runTests.sh
	
clean :
	rm -vrf *.o *.out *.out_debug *.gch *.dSYM *.stackdump *.out.txt *tar.gz
