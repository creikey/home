ofiles = main.o draw_time.o world_map.o

.PHONY: clean

home: $(ofiles)
	gcc -o home $(ofiles) $(shell pkg-config --libs operomnia)

static_home: $(ofiles)
	gcc -o home_static $(ofiles) $(shell pkg-config --libs --static operomnia_static)

debug: $(ofiles)
		gcc -o home_debug $(ofiles) $(shell pkg-config --libs operomnia) -g

world_map.o: world_map.c world_map.h
	gcc -c world_map.c

main.o: main.c conf.h
	gcc -c main.c

draw_time.o: draw_time.c draw_time.h
	gcc -c draw_time.c

clean:
	-rm home_static
	-rm home_debug
	-rm home
	-rm *.o
	-rm *.gch
