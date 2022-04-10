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
 * 
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
