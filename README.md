# Sleep-Sort
Sleep sort is fun. :) 

## Shenanigans
Sleep sort works by examining each element of a list of positive integers, and then forking a new process or spawning
a new thread that will sleep for the duration of the value of that element. Said element will then be output to the screen, or
placed into a sorted list. Fun right?

This repository contains sleep sort implemented in both Bash and C++. The Bash implementation utilizes new processes, while the
C++ implementation utilizes threads.
