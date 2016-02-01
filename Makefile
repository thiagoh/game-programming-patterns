modname = game-programming-patterns

MODULES_DIR = modules

GLOBAL_INCLUDE_MODULE = core
GLOBAL_MODULE = core

EXEC_MODULES = observer state tests pointer-to-function lambda
MODULES = observer state tests pointer-to-function lambda

##
## https://gcc.gnu.org/onlinedocs/gcc-3.0/gcc_3.html#SEC11
##
## You can request many specific warnings with options beginning `-W', 
## for example `-Wimplicit' to request warnings on implicit declarations. 
## Each of these specific warning options also has a negative form
## beginning `-Wno-' to turn off warnings; for example, `-Wno-implicit'. 
## This manual lists only one of the two forms, whichever is not the default.
##
CXX_FLAGS += -O3 -std=c++0x -pg -D_DEBUG -W -Wall -Werror -Wno-unused -Wno-unused-parameter
CXX_FLAGS += -g -rdynamic 
CXX_FLAGS += -O 
LIBS += -lcppunit

_GLOBAL_SRC_DIR := $(MODULES_DIR)/$(GLOBAL_MODULE)/src
_GLOBAL_BUILD_DIR := $(MODULES_DIR)/$(GLOBAL_MODULE)/build
_GLOBAL_MODULE := $(MODULES_DIR)/$(GLOBAL_MODULE)/src
_GLOBAL_INCLUDE_DIR := /usr/include /usr/local/include $(MODULES_DIR)/$(GLOBAL_INCLUDE_MODULE)/headers

_GLOBAL_INCLUDES := $(addprefix -I,$(_GLOBAL_INCLUDE_DIR))

