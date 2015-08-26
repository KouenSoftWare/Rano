cc = g++
objects := $(patsubst %.cpp,%.o,$(wildcard *.cpp))
target = Rano_RouteNode

linkFlags := -g -Wall 
include_dirs := 
LIBS := boost_system pthread boost_thread protobuf
LDFLAGS := 

CPPFLAGS =  $(addprefix -I, $(include_dirs)) $(addprefix -L,$(LDFLAGS))
CPPFLAGS += -g -Wall 

$(target): $(objects)
	$(cc) $(linkFlags) -o $(target)  $(objects) $(addprefix -I, $(include_dirs)) $(addprefix -L,$(LDFLAGS)) $(addprefix -l,$(LIBS))

.PHONY : clean
clean:
	rm -f $(target) $(objects)
