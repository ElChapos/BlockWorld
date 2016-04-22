#include <boost/python.hpp>

const char* HelloWorld()
{
	return "Hello world!";
}

BOOST_PYTHON_MODULE(hello_world)
{
	using namespace boost::python;
	def("print", HelloWorld)
}