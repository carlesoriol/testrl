#! /bin/sh

gcc testrl.c -Os -lraylib -lGL  -lm -pthread -ldl -lX11 -lXrandr -lXinerama -lXi -lXxf86vm -lXcursor -o testrl

