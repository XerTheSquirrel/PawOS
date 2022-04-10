# ---------------------------------------------------------------------------
# HandOS
#     Copyright (C) Stephanie Gawroriski <xer@multiphasicapps.net>
# ---------------------------------------------------------------------------
# HandOS is under the GNU General Public License v3+, or later.
# See license.mkd for licensing and copyright information.
# ---------------------------------------------------------------------------

# Use this version of CMake
cmake_minimum_required(VERSION 3.13)

# This is our project!
project(HandOS
	VERSION 0.1
	DESCRIPTION "High level Palm OS re-implementation."
	HOMEPAGE_URL https://github.com/XerTheSquirrel/PawOS
	LANGUAGES C)

# To Emily and Near...
message("******************************")
message("To my close friends who are not here today, your friendships were")
message("very important to me. I hope that you are both resting in piece:")
message("  * Emily, developer of Mu. (1998-2020)")
message("  * Near, developer of Higan and Ares. (1983-2021)")
message(" -- Your friend, Stephanie")
message("******************************")

# We need the resource compiler for PalmOS
find_program(PILRC_PATH pilrc
	DOC "Palm OS Resource Compiler"
	REQUIRED)
message("Found PilRC (Palm OS Resource Compiler) at ${PILRC_PATH}")

# Enable support for testing, this is needed here otherwise testing will not
# work at all! Major headache this has caused...
# From: https://cmake.org/cmake/help/v3.13/command/enable_testing.html
# > Note that ctest expects to find a test file in the build directory root.
# > Therefore, this command should be in the source directory root.
enable_testing()

# Add tools
add_subdirectory(tools)

# Add sources
add_subdirectory(src)

# Add ROM entries
add_subdirectory(rom)

# Add tests
add_subdirectory(tests)
