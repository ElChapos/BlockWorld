#include "PythonBindings.h"

PythonBindings::PythonBindings(){}

BOOST_PYTHON_MODULE(libBlockWorld)
{
	boost::python::class_<GameAssetManager>("GameAssetManager").def("DeleteAsset", &GameAssetManager::DeleteAsset);
}
