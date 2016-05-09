#include "PythonBindings.h"

PythonBindings::PythonBindings(){}

BOOST_PYTHON_MODULE(libblockengine)
{
	boost::python::class_<GameAssetManager>("GameAssetManager")
                            .def("DeleteAsset", &GameAssetManager::DeleteAsset)
                            .def("AddAsset", &GameAssetManager::AddAsset)
                            .def("UpdateCameraPosition", &GameAssetManager::UpdateCameraPosition)
    ;

    boost::python::class_<GameWorld>("GameWorld")
                            .def("BlockType", &GameWorld::BlockType)
    ;
}
