#include "carcassmodel.h"
#include "objectvisitor.h"

CarcassModel::CarcassModel(const CarcassModel &model) {
    _modelStructure = model._modelStructure;
    _id = model._id;
}

Vertex CarcassModel::getCenter() const {
    return _modelStructure->getCenter();
}

void CarcassModel::accept(shared_ptr<ObjectVisitor> &vis) {
    vis->visit(*this);
}
