ARCH := $(shell uname -m)

all: build/count_args

build/count_args: build/count_args.o
	ld -o build/count_args build/count_args.o

build/count_args.o: $(ARCH)/count_args.s
	@mkdir -p build
	as -o build/count_args.o $(ARCH)/count_args.s

clean:
	rm -rf build
