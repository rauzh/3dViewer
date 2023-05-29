#include "filecamerabuilddirector.h"
#include "exceptions.h"

FileCameraBuildDirector::FileCameraBuildDirector() {
    _builder = std::make_shared<CameraBuilder>();
    _loader = std::make_shared<FileCarcassModelLoader>();
}

FileCameraBuildDirector::FileCameraBuildDirector(std::shared_ptr<FileCarcassModelLoader> &loader) {
    _builder = std::make_shared<CameraBuilder>();
    _loader = loader;
}

std::shared_ptr<Camera> FileCameraBuildDirector::create(std::string &fileName) {
    _loader->open(fileName);

    _builder->build();
    Vertex location = _loader->loadVertex();
    _builder->buildLocation(location);

    _loader->close();

    return _builder->get();
}
