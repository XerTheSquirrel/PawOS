# ---------------------------------------------------------------------------
# PawOS
#     Copyright (C) Stephanie Gawroriski <xer@multiphasicapps.net>
# ---------------------------------------------------------------------------
# PawOS is under the GNU General Public License v3+, or later.
# See license.mkd for licensing and copyright information.
# ---------------------------------------------------------------------------

# Use this version of CMake
cmake_minimum_required(VERSION 3.13)

# This is our project!
project(PawOS
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

# We also need the Palm OS Toolchain
find_program(ARM_PALMOS_AR arm-palmos-ar
	DOC "ARM PalmOS Ar"
	REQUIRED)
find_program(ARM_PALMOS_AS arm-palmos-as
	DOC "ARM PalmOS Assembler"
	REQUIRED)
find_program(ARM_PALMOS_GCC arm-palmos-gcc
	DOC "ARM PalmOS GCC"
	REQUIRED)
find_program(ARM_PALMOS_LD arm-palmos-ld
	DOC "ARM PalmOS LD"
	REQUIRED)
message("Found ARM PalmOS Toolchain...")
message(" - AR : ${ARM_PALMOS_AR}")
message(" - AS : ${ARM_PALMOS_AS}")
message(" - GCC: ${ARM_PALMOS_GCC}")
message(" - LD : ${ARM_PALMOS_LD}")

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
