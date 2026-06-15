/* Useful if you wish to make target-specific GCC changes. */
#undef TARGET_NANVIX
#define TARGET_NANVIX 1

/* The Nanvix C runtime is the in-tree, Rust-implemented library staged into the
   sysroot (crt0.o + libc.a + libm.a + headers), NOT newlib.  libc.a embeds the
   POSIX syscall backend and the allocator; libm.a is the standalone math
   archive.  A --start-group resolves the crt0 <-> libc <-> libm back-references.
   No -lposix, -lpthread, -lnosys, -lgloss, or -lgcc is needed (the legacy stub
   archives in the sysroot satisfy any residual -ldl/-lpthread/-lrt).  */
#undef LIB_SPEC
#define LIB_SPEC "%{!shared: --start-group -lc -lm --end-group}"

/* Startup is `_do_start` in crt0.o (NOT newlib's `_start`); the runtime is
   brought up by `__nanvix_libc_start_main` in libc.a, which walks `.init_array`.
   crt0.o is the single relocatable startfile; %s makes GCC search the sysroot
   library directory for it.  No crti.o/crtbegin.o: with `.init_array` framing
   there is no GCC-style `_init` prologue.  */
#undef STARTFILE_SPEC
#define STARTFILE_SPEC "%{!shared: crt0.o%s}"

/* No crtn.o/crtend.o: with `.init_array` framing there is no `_fini` epilogue. */
#undef ENDFILE_SPEC
#define ENDFILE_SPEC ""

/* Nanvix's loader needs page-aligned LOAD segments and cannot handle GNU_RELRO.
   Entry comes from the port's `user.ld` via -T.  */
#undef LINK_SPEC
#define LINK_SPEC "%{shared:-shared} %{static:-static} \
  %{!shared: %{!static: %{rdynamic:-export-dynamic}}} \
  -z norelro --build-id=none"

/* Additional predefined macros. */
#undef TARGET_OS_CPP_BUILTINS
#define TARGET_OS_CPP_BUILTINS()      \
  do {                                \
    builtin_define ("__nanvix__");      \
    builtin_define ("__unix__");      \
    builtin_assert ("system=nanvix");   \
    builtin_assert ("system=unix");   \
    builtin_assert ("system=posix");   \
  } while(0);
