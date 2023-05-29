#ifndef CARCASSMODEL_H
#define CARCASSMODEL_H

#include <memory>
#include <utility>

#include "object.h"
#include "basemodel.h"
#include "vertex.h"
#include "link.h"
#include "modelstructure.h"

class CarcassModel : public BaseModel {
    friend class TransformVisitor;
public:
    CarcassModel() : _modelStructure(new ModelStructure) { }
    explicit CarcassModel(const std::shared_ptr<ModelStructure> &modelStructure) :
        _modelStructure(modelStructure) { }
    CarcassModel(const CarcassModel &model);

    ~CarcassModel() override = default;

    virtual Vertex getCenter() const override;
    virtual void accept(shared_ptr<ObjectVisitor> &) override;
    std::shared_ptr<ModelStructure> getModel() {return _modelStructure;}

protected:
    std::shared_ptr<ModelStructure> _modelStructure;
};


#endif // CARCASSMODEL_H
