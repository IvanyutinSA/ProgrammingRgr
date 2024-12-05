API_SOURCES = lib/api.h lib/nonlinear_api.cpp lib/integral_api.cpp lib/function_api.cpp
ALGORITHMS_SOURCES = lib/algorithms.cpp lib/algorithms.h
SOURCES = $(LIBS) $(API_SOURCES) $(ALGORITHMS_SOURCES)
CC = x86_64-w64-mingw32-g++ -std=c++23 -static -static-libgcc -static-libstdc++
# CC = x86_64-w64-mingw32-g++ -std=c++20 -static -static-libgcc -static-libstdc++ 
# CC = g++

app: 
	$(CC) main.cpp $(SOURCES) -lgdi32 -o app

.PHONY: app
