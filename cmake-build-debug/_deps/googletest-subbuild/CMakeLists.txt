# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.20.2)

# We name the project and the target for the ExternalProject_Add() call
# to something that will highlight to the user what we are working on if
# something goes wrong and an error message is produced.

project(googletest-populate NONE)



include(ExternalProject)
ExternalProject_Add(googletest-populate
                     "UPDATE_DISCONNECTED" "False" "URL" "https://github.com/google/googletest/archive/release-1.10.0.tar.gz" "URL_HASH" "SHA256=9dc9157a9a1551ec7a7e43daea9a694a0bb5fb8bec81235d8a1e6ef64c716dcb"
                    SOURCE_DIR          "D:/Programming/c++/skillbox/cmake-build-debug/_deps/googletest-src"
                    BINARY_DIR          "D:/Programming/c++/skillbox/cmake-build-debug/_deps/googletest-build"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
                    USES_TERMINAL_DOWNLOAD  YES
                    USES_TERMINAL_UPDATE    YES
)


