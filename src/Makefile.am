EXTRA_DIST = GameWorld.h GameAssetManager.h GameAsset.h Camera.h BoundingBox.h ColourManager.h PythonBindings.h DiamondAsset.h CubeAsset.h StarAsset.h

bin_PROGRAMS = BlockWorld
BlockWorld_SOURCES = main.cc
BlockWorld_LDADD = libblockengine.la

lib_LTLIBRARIES = libblockengine.la
libblockengine_la_SOURCES = GameWorld.cc GameAssetManager.cc Camera.cc BoundingBox.cc GameAsset.cc ColourManager.cc PythonBindings.cc DiamondAsset.cc CubeAsset.cc StarAsset.cc

AM_CPPFLAGS = -DGL_GLEXT_PROTOTYPES -DGL3_PROTOTYPES
AM_CPPFLAGS += -std=c++11 -I/usr/include/python2.7
AM_CPPFLAGS += $(gl_CFLAGS) $(glew_CFLAGS) $(sdl2_CFLAGS) $(BOOST_CPPFLAGS)

LDFLAGS = -framework OpenGL -framework GLUT -lSDL2 -lboost_system -lboost_python -lpython2.7 -Wl,-rpath,'$$ORIGIN/.libs'
LIBS += $(gl_LIBS) $(glew_LIBS) $(sdl2_LIBS) $(BOOST_THREAD_LIBS) $(BOOST_PROGRAM_OPTIONS_LIBS)
