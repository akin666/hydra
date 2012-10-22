/* config.h.in.  Generated from configure.ac by autoheader.  */

/* Define if building universal (internal helper macro) */
#undef AC_APPLE_UNIVERSAL_BUILD

/* Define to 1 if the compiler supports __builtin_ctz and friends. */
#undef HAVE_BUILTIN_CTZ

/* Define to 1 if the compiler supports __builtin_expect. */
#undef HAVE_BUILTIN_EXPECT

/* Define to 1 if you have the <dlfcn.h> header file. */
#undef HAVE_DLFCN_H

/* Use the gflags package for command-line parsing. */
#undef HAVE_GFLAGS

/* Defined when Google Test is available. */
#undef HAVE_GTEST

/* Define to 1 if you have the <inttypes.h> header file. */
#undef HAVE_INTTYPES_H

/* Define to 1 if you have the `fastlz' library (-lfastlz). */
#undef HAVE_LIBFASTLZ

/* Define to 1 if you have the `lzf' library (-llzf). */
#undef HAVE_LIBLZF

/* Define to 1 if you have the `lzo2' library (-llzo2). */
#undef HAVE_LIBLZO2

/* Define to 1 if you have the `quicklz' library (-lquicklz). */
#undef HAVE_LIBQUICKLZ

/* Define to 1 if you have the `z' library (-lz). */
#undef HAVE_LIBZ

/* Define to 1 if you have the <memory.h> header file. */
#undef HAVE_MEMORY_H
#define HAVE_MEMORY_H 1

/* Define to 1 if you have the <stddef.h> header file. */
#undef HAVE_STDDEF_H
#define HAVE_STDDEF_H 1

/* Define to 1 if you have the <stdint.h> header file. */
#undef HAVE_STDINT_H
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#undef HAVE_STDLIB_H
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#undef HAVE_STRINGS_H
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#undef HAVE_STRING_H
#define HAVE_STRING_H 1

/* Define to 1 if you have the <sys/mman.h> header file. */
#undef HAVE_SYS_MMAN_H

/* Define to 1 if you have the <sys/stat.h> header file. */
#undef HAVE_SYS_STAT_H

/* Define to 1 if you have the <sys/types.h> header file. */
#undef HAVE_SYS_TYPES_H

/* Define to 1 if you have the <unistd.h> header file. */
#undef HAVE_UNISTD_H

/* Define to the sub-directory in which libtool stores uninstalled libraries.
   */
#undef LT_OBJDIR

/* Name of package */
#undef PACKAGE

/* Define to the address where bug reports for this package should be sent. */
#undef PACKAGE_BUGREPORT

/* Define to the full name of this package. */
#undef PACKAGE_NAME

/* Define to the full name and version of this package. */
#undef PACKAGE_STRING

/* Define to the one symbol short name of this package. */
#undef PACKAGE_TARNAME

/* Define to the home page for this package. */
#undef PACKAGE_URL

/* Define to the version of this package. */
#undef PACKAGE_VERSION

/* Define to 1 if you have the ANSI C header files. */
#undef STDC_HEADERS

/* Version number of package */
#undef VERSION

/* Define WORDS_BIGENDIAN to 1 if your processor stores words with the most
   significant byte first (like Motorola and SPARC, unlike Intel). */
#if defined AC_APPLE_UNIVERSAL_BUILD
# if defined __BIG_ENDIAN__
#  define WORDS_BIGENDIAN 1
# endif
#else
# ifndef WORDS_BIGENDIAN
#  undef WORDS_BIGENDIAN
# endif
#endif
