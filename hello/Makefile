ARCH := $(shell uname -m)

all: build/hello

build/hello: build/hello.o
	ld -o build/hello build/hello.o

build/hello.o: $(ARCH)/hello.s common/hello.s
	@mkdir -p build
	as -o build/hello.o $(ARCH)/hello.s common/hello.s

clean:
	rm -rf build
