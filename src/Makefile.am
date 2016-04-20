EXTRA_DIST = BlockColours.h GameWorld.h GameAssetManager.h GameAsset.h CubeAsset.h

bin_PROGRAMS = BlockWorld
BlockWorld_SOURCES = main.cc
BlockWorld_LDADD = libblockengine.la

libblockengine_la_SOURCES = BlockColours.cc GameWorld.cc GameAssetManager.cc CubeAsset.cc

AM_CPPFLAGS = -DGL_GLEXT_PROTOTYPES -DGL3_PROTOTYPES
AM_CPPFLAGS += -std=c++11
AM_CPPFLAGS += $(gl_CFLAGS) $(glew_CFLAGS) $(sdl2_CFLAGS) $(BOOST_CPPFLAGS)
LIBS += $(gl_LIBS) $(glew_LIBS) $(sdl2_LIBS) $(BOOST_THREAD_LIBS) $(BOOST_PROGRAM_OPTIONS_LIBS)
