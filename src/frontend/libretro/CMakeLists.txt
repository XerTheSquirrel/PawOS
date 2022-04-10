# ---------------------------------------------------------------------------
# PawOS
#     Copyright (C) Stephanie Gawroriski <xer@multiphasicapps.net>
# ---------------------------------------------------------------------------
# PawOS is under the GNU General Public License v3+, or later.
# See license.mkd for licensing and copyright information.
# ---------------------------------------------------------------------------

# Define our RetroArch library
add_library(pawos_libretro SHARED
	loop.c)

# Includes for RetroArch
target_include_directories(pawos_libretro
	PUBLIC "${PROJECT_SOURCE_DIR}/include"
	PUBLIC "${PROJECT_SOURCE_DIR}/include/libretro")