_GLOBAL_SRC := $(foreach sdir, $(_GLOBAL_MODULE), $(wildcard $(sdir)/*.c)) $(foreach sdir, $(_GLOBAL_MODULE), $(wildcard $(sdir)/*.cpp))
_GLOBAL_OBJ := $(patsubst $(_GLOBAL_SRC_DIR)/%.c, $(_GLOBAL_BUILD_DIR)/%.o, $(patsubst $(_GLOBAL_SRC_DIR)/%.cpp, $(_GLOBAL_BUILD_DIR)/%.o, $(_GLOBAL_SRC)))

.PHONY: $(GLOBAL_MODULE)-checkdirs
$(GLOBAL_MODULE)-checkdirs:
	@echo "Creating directories $(_GLOBAL_BUILD_DIR)"
	@mkdir -p $(_GLOBAL_BUILD_DIR)
	@echo "Done..."
	
.PHONY: 
$(GLOBAL_MODULE)-clean:
	@echo "Cleaning build directory of $(GLOBAL_MODULE) which is $(_GLOBAL_BUILD_DIR)"
	@rm -rf $(_GLOBAL_BUILD_DIR) || true
	@echo "Done..."
	
# Global Object targets
$(_GLOBAL_BUILD_DIR)/%.o: $(_GLOBAL_SRC_DIR)/%.cpp
	@echo "Compiling $(GLOBAL_MODULE) dependency $< into $@ with includes $($@INCLUDES)"
	@#echo $1/%.o and $(patsubst build/%,src/%,$1)%.c
	g++ $(CXX_FLAGS) $(_GLOBAL_INCLUDES) -fPIC -o $@ -c $<
	@echo "Done..."
	
.PHONY: global-build
global-build: $(_GLOBAL_OBJ)
	@echo "Done..."
	
.PHONY: print-vars	
print-vars:
	@echo "CXX_FLAGS $(CXX_FLAGS)"
	@echo "_GLOBAL_INCLUDES $(_GLOBAL_INCLUDES)"
	@echo "GLOBAL_INCLUDE_MODULE $(GLOBAL_INCLUDE_MODULE)"

define make-mod

$(eval $@SRC_DIR := $(MODULES_DIR)/$1/src)
$(eval $@BUILD_DIR := $(MODULES_DIR)/$1/build)

$(eval $@SRC := $(foreach sdir, $($@SRC_DIR), $(wildcard $(sdir)/*.c)) $(foreach sdir, $($@SRC_DIR), $(wildcard $(sdir)/*.cpp)))
$(eval $@OBJ := $(patsubst $($@SRC_DIR)/%.c, $($@BUILD_DIR)/%.o, $(patsubst $($@SRC_DIR)/%.cpp, $($@BUILD_DIR)/%.o, $($@SRC))) $($@_GLOBAL_OBJ))

$(eval $@INCLUDES := $(addprefix -I,$(_GLOBAL_INCLUDE_DIR) $(MODULES_DIR)/$1/headers))

.PHONY: $(addprefix $1, -checkdirs)
$(addprefix $1, -checkdirs): $(GLOBAL_MODULE)-checkdirs
	@echo "Creating directories $($@BUILD_DIR)"
	@mkdir -p $($@BUILD_DIR)
	@echo "Done..."

# Object targets
$($@BUILD_DIR)/%.o: $($@SRC_DIR)/%.c
	@echo "Compiling $1 dependency $$< into $$@ with includes $($@INCLUDES)"
	@#echo $1/%.o and $(patsubst build/%,src/%,$1)%.c
	g++ $(CXX_FLAGS) -O $($@INCLUDES) -fPIC -o $$@ -c $$<
	@echo "Done..."
	
# Object targets
$($@BUILD_DIR)/%.o: $($@SRC_DIR)/%.cpp 
	@echo "Compiling $1 dependency $$< into $$@ with includes $($@INCLUDES)"
	@#echo $1/%.o and $(patsubst build/%,src/%,$1)%.c
	g++ $(CXX_FLAGS) $($@INCLUDES) -fPIC -o $$@ -c $$<
	@echo "Done..."
	
$(addprefix $1, -print-vars):
	@echo "1" $1
	@echo "($@SRC_DIR)" $($@SRC_DIR)
	@echo "($@BUILD_DIR)" $($@BUILD_DIR)
	@echo "($@SRC)" $($@SRC)
	@echo "($@OBJ)" $($@OBJ)
	@echo "($@_GLOBAL_SRC_DIR)" $($@_GLOBAL_SRC_DIR)
	@echo "($@_GLOBAL_BUILD_DIR)" $($@_GLOBAL_BUILD_DIR)
	@echo "($@_GLOBAL_SRC)" $($@_GLOBAL_SRC)
	@echo "($@_GLOBAL_OBJ)" $($@_GLOBAL_OBJ)
	@echo "($@INCLUDES)" $($@INCLUDES)


	
.PHONY: $(addprefix $1, -build)
$(addprefix $1, -build): $(addprefix $1, -checkdirs) $($@OBJ) $(_GLOBAL_OBJ) 
	@echo "Building the $1 with includes $($@INCLUDES) and objects $($@OBJ)"
ifneq ($(strip $$($@OBJ)),)

ifneq (,$(findstring $1,$(EXEC_MODULES)))	
	g++ $(CXX_FLAGS) $($@INCLUDES) -o $($@BUILD_DIR)/$1 $($@OBJ) $(LIBS)
endif # ifneq (,$(findstring $1,$(EXEC_MODULES)))

endif # ifneq ($(strip $$($@OBJ)),)
	@echo "Success! All done. Module $1 built successfully"


.PHONY: $(addprefix $1, -clean)
$(addprefix $1, -clean):
	@echo "Cleaning build directory of $1 which is $($@BUILD_DIR)"
	@rm -rf $($@BUILD_DIR) || true
	@echo "Done..."

endef # define make-mod

$(foreach mod,$(MODULES),$(eval $(call make-mod,$(mod))))

.PHONY: all
all: $(foreach mod, $(MODULES), $(mod)-checkdirs) $(foreach mod, $(EXEC_MODULES), $(mod)-build)
	@echo "Building the $(modname)..."
	@echo "Success! All done. Module $(modname) built successfully"
	
.PHONY: clean 
clean: $(GLOBAL_MODULE)-clean $(foreach mod, $(MODULES), $(mod)-clean)
	@echo "Cleaning build directory..."



