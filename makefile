API_SOURCES = lib/api.h lib/nonlinear_api.cpp lib/integral_api.cpp lib/function_api.cpp
ALGORITHMS_SOURCES = lib/algorithms.cpp lib/algorithms.h
SOURCES = $(API_SOURCES) $(ALGORITHMS_SOURCES)
# COMPILER = x86_64-w64-mingw32-g++ -std=c++20 -static -static-libgcc -static-libstdc++ -L /usr/x86_64-w64-mingw32/lib -lgdi32
COMPILER = x86_64-w64-mingw32-g++ -std=c++20 -static -static-libgcc -static-libstdc++ -mwindows -lgdi32
# COMPILER = g++

app: 
	$(COMPILER) main.cpp $(SOURCES) -o app

.PHONY: app
