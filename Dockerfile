FROM ubuntu:18.04

ARG UNAME=usr
ARG UID=1000
ARG GID=1000
ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        build-essential \
        g++ \
        libgtest-dev \
        libuv1-dev libssl-dev libz-dev gnuplot git \
        python3 \
        python3-dev \
        python3-setuptools \
        libpython3-dev \
        python3-numpy \
        python3-matplotlib \
        python3-pandas \
        cmake \
        python3-pip && \
    rm -rf /var/lib/apt/lists/*

RUN cd /tmp && \
    git clone https://github.com/uWebSockets/uWebSockets && \
    cd uWebSockets && \
    git checkout e94b6e1 && \
    cmake . && \
    make -j && \
    make install && \
    cd .. && rm -r uWebSockets && \
    ln -s /usr/lib64/libuWS.so /usr/lib/libuWS.so

RUN pip3 install -U --no-cache-dir pip carla pygame

RUN echo "deb [arch=amd64 trusted=yes] http://dist.carla.org/carla bionic main" >> /etc/apt/sources.list && \
    apt-get update --allow-unauthenticated && \
    apt-get install -y --allow-unauthenticated carla-simulator=0.9.10-2 && \
    rm -rf /var/lib/apt/lists/*

# Add user and set as default
RUN groupadd -g $GID -o $UNAME
RUN useradd -m -u $UID -g $GID -o -s /bin/bash $UNAME

USER $UNAME