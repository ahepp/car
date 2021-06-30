#!/bin/bash

cd $(dirname $0)/..

source docker/docker.env

docker run \
    --mount type=bind,source="$(pwd)",target=/ws \
    --user 1000:1000 \
    "${IMAGE}" \
    bash -c "$1"
