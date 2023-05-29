#include "composite.h"
#include "transformvisitor.h"

Composite::Composite(std::shared_ptr<Object> &element) {
    _objects.push_back(element);
    updateCenter();
}


Composite::Composite(const std::vector<std::shared_ptr<Object>> &vector) {
    _objects = vector;
    updateCenter();
}


bool Composite::add(const std::shared_ptr<Object> &element) {
    _objects.push_back(element);
    updateCenter();

    return true;
}


bool Composite::remove(const Iterator &iter) {
    _objects.erase(iter);
    updateCenter();

    return true;
}

void Composite::updateCenter() {
    _center = Vertex(0, 0, 0);
    size_t count = 0;

    for (const auto &element : _objects)
    {
        _center = _center + element->getCenter();
        count++;
    }

    _center = Vertex(_center.getX() / count,
                     _center.getY() / count,
                     _center.getZ() / count);
}

bool Composite::isVisible() {
    return false;
}

bool Composite::isComposite() {
    return true;
}

Vertex Composite::getCenter() const {
    return _center;
}

void Composite::accept(shared_ptr<ObjectVisitor> &vis) {
    for (auto &obj : _objects) {
        obj->accept(vis);
    }
}

Iterator Composite::begin() {
    return _objects.begin();
}


Iterator Composite::end() {
    return _objects.end();
}
