#!/usr/bin/env python

from __future__ import print_function
import os
import sys
import shutil

def compile_and_make(library_name, exec_name):
    """
    use two source code to compile
    generate a cmakelist
    then make
    """
    BASE_DIR = os.path.dirname(os.path.abspath(__file__))
    BUILD_DIR = os.path.join(BASE_DIR, "build")
    if os.path.exists(BUILD_DIR):
        shutil.rmtree(BUILD_DIR)
    os.mkdir(BUILD_DIR)

    cmakelist_content = "cmake_minimum_required (VERSION 2.6)\n" \
                        "add_library(%s %s.c)\n" \
                        "add_executable(%s %s.c)\n" \
                        "target_link_libraries(ExpressionConvertor Stack_Array)" % (library_name, library_name, exec_name, exec_name)
    with open(os.path.join(BASE_DIR, "CMakelists.txt"), 'w') as fi:
        fi.write(cmakelist_content)
    os.system('cd "%s" && cmake .. && make && mv %s .. && rm -rf %s && cd %s && echo "RUNNING: \n" && ./%s' % (BUILD_DIR, exec_name, BUILD_DIR, BASE_DIR, exec_name))


def main():
    exec_name = sys.argv[2]
    library_name = sys.argv[1]
    compile_and_make(library_name, exec_name)

if __name__ == '__main__':
    main()

