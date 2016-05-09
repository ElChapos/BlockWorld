#include "PythonBindings.h"

PythonBindings::PythonBindings(){}

char const* greet()
{
   return "hello, world";
}

BOOST_PYTHON_MODULE(libblockengine)
{
    boost::python::def("greet", greet);

    boost::python::class_<App>("App")
    	.def("Run", &App::Run);
}
