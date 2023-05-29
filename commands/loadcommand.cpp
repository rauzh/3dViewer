#include "loadcommand.h"

LoadModel::LoadModel(const ID &id, std::string &fileName) :
    _fileName(fileName), _id(id) { }

void LoadModel::execute() {
    auto model = _loadManager->load(_fileName);
    (*_id) = _scene->addObject(model);
}


LoadScene::LoadScene(const std::string fileName) : _fileName(fileName) { }

void LoadScene::execute() {
    _scene = _loadManager->loadScene(_fileName);
    _sceneManager->setScene(_scene);
}
