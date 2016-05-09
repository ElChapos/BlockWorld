#include "PythonBindings.h"

/**
 * Class constructor
 */
PythonBindings::PythonBindings(){}

/**
 * Test function to print out "hello, world" in Python
 */
char const* greet()
{
   return "hello, world";
}

/**
 * Main PythonBindings setup method, defines what methods Python can access from the shared library
 */
BOOST_PYTHON_MODULE(libblockengine)
{
    /**
     * Local methods within this class
     */ 
    boost::python::def("greet", greet);
    
    /**
     * External functions from other classes
     */
    boost::python::class_<App>("App").def("Run", &App::Run);
}
