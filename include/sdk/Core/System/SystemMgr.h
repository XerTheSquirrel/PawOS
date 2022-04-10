// ---------------------------------------------------------------------------
// PawOS
//     Copyright (C) Stephanie Gawroriski <xer@multiphasicapps.net>
// ---------------------------------------------------------------------------
// PawOS is under the GNU General Public License v3+, or later.
// See license.mkd for licensing and copyright information.
// ---------------------------------------------------------------------------

/**
 * System Management.
 * 
 * @since 2022/04/10
 */

#ifndef PAWOS_SYSTEMMGR_H
#define PAWOS_SYSTEMMGR_H

#include <PalmTypes.h>

/* Anti-C++. */
#ifdef __cplusplus
#ifndef PAWOS_CXX_IS_EXTERNED
#define PAWOS_CXX_IS_EXTERNED
#define PAWOS_CXX_PAWOS_SYSTEMMGR_H
extern "C"
{
#endif /* #ifdef PAWOS_CXX_IS_EXTERNED */
#endif /* #ifdef __cplusplus */

/*--------------------------------------------------------------------------*/

/**
 * Represents a single entry in the library table.
 * 
 * @since 2022/04/10
 */
typedef struct SysLibTblEntryType
{
	/** Pointer to the dispatch table. */
	MemPtr* dispatchTblP;
	
	/** Pointer to the globals the library uses. */
	MemPtr globalsP;
	
	/** The database ID of the library. */
	LocalID dbID;
	
	/** Handle to the code resource library. */
	MemPtr codeRscH;
} SysLibTblEntryType;

/**
 * Pointer to a @c SysLibTblEntryType.
 * 
 * @since 2022/04/10
 */
typedef SysLibTblEntryType* SysLibTblEntryPtr;

/**
 * Palm OS Main entry point.
 * 
 * @param cmd The command that is used to launch the program.
 * @param cmdPBP The command pointer, this is optional and may be @c NULL.
 * @param launchFlags The flags used to launch the application.
 * @return Return @c 0 on success, otherwise any other error code. Note that
 * this may have special meaning depending on the application.
 * @since 2022/04/10
 */
__attribute__((unused))
UInt32 PilotMain(UInt16 cmd, void* cmdPBP, UInt16 launchFlags);

/**
 * Entry point for library procedures.
 * 
 * @param uRefNum Library reference number.
 * @param entryP Entry pointer within the library table.
 * @return Any resultant error.
 * @since 2022/04/10
 */
Err (*SysLibEntryProcPtr)(UInt16 uRefNum, SysLibTblEntryPtr entryP);

/**
 * Entry point for libraries.
 * 
 * @param uRefNum Reference number.
 * @param entryP Entry pointer within the library table.
 * @return Any resultant error.
 * @since 2022/04/10
 */
__attribute__((unused))
Err __Startup__(UInt16 uRefNum, SysLibTblEntryPtr entryP);

/*--------------------------------------------------------------------------*/

/* Anti-C++. */
#ifdef __cplusplus
#ifdef PAWOS_CXX_PAWOS_SYSTEMMGR_H
}
#undef PAWOS_CXX_PAWOS_SYSTEMMGR_H
#undef PAWOS_CXX_IS_EXTERNED
#endif /* #ifdef PAWOS_CXX_PAWOS_SYSTEMMGR_H */
#endif /* #ifdef __cplusplus */

#endif /* PAWOS_SYSTEMMGR_H */
