
modname = game-programming-patterns

MODULES = modules/core modules/observer

.PHONY: all 

all:
	@for dir in $(MODULES); do \
      $(MAKE) -C $$dir; \
    done
	
.PHONY: clean 
clean:
	@for dir in $(MODULES); do \
		echo "Cleaning build $$dir/build directory..." ; \
		rm -rf $$dir/build || true ;\
    done

