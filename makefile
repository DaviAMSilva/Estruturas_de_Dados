DIRS	:= build/ lib/
SOURCES	:= $(wildcard source/*.c)
OBJECTS	:= $(patsubst source/%.c,build/%.o,$(SOURCES))
LIBS	:= $(patsubst source/%.c,lib/lib%.a,$(SOURCES))





all: $(LIBS)
dirs: $(DIRS)

.PHONY: all dirs clean
.SECONDARY: $(OBJECTS)





build/%.o: source/%.c include/%.h | $(DIRS)
	gcc -c $< -Wall -O3 -o $@ -I include/

lib/lib%.a: build/%.o | $(DIRS)
	ar cr $@ $<





$(DIRS):
	mkdir -p $@

clean:
	rm -fr build/ lib/