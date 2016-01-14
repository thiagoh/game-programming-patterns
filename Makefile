modname = game-programming-patterns

#
#MODULES = modules/core modules/observer modules/tests
#
#.PHONY: all 
#
#all:
#	@for dir in $(MODULES); do \
#      $(MAKE) -C $$dir; \
#    done
#	
#.PHONY: clean 
#clean:
#	@for dir in $(MODULES); do \
#		echo "Cleaning build $$dir/build directory..." ; \
#		rm -rf $$dir/build || true ;\
#    done


MODULES_DIR = modules

MODULES = core observer state tests

##
## https://gcc.gnu.org/onlinedocs/gcc-3.0/gcc_3.html#SEC11
##
## You can request many specific warnings with options beginning `-W', 
## for example `-Wimplicit' to request warnings on implicit declarations. 
## Each of these specific warning options also has a negative form
## beginning `-Wno-' to turn off warnings; for example, `-Wno-implicit'. 
## This manual lists only one of the two forms, whichever is not the default.
##
CXX_FLAGS += -O3 -g -std=c++0x -pg -D_DEBUG -W -Wall -Werror -Wno-unused

print-vars:
	@echo "CXX_FLAGS is $(CXX_FLAGS)"

define make-mod

$(eval $@SRC_DIR := $(MODULES_DIR)/$1/src)
$(eval $@BUILD_DIR := $(MODULES_DIR)/$1/build)

$(eval $@SRC := $(foreach sdir,  $($@SRC_DIR), $(wildcard $(sdir)/*.c)) $(foreach sdir, $($@SRC_DIR), $(wildcard $(sdir)/*.cpp)))
$(eval $@OBJ := $(patsubst $($@SRC_DIR)/%.c, $($@BUILD_DIR)/%.o, $(patsubst $($@SRC_DIR)/%.cpp, $($@BUILD_DIR)/%.o, $($@SRC))))

$(eval $@INCLUDES := $(addprefix -I, $(MODULES_DIR)/$1/src))

.PHONY: $(addprefix $1, -checkdirs)
$(addprefix $1, -checkdirs):
	@mkdir -p $($@BUILD_DIR)

$($@BUILD_DIR)/%.o: $($@SRC_DIR)/%.c $(addprefix $1, -checkdirs)
	@echo "Compiling $1 dependency $$< into $$@"
	@#echo $1/%.o and $(patsubst build/%,src/%,$1)%.c
	@g++ $(CXX_FLAGS) -O $($@INCLUDES) -fPIC -o $$@ -c $$<

$($@BUILD_DIR)/%.o: $($@SRC_DIR)/%.cpp $(addprefix $1, -checkdirs)
	@echo "Compiling $1 dependency $$< into $$@"
	@#echo $1/%.o and $(patsubst build/%,src/%,$1)%.c
	@g++ $(CXX_FLAGS) -O $($@INCLUDES) -fPIC -o $$@ -c $$<
	
.PHONY: $(addprefix $1, -build)
$(addprefix $1, -build): $($@OBJ)
	@echo "Building the $1 with includes $($@INCLUDES) and objects $($@OBJ)"
ifneq ($(strip $$($@OBJ)),)
	@g++ $(CXX_FLAGS) $($@INCLUDES) -o $($@BUILD_DIR)/$1 $($@OBJ)
endif
	@echo "Success! All done. Module $1 built successfully"

.PHONY: $(addprefix $1, -clean)
$(addprefix $1, -clean):
	@echo "Cleaning build directory of $1 which is $($@BUILD_DIR)"
	@rm -rf $($@BUILD_DIR) || true

endef

$(foreach mod,$(MODULES),$(eval $(call make-mod,$(mod))))

.PHONY: all
all: $(foreach mod, $(MODULES), $(mod)-checkdirs) $(foreach mod, $(MODULES), $(mod)-build)
	@echo "Building the $(modname)..."
	@echo "Success! All done. Module $(modname) built successfully"
	
.PHONY: clean 
clean: $(foreach mod, $(MODULES), $(mod)-clean)
	@echo "Cleaning build directory..."



