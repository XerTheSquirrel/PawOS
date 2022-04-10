# ---------------------------------------------------------------------------
# PawOS
#     Copyright (C) Stephanie Gawroriski <xer@multiphasicapps.net>
# ---------------------------------------------------------------------------
# PawOS is under the GNU General Public License v3+, or later.
# See license.mkd for licensing and copyright information.
# ---------------------------------------------------------------------------

# Common type codes
set(TYPE_CODE_APPLICATION "appl")
set(TYPE_CODE_LIBRARY "libr")
set(TYPE_CODE_PREFERENCE_PANEL "panl")

# We need a macro to adjust the toolchain entries of each ROM entry
macro(enable_arm_palmos_toolchain)
    set(CMAKE_SYSTEM_NAME palmos)
    set(CMAKE_SYSTEM_PROCESSOR arm)
    set(CMAKE_C_COMPILER "${ARM_PALMOS_GCC}")
    set(CMAKE_C_COMPILER_AR "${ARM_PALMOS_AR}")
    set(CMAKE_C_LINK_EXECUTABLE "${ARM_PALMOS_LD}")
    set(CMAKE_C_FLAGS
    	"-ffixed-r9 -fPIC -nostdlib -nostdinc -ffunction-sections")
    set(CMAKE_ASM_COMPILER "${ARM_PALMOS_AS}")
endmacro()

# Macro to simplify the creation of rules shared with everything
macro(native_arm_application typeCode creatorCode ...)
	# Enable ARM compiler support
	enable_arm_palmos_toolchain()

	# Setup like for all arguments
	set(native_arm_sources)
	set(trim_counter 0)
	foreach(native_arm_source IN ITEMS ${ARGV})
		math(EXPR trim_counter "${trim_counter} + 1")

		# Ignore all the start because they are treated as sources
		if(${trim_counter} LESS 3)
			continue()
		endif()

		# Add to the source list
		list(APPEND native_arm_sources "${native_arm_source}")
	endforeach()

	# Define application as a library
	add_library(rom-${typeCode}-${creatorCode} SHARED
		${native_arm_sources})

	# Use the PalmOS SDK we created
	target_include_directories(rom-${typeCode}-${creatorCode}
		PUBLIC "${PROJECT_SOURCE_DIR}/include/sdk")
endmacro()

# Add all the ROM entries that would be collected into a built-in ROM
file(GLOB PAWOS_ROM_ENTRIES "????-????")
foreach(PAWOS_ROM_ENTRY ${PAWOS_ROM_ENTRIES})
	# Ignore non-directories
	if(NOT IS_DIRECTORY "${PAWOS_ROM_ENTRY}")
		continue()
	endif()

	# Get the base name
	get_filename_component(PAWOS_ROM_ENTRY_BASE "${PAWOS_ROM_ENTRY}" NAME)

	# Include sub-directory
	message("Registering ROM entry ${PAWOS_ROM_ENTRY_BASE}...")
	add_subdirectory("${PAWOS_ROM_ENTRY_BASE}")
endforeach()
