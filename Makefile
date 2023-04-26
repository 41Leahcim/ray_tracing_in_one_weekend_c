src = $(wildcard src/*.c)
flags = -Wall -Wextra -fanalyzer -Os -lm
includes = -I include

app: $(src)
	gcc $(src) $(flags) $(includes) -o app

image.ppm: app
	./app > image.ppm

run: image.ppm

clean:
	rm app image.ppm
