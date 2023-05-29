#ifndef COMPOSITE_H
#define COMPOSITE_H

#include "object.h"

class Composite : public Object {
public:
    Composite() = default;
    explicit Composite(std::shared_ptr<Object> &element);
    explicit Composite(const std::vector<std::shared_ptr<Object>> &vector);

    virtual bool add(const std::shared_ptr<Object> &element) override;
    virtual bool remove(const Iterator &iter) override;
    virtual void updateCenter() override;
    virtual Vertex getCenter() const override;

    virtual bool isVisible() override;
    virtual bool isComposite() override;

    virtual void accept(shared_ptr<ObjectVisitor> &) override;
    
    virtual Iterator begin() override;
    virtual Iterator end() override;

private:
    Vertex _center;
    std::vector<std::shared_ptr<Object>> _objects;
};

#endif //COMPOSITE_H
