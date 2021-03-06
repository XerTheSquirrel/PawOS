// ---------------------------------------------------------------------------
// PawOS
//     Copyright (C) Stephanie Gawroriski <xer@multiphasicapps.net>
// ---------------------------------------------------------------------------
// PawOS is under the GNU General Public License v3+, or later.
// See license.mkd for licensing and copyright information.
// ---------------------------------------------------------------------------

/**
 * Palm OS Types.
 * 
 * @since 2022/04/10
 */

#ifndef PAWOS_PALMTYPES_H
#define PAWOS_PALMTYPES_H

/* Anti-C++. */
#ifdef __cplusplus
#ifndef PAWOS_CXX_IS_EXTERNED
#define PAWOS_CXX_IS_EXTERNED
#define PAWOS_CXX_PAWOS_PALMTYPES_H
extern "C"
{
#endif /* #ifdef PAWOS_CXX_IS_EXTERNED */
#endif /* #ifdef __cplusplus */

/*--------------------------------------------------------------------------*/

/**
 * Signed 16-bit integer.
 * 
 * @since 2022/04/10
 */
typedef signed short Int16;

/**
 * Unsigned 16-bit integer.
 * 
 * @since 2022/04/10
 */
typedef unsigned short UInt16;

/**
 * Signed 32-bit integer.
 * 
 * @since 2022/04/10
 */
typedef signed int Int32;

/**
 * Unsigned 32-bit integer.
 * 
 * @since 2022/04/10
 */
typedef unsigned int UInt32;

/**
 * Memory pointer.
 * 
 * @since 2022/04/10
 */
typedef void* MemPtr;

/**
 * Error type.
 * 
 * @since 2022/04/10
 */
typedef UInt16 Err;

/**
 * Local identifier.
 * 
 * @since 2022/04/10
 */
typedef UInt32 LocalID;

/*--------------------------------------------------------------------------*/

/* Anti-C++. */
#ifdef __cplusplus
#ifdef PAWOS_CXX_PAWOS_PALMTYPES_H
}
#undef PAWOS_CXX_PAWOS_PALMTYPES_H
#undef PAWOS_CXX_IS_EXTERNED
#endif /* #ifdef PAWOS_CXX_PAWOS_PALMTYPES_H */
#endif /* #ifdef __cplusplus */

#endif /* PAWOS_PALMTYPES_H */
