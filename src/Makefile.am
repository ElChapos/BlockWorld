EXTRA_DIST = ColourManager.h GameWorld.h GameAssetManager.h GameAsset.h CubeAsset.h DiamondAsset.h PyBind.h BoundingBox.h

bin_PROGRAMS = shaderexample
shaderexample_SOURCES = main.cc
shaderexample_LDADD = libengine.la

lib_LTLIBRARIES = libengine.la
libengine_la_SOURCES = ColourManager.cc GameWorld.cc GameAssetManager.cc CubeAsset.cc DiamondAsset.cc PyBind.cc BoundingBox.cc
libengine_la_LDFLAGS = -version-info 0:1

AM_CPPFLAGS = -DGL_GLEXT_PROTOTYPES -DGL3_PROTOTYPES
AM_CPPFLAGS += -std=c++11
AM_CPPFLAGS += $(gl_CFLAGS) $(glew_CFLAGS) $(sdl2_CFLAGS) $(BOOST_CPPFLAGS)
LIBS += $(gl_LIBS) $(glew_LIBS) $(sdl2_LIBS) $(BOOST_THREAD_LIBS) $(BOOST_PROGRAM_OPTIONS_LIBS) $(BOOST_PYTHON_LIBS)