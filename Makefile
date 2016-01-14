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

MODULES = core observer tests

GPP_FLAGS = -std=c99 -std=gnu99 -W -Wall -Werror

define make-objects
$1/%.o: $(patsubst build/%,src/%,$1)/%.c
	@echo $1
	@echo $1/%.o and $(patsubst build/%,src/%,$1)%.c
	@g++ $(GPP_FLAGS) -O $(INCLUDES) -fPIC -o $$@ -c $$<
endef

$(foreach bdir, $(BUILD_DIR), $(eval $(call make-objects,$(bdir))))

define make-mod

$(eval $@SRC_DIR := $(MODULES_DIR)/$1/src/)
$(eval $@BUILD_DIR := $(MODULES_DIR)/$1/build/)

$(eval SRC := $(foreach sdir,  $($@SRC_DIR), $(wildcard $(sdir)/*.c)) $(foreach sdir, $($@SRC_DIR), $(wildcard $(sdir)/*.cpp)))
$(eval OBJ := $(patsubst src/%.c, build/%.o, $($@SRC)))

$(eval $@INCLUDES := $(addprefix -I, $(MODULES_DIR)/$1/src/))

$(addprefix $1, -checkdirs):
	@mkdir -p $($@BUILD_DIR)

$1/build/%.o: $1/src/%.c $1/src/%.cpp
	@echo $1
	@echo $1/%.o and $(patsubst build/%,src/%,$1)%.c
	@g++ $(GPP_FLAGS) -O $($@INCLUDES) -fPIC -o $$@ -c $$<

$(addprefix $1, -build):
	@echo "Building the $1 with includes $($@INCLUDES)..."
	@g++ -g $(GPP_FLAGS) $($@INCLUDES) -o $($@BUILD_DIR) $($@OBJ)
	@echo "Success! All done. Module $1 built successfully"

$(addprefix $1, -clean):
	@echo "Cleaning build directory of $1 which is $($@BUILD_DIR)"
	@rm -rf $(MODULES_DIR)/$($@BUILD_DIR) || true

endef

$(foreach mod,$(MODULES),$(eval $(call make-mod,$(mod))))

all: $(foreach mod, $(MODULES), $(mod)-checkdirs) $(foreach mod, $(MODULES), $(mod)-build)
	@echo "Building the $(modname)..."
	@echo "Success! All done. Module $(modname) built successfully"
	
.PHONY: clean 
clean: $(foreach mod, $(MODULES), $(mod)-clean)
	@echo "Cleaning build directory..."



