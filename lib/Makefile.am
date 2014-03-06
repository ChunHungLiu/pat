SOURCE = pat.cpp \
	Support/Timer.h \
	Support/Timer.cpp

ANDROID_CPPFLAGS=-fno-rtti -fno-exceptions -Waddress -Wchar-subscripts -Wcomment -Wformat -Wparentheses -Wreorder -Wreturn-type -Wsequence-point -Wstrict-aliasing -Wstrict-overflow=1 -Wswitch -Wtrigraphs -Wuninitialized -Wunknown-pragmas -Wunused-function -Wunused-label -Wunused-value -Wunused-variable -Wvolatile-register-var

SKYMIZER_INCLUDES = -I${abs_top_srcdir}/include \
                    -I${abs_top_builddir}/include

if ENABLE_OPTIMIZE
SKYMIZER_CPPFLAGS = -O2
else
SKYMIZER_CPPFLAGS = -g
endif

SKYMIZER_CPPFLAGS += -fvisibility=hidden

AM_CPPFLAGS = ${SKYMIZER_INCLUDES} ${SKYMIZER_CPPFLAGS} ${ANDROID_CPPFLAGS}

#############################
# Build shared library
lib_LTLIBRARIES = libpat.la

libpat_la_SOURCES = ${SOURCE}

libpat_la_LDFLAGS = -version-info @PAT_VERSION@

pkgconfigdir = $(libdir)/pkgconfig

pkgconfig_DATA = pat.pc

# Remove temporary *.la files
install-exec-hook:
	rm -f $(libdir)/libpat.la