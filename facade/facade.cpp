#include "facade.h"

Facade::Facade() {
    _drawManager = ManagerSolution<DrawManagerCreator>().create();
    _loadManager = ManagerSolution<LoadManagerCreator>().create();
    _sceneManager = ManagerSolution<SceneManagerCreator>().create();
    _transformManager = ManagerSolution<TransformManagerCreator>().create();
    _modelLoadModerator = ModeratorSolution<ModelLoadModeratorCreator>().create();
    _sceneLoadModerator = ModeratorSolution<SceneLoadModeratorCreator>().create();;

    _loadManager->setModerator(_modelLoadModerator);
    _loadManager->setSceneModerator(_sceneLoadModerator);
}

void Facade::execute(BaseCommand &command) {
    command.setManagers(_drawManager, _loadManager, _sceneManager, _transformManager,
                        _modelLoadModerator, _sceneLoadModerator);

    auto camera = _sceneManager->getCamera();
    _drawManager->setCamera(camera);

    auto scene = _sceneManager->getScene();
    command.setScene(scene);

    command.execute();
}
