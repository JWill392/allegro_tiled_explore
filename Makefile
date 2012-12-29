CC      := clang
TARGET  := explore
CFLAGS  := -I../include -g -Wall
LDFLAGS := -L..
LIBS    := $(shell pkg-config --cflags --libs allegro-5.0 allegro_acodec-5.0 allegro_audio-5.0 allegro_color-5.0 allegro_dialog-5.0 allegro_font-5.0 allegro_image-5.0 allegro_main-5.0 allegro_memfile-5.0 allegro_physfs-5.0 allegro_primitives-5.0 allegro_ttf-5.0 allegro_tiled-5.0)
SOURCES := $(shell find src/ -type f -name "*.c")
OBJECTS := $(SOURCES:.c=.o)

$(TARGET): $(OBJECTS)
	@echo "  Linking..."; $(CC) $(LDFLAGS) $^ -o $(TARGET) $(LIBS)

%.o: %.c
	@echo "  CC $<"; $(CC) $(CFLAGS) -c -o $@ $<

clean:
	@echo "  Cleaning..."; $(RM) src/*.o $(TARGET)

run: $(TARGET)
	@echo "  Starting..."; LD_LIBRARY_PATH=.. ./$(TARGET)

.PHONY: clean run
