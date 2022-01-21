##
# ProjetoFinal
#
# @file
# @version 0.1

inc_dir := ./include/
src_dir := ./src/
sources := $(wildcard ${src_dir}/*.c)

build_dir := ./build/

all:
	gcc ./src/*.c -o ./build/bin/base && ./build/bin/base
compile:
	gcc ./src/*.c -o ./build/bin/base

# end
