CXX =	g++
CFLAGSi	 = -Wall 
LDFLAGS   = `pkg-config --cflags --libs opencv`

SRCS = $(wildcard *.cpp)
TARGETS = $(patsubst %.cpp, %,$(SRCS))

all:$(TARGETS)
$(TARGETS):$(SRCS)
	$(CXX) -D_GLIBCXX_USE_CXX11_ABI=0 -o $@ $< $(LDFLAGS) $(CFLAGS)
clean:
	-rm -rf $(TARGETS) *~ .*swp
.PHONY: clean all
