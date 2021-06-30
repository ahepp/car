#!/bin/bash

cd $(dirname $0)

source docker.env

docker build -t "${IMAGE}" .

