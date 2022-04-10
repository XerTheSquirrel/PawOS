# ---------------------------------------------------------------------------
# HandOS
#     Copyright (C) Stephanie Gawroriski <xer@multiphasicapps.net>
# ---------------------------------------------------------------------------
# HandOS is under the GNU General Public License v3+, or later.
# See license.mkd for licensing and copyright information.
# ---------------------------------------------------------------------------

# Add all the ROM entries that would be collected into a built-in ROM
file(GLOB HANDOS_ROM_ENTRIES "????-????")
foreach(HANDOS_ROM_ENTRY ${HANDOS_ROM_ENTRIES})
	# Ignore non-directories
	if(NOT IS_DIRECTORY "${HANDOS_ROM_ENTRY}")
		continue()
	endif()

	# Get the base name
	get_filename_component(HANDOS_ROM_ENTRY_BASE "${HANDOS_ROM_ENTRY}" NAME)

	# Include sub-directory
	message("Registering ROM entry ${HANDOS_ROM_ENTRY_BASE}...")
	add_subdirectory("${HANDOS_ROM_ENTRY_BASE}")
endforeach()
