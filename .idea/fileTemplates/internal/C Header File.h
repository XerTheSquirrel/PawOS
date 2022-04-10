#parse("C File Header.h")


/**
 * Describe this.
 * 
 * @since ${YEAR}/${MONTH}/${DAY}
 */

#[[#ifndef]]# ${INCLUDE_GUARD}
#[[#define]]# ${INCLUDE_GUARD}

/* Anti-C++. */
#[[#ifdef]]# __cplusplus
#[[#ifndef]]# HANDOS_CXX_IS_EXTERNED
#[[#define]]# HANDOS_CXX_IS_EXTERNED
#[[#define]]# HANDOS_CXX_${INCLUDE_GUARD}
extern "C"
{
#[[#endif]]# /* #[[#ifdef]]# HANDOS_CXX_IS_EXTERNED */
#[[#endif]]# /* #[[#ifdef]]# __cplusplus */

/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/

/* Anti-C++. */
#[[#ifdef]]# __cplusplus
#[[#ifdef]]# HANDOS_CXX_${INCLUDE_GUARD}
}
#[[#undef]]# HANDOS_CXX_${INCLUDE_GUARD}
#[[#undef]]# HANDOS_CXX_IS_EXTERNED
#[[#endif]]# /* #[[#ifdef]]# HANDOS_CXX_${INCLUDE_GUARD} */
#[[#endif]]# /* #[[#ifdef]]# __cplusplus */

#[[#endif]]# /* ${INCLUDE_GUARD} */