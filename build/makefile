CXX = clang++
SDL_LIB = -L/usr/local/lib -lSDL2 -lSDL2_image -lSDL2_ttf
TEST_LIB = -lcppunit
FAKEIT_INCLUDE = -I/home/jared/cpp_dev/FakeIt/single_header/standalone
SDL_INCLUDE = -I/usr/include/SDL2
INC_INCLUDE = -I../inc
CXX_FLAGS = -Werror -pedantic-errors -O0 -Wno-c++98-compat-pedantic -Wno-padded -std=c++11 $(SDL_INCLUDE) $(INC_INCLUDE) $(FAKEIT_INCLUDE)
LINKER_FLAGS = $(SDL_LIB) $(TEST_LIB)
OBJ_FILES = sprite.o easy_sdl.o game_renderer.o game.o character.o sprite_clipper.o \
walking_state.o standing_state.o input_handler.o input_event.o camera.o scene.o \
game_component_factory.o scenery.o following_state.o text_box.o glyph.o recruitable_state_decorator.o
TEST_OBJ_FILES = test_background.o
VPATH = ../src/test:../src/main:../src/main/input:../src/main/character

all: Labyrinth tests cscope

%.o: %.cpp
	$(CXX) $(CXX_FLAGS) -c $<

Labyrinth: $(OBJ_FILES) Labyrinth.o
	$(CXX) $(LINKER_FLAGS) -o Labyrinth $(OBJ_FILES) Labyrinth.o

tests: $(TEST_OBJ_FILES)
	$(CXX) $(LINKER_FLAGS) -o tests $(TEST_OBJ_FILES) $(OBJ_FILES)

.PHONY : clean

clean: 
	-rm *.o Labyrinth tests

.DELETE_ON_ERROR: 

test:
	./tests

cscope:
	cd ~/Games/Labyrinth && find . -name "*.h" > cscope.files && \
	find . -name "*.cpp" >> cscope.files && cscope -b -q -k -R

build_linux:
	cp *.o builds/linux/ && cp sketch_1 builds/linux/
