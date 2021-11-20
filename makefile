CXX = g++
CXXFLAGS = -Wall

proj4: War.o Horse.o Untrained.o Warhorse.o Heavy.o Medium.o Light.o driver.cpp
        $(CXX) $(CXXFLAGS) War.o Horse.o Untrained.o Warhorse.o Heavy.o Medium.o Light.o driver.cpp -o proj4

War.o: Untrained.o Horse.o Heavy.o Medium.o Light.o Warhorse.o War.h War.cpp
        $(CXX) $(CXXFLAGS) -c War.cpp

Horse.o: Horse.cpp Horse.h
        $(CXX) $(CXXFLAGS) -c Horse.cpp

Heavy.o: Warhorse.o Heavy.cpp Heavy.h
        $(CXX) $(CXXFLAGS) -c Heavy.cpp

Medium.o: Warhorse.o Medium.cpp Medium.h
        $(CXX) $(CXXFLAGS) -c Medium.cpp

Light.o: Warhorse.o Light.cpp Light.h
        $(CXX) $(CXXFLAGS) -c Light.cpp

Warhorse.o: Horse.o Warhorse.cpp Warhorse.h
        $(CXX) $(CXXFLAGS) -c Warhorse.cpp

Untrained.o: Horse.o Heavy.o Medium.o Light.o Untrained.cpp Untrained.h
        $(CXX) $(CXXFLAGS) -c Untrained.cpp


clean:
        rm *.o*
        rm *~

run:
        ./proj4

run1:
        ./proj4 proj4_data.txt

val1:
        valgrind ./proj4 proj4_data.txt
