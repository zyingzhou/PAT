cmake_minimum_required(VERSION 3.15)
project(PAT C)

set(CMAKE_C_STANDARD 99)

add_executable(pat1001 ./C/pat1001.c)
add_executable(pat1002 ./C/pat1002.c)
add_executable(pat1004 ./C/pat1004.c)
add_executable(pat1006 ./C/pat1006.c)
add_executable(pat1008 ./C/pat1008.c)
add_executable(pat1009 ./C/pat1009.c)
add_executable(pat1011 ./C/pat1011.c)
add_executable(pat1014 ./C/pat1014.c)
add_executable(pat1016 ./C/pat1016.c)
add_executable(pat1018 ./C/pat1018.c)
add_executable(pat1021 ./C/pat1021.c)
add_executable(pat1022 ./C/pat1022.c)
add_executable(pat1023 ./C/pat1023.c)
add_executable(pat1026 ./C/pat1026.c)
add_executable(pat1027 ./C/pat1027.c)
add_executable(pat1012 ./C/pat1012.c)

# debug only
add_executable(test1 tests/test.c)