#include "PythonBindings.h"
using namespace boost::python;

/**
 * Unused constructor.
 */
PythonBindings::PythonBindings(){

}

BOOST_PYTHON_MODULE(libBlockWorld){

	class_<GameAssetManager>("GameAssetManager")
			.def("DeleteAsset", &GameAssetManager::DeleteAsset)
	;

}
