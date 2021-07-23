# car
A c based program that is intended to evolve into a lisp based on Paul Graham's [bel spec](https://sep.yimg.com/ty/cdn/paulgraham/bellanguage.txt?t=1595850613&).

Ideally, this will bootstrap [bel in bel](https://sep.yimg.com/ty/cdn/paulgraham/bel.bel?t=1595850613&).

## Building
First, construct the docker build environment image:

    $ docker/build-image.sh
    
Next, build `car`:

    $ docker/exec.sh make
    
Assuming your C standard library is compatible with the docker image, the resulting `car` executable should be able to be run on the host system.
Of course, you could also run:

    $ docker/exec.sh car
    
## Testing
The default `make` target also produces an executable `tests`. As with `car`, the executable should depend only on libc.

The Makefile also has a target `val`, which will run the tests in the valgrind environment (to detect some memory errors).
To build this (phony) target, you could run:

    $ docker/exec.sh "make val"

## Odds and Ends

`docker/dev-shell.sh` should drop you into the dockerized build environment.
Of course, if you prefer to not use docker, you could simply inspect the Dockerfile to find what packages must be installed.
