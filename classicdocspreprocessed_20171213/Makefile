CXX = g++
CXXFLAGS = -O3 -Wall -Wextra -std=c++17
correct : MakeCorrectForClassic4.cxx
	$(CXX) $(CXXFLAGS) $^ -o $@.out
data : MakeDataForClassic4.cxx
	$(CXX) $(CXXFLAGS) $^ -o $@.out
sparse : MakeDataForSparse.cxx
	$(CXX) $(CXXFLAGS) $^ -o $@.out
clean:
	rm -f *.out
