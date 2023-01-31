#! /bin/bash
BASE=$(dirname $(realpath $0))

docker run \
    -v /tmp/.X11-unix:/tmp/.X11-unix \
    -e DISPLAY=$DISPLAY \
    -v ${BASE}:/app/project/ \
    --network=host \
    -ti \
    --shm-size=14gb \
    control bash