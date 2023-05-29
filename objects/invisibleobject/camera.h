#ifndef CAMERA_H
#define CAMERA_H

#include "invisibleobject.h"

class Camera : public InvisibleObject {
public:
    Camera() = default;
    Camera(const Vertex &location) : _location(location) { }
    ~Camera() override = default;

    virtual Vertex getCenter() const override;
    virtual void accept(shared_ptr<ObjectVisitor> &) override;

    Vertex getLocation() {return _location;}
    void setLocation(Vertex v) {_location = v;}

private:
    Vertex _location;
};


#endif //CAMERA_H
