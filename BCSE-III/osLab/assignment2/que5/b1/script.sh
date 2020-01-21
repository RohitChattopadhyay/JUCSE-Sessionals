#!/bin/bash
gcc caller.c -o caller
gcc receiver.c -o receiver
gnome-terminal -e ./receiver
gnome-terminal -e ./caller