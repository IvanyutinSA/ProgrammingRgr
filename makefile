API_SOURCES = lib/api.h lib/nonlinear_api.cpp lib/integral_api.cpp
ALGORITHMS_SOURCES = lib/algorithms.cpp lib/algorithms.h
SOURCES = $(API_SOURCES) $(ALGORITHMS_SOURCES)

app: 
	g++ main.cpp $(SOURCES) -o app

.PHONY: app
