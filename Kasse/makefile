ODEMX_HOME := /home/vincent/ODEMx-lite

CFLAGS := -std=c++14 -O0 -g -I$(ODEMX_HOME)/include -I$(ODEMX_HOME)/external/CppLog/include
LFLAGS := -L$(ODEMX_HOME)/lib

CPPFILES := $(wildcard *.cpp)
HPPFILES := $(wildcard *.h) $(wildcard *.hpp)

LIBS 	:= -lOdemxD
OBJS 	:= $(CPPFILES:%.cpp=%.o)
TARGET 	:= KassenSim

# runnable
all: $(TARGET)

# link
$(TARGET): $(OBJS)
	$(CXX) -o $(TARGET) $(LFLAGS) $^ $(LIBS)
	
# compile
%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@
	
# run
run: $(TARGET)
	./$(TARGET)

# clean
clean:
	$(RM) $(RMFILES) $(OBJS) $(TARGET)
	