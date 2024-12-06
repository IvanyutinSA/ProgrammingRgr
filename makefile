SOURCES = main.cpp
CC = x86_64-w64-mingw32-g++ -std=c++23 -static -static-libgcc -static-libstdc++

app: 
	$(CC) $(SOURCES) -lgdi32 -o app

.PHONY: app
