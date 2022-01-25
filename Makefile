##
# Project Title
#
# @file
# @version 0.1
all:
	gcc ./src/*.c -o ./build/bin/base
run:
	make all && ./build/bin/base

# end
