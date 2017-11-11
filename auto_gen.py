#!/usr/bin/env python

from __future__ import print_function
import os
import sys
import shutil

def get_file_name(file_location):
    return file_location.split('/')[-1].split('.')[0]


def gen_cmakelist_content(exec_location, library_location):
    exec_name = get_file_name(exec_location)
    library_name = get_file_name(library_location)
    library_name = library_location.split('/')[-1].split('.')[0]
    version_required = "cmake_minimum_required (VERSION 2.6)\n"
    add_library = "add_library(%s %s)\n" % (library_name, library_location)
    add_executable = "add_executable(%s %s)\n" % (exec_name, exec_location)
    target_link_libraries = "target_link_libraries(%s %s)" % (exec_name, library_name)
    return ''.join((version_required, add_library, add_executable, target_link_libraries))


def compile_and_make(library_location, exec_location):
    """
    use two source code to compile
    generate a cmakelist
    then make
    """
    exec_name = get_file_name(exec_location)
    BASE_DIR = os.path.dirname(os.path.abspath(__file__))
    BUILD_DIR = os.path.join(BASE_DIR, "build")
    if os.path.exists(BUILD_DIR):
        shutil.rmtree(BUILD_DIR)
    os.mkdir(BUILD_DIR)

    cmakelist_content = gen_cmakelist_content(exec_location, library_location)
    
    with open(os.path.join(BASE_DIR, "CMakelists.txt"), 'w') as fi:
        fi.write(cmakelist_content)
    if not os.path.exists("bin"):
        os.mkdir("bin")
    os.system('cd "%s" && cmake .. && make' % BUILD_DIR)
    if os.path.exists(os.path.join(BUILD_DIR, exec_name)):
        os.remove(os.path.join(BASE_DIR, "bin", exec_name))
    shutil.move(os.path.join(BUILD_DIR, exec_name), os.path.join(BASE_DIR, "bin"))
    shutil.rmtree(BUILD_DIR)
    os.system('echo "RUNNING: \n" && ./bin/%s' % exec_name)


def main():
    exec_location = sys.argv[2]
    library_location = sys.argv[1]
    compile_and_make(library_location, exec_location)


if __name__ == '__main__':
    main()

