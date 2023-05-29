#include "filescenebuilddirector.h"
#include "filecamerabuilddirector.h"
#include "filemodelbuilddirector.h"
#include "exceptions.h"

FileSceneBuildDirector::FileSceneBuildDirector() {
    _builder = std::make_shared<SceneBuilder>();
    _loader = std::make_shared<FileCarcassModelLoader>();
}

FileSceneBuildDirector::FileSceneBuildDirector(std::shared_ptr<FileCarcassModelLoader> &loader) {
    _builder = std::make_shared<SceneBuilder>();
    _loader = loader;
}

std::shared_ptr<Scene> FileSceneBuildDirector::create(std::string &fileName) {
    _loader->open(fileName);

    _builder->build();

    createModels(_builder, fileName);
    createCameras(_builder, fileName);

    _loader->close();

    return _builder->get();
}

void FileSceneBuildDirector::createModels(std::shared_ptr<SceneBuilder> builder, std::string &fileName) {

    size_t modelsCount = _loader->loadCount();

    for (size_t i = 0; i < modelsCount; i++) {
        auto model = FileModelBuildDirector(_loader).create(fileName);
        builder->buildObject(model);
    }
}

void FileSceneBuildDirector::createCameras(std::shared_ptr<SceneBuilder> builder, std::string &fileName) {

    size_t camsCount = _loader->loadCount();

    for (size_t i = 0; i < camsCount; i++) {
        auto camera = FileCameraBuildDirector(_loader).create(fileName);
        builder->buildObject(camera);
    }
}
