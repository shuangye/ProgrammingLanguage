# Makefile, by Papillon


TARGET = osa
LIB = lib$(TARGET).so
EXE = $(TARGET)

CROSS :=

INCLUDE := -I../include
LIB_DIR := 
LIBS     =
COMMON_FLAGS := -DOSA_MODULE_NAME='"$(TARGET)"'
COMMON_FLAGS += -Wall -Wextra -pipe

SRC     = $(wildcard ../src/*.c)
SRC    += $(wildcard ../src/log/*.c)
CXXSRC += $(wildcard ../src/*.cpp)
EXESRC += $(wildcard ../tests/*.c)
# OBJDIR = ./objs
OBJDIR = ./
OBJ += $(SRC:%.c=$(OBJDIR)/%.o) $(CXXSRC:%.cpp=$(OBJDIR)/%.o)
EXEOBJ += $(EXESRC:%.cpp=$(OBJDIR)/%.o)

COMMON_FLAGS += $(INCLUDE) $(LIB_DIR)


CC        = $(CROSS)gcc
CXX       = $(CROSS)g++
LD        = $(CROSS)gcc
CFLAGS   += -std=c99
# CXXFLAGS += -std=c++11
LDFLAGS  += -pie -fPIE
SHARED_LIB_FLAGS += -fPIC -shared

# Debug Options
ifeq ($(config), debug)
    COMMON_FLAGS += -DDEBUG -g -O0
else
    COMMON_FLAGS += -Os -mtune=native
endif

CFLAGS   += $(COMMON_FLAGS) $(SHARED_LIB_FLAGS)
CPPFLAGS += $(COMMON_FLAGS) $(SHARED_LIB_FLAGS)


all:lib
exe:$(EXE)
lib:$(LIB)

$(EXE): $(EXEOBJ) $(LIB)
	$(LD) -o $@ $(LDFLAGS) $(EXEOBJ) $(COMMON_FLAGS) $(LIB) $(LIBS)
	LD_LIBRARY_PATH=. ./$(EXE)
$(LIB):$(OBJ)
	$(LD) -o $@ $(SHARED_LIB_FLAGS) $(OBJ)

$(OBJDIR)/%.o : %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@
$(OBJDIR)/%.o : %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@
	
clean:
	-rm -f $(OBJ)
	-rm -f $(EXE)
	-rm -f $(LIB)
#   -rm -r $(OBJDIR)

.PHONY:clean all exe lib

-include $(shell mkdir $(OBJDIR) 2>/dev/null) $(wildcard $(OBJDIR)/*.d)
