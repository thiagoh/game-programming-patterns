
modname = observer

SRC_DIR   := src/
BUILD_DIR := build/

GPP_FLAGS = -W -Wall -Werror

SRC       := $(foreach sdir,$(SRC_DIR),$(wildcard $(sdir)/*.c)) $(foreach sdir,$(SRC_DIR),$(wildcard $(sdir)/*.cpp))
OBJ       := $(patsubst src/%.c,build/%.o,$(SRC))

INCLUDES  := $(addprefix -I,$(SRC_DIR)) 

.PHONY: all checkdirs

all: checkdirs $(OBJ)
	@#echo $(BUILD_DIR)
	@#echo $(SRC_DIR)
	@#echo $(SRC)
	@#echo $(OBJ)
	@#echo $(INCLUDES)
	@#sudo apxs -i -a -l cryptoc -l ssl -l crypto -Wc,-Wall -I . -n $(modname) -c src/core/mod_token_auth.c $(OBJ)
	@echo "Building the $(modname))..."
	@#sudo g++ -g $(GPP_FLAGS) $(INCLUDES) -o $(BUILD_DIR)/$(modname) $(OBJ)
	@g++ -g $(GPP_FLAGS) $(INCLUDES) -o $(BUILD_DIR)/$(modname) $(OBJ)
	@echo "Success! All done. Module $(modname) built successfully"

checkdirs: $(BUILD_DIR)
	
$(BUILD_DIR):
	@mkdir -p $@

define make-goal
$1/%.o: $(patsubst build/%,src/%,$1)/%.c
	@echo $1
	@echo $1/%.o and $(patsubst build/%,src/%,$1)%.c
	@g++ -std=c99 -std=gnu99 -O $(INCLUDES) -Wall -fPIC -o $$@ -c $$<
endef

$(foreach bdir,$(BUILD_DIR),$(eval $(call make-goal,$(bdir))))

.PHONY: clean 
clean:
	@echo "Cleaning build directory..."
	@rm -rf $(builddir) || true


