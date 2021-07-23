FROM debian:sid-slim

RUN dpkg-reconfigure debconf -f noninteractive -p critical

RUN apt-get update && apt-get install --no-install-recommends -y \
    clang \
    clang-format \
    gdb \
    make \
    valgrind

ENV LANG=en_US.UTF-8

RUN groupadd -g 1000 dev \
	&& useradd -m -u 1000 -g dev dev

USER dev

WORKDIR /ws
