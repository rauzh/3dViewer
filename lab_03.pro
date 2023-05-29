# Created by and for Qt Creator This file was created for editing the project sources only.
# You may attempt to use it for building too, by modifying this file here.

#TARGET = lab_03

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS = \
    transformer/transformer.h \
    visitor/objectvisitor.h \
    visitor/transformvisitor.h \
    visitor/drawvisitor.h \
    commands/basecommand.h \
    commands/cameracommand.h \
    commands/modelcommand.h \
    commands/modelscommand.h \
    commands/drawcommand.h \
    commands/loadcommand.h \
    drawer/abstractfactory.h \
    drawer/basedrawer.h \
    drawer/drawersolution.h \
    drawer/drawersolution.hpp \
    drawer/qtdrawer.h \
    drawer/qtfactory.h \
    exceptions/exceptions.h \
    facade/facade.h \
    managers/creators/drawmanagercreator.h \
    managers/creators/loadmanagercreator.h \
    managers/creators/managersolution.h \
    managers/creators/scenemanagercreator.h \
    managers/creators/transformmanagercreator.h \
    managers/draw/drawmanager.h \
    managers/load/loadmanager.h \
    managers/scene/scenemanager.h \
    managers/transform/transformmanager.h \
    managers/basemanager.h \
    matrix/errors/errors.hpp \
    matrix/iterator/const_matrix_iterator.h \
    matrix/iterator/const_matrix_iterator.hpp \
    matrix/iterator/matrix_iterator.h \
    matrix/iterator/matrix_iterator.hpp \
    matrix/matrix/matrix.h \
    matrix/matrix/matrix.hpp \
    matrix/matrix/matrix_base.hpp \
    objects/invisibleobject/camera.h \
    objects/invisibleobject/invisibleobject.h \
    objects/visibleobject/carcassmodel/carcassmodel.h \
    objects/visibleobject/carcassmodel/imp/link.h \
    objects/visibleobject/carcassmodel/imp/modelstructure.h \
    objects/visibleobject/carcassmodel/imp/vertex.h \
    objects/visibleobject/basemodel.h \
    objects/visibleobject/visibleobject.h \
    objects/composite.h \
    objects/object.h \
    builder/builders/camera/basecamerabuilder.h \
    builder/builders/camera/camerabuilder.h \
    builder/builders/model/basemodelbuilder.h \
    builder/builders/model/modelbuilder.h \
    builder/builders/scene/basescenebuilder.h \
    builder/builders/scene/scenebuilder.h \
    builder/builders/basebuilder.h \
    builder/directors/camera/basecamerabuilddirector.h \
    builder/directors/camera/filecamerabuilddirector.h \
    builder/directors/model/basemodelbuilddirector.h \
    builder/directors/model/filemodelbuilddirector.h \
    loader/basecarcassmodelloader.h \
    loader/filecarcassmodelloader.h \
    builder/directors/scene/basescenebuilddirector.h \
    builder/directors/scene/filescenebuilddirector.h \
    builder/directors/basedirector.h \
    builder/moderators/camera/cameraloadmoderator.h \
    builder/moderators/creators/cameraloadmoderatorcreator.h \
    builder/moderators/creators/modelloadmoderatorcreator.h \
    builder/moderators/creators/moderatorsolution.h \
    builder/moderators/creators/sceneloadmoderatorcreator.h \
    builder/moderators/model/modelloadmoderator.h \
    builder/moderators/scene/sceneloadmoderator.h \
    builder/moderators/baseloadmoderator.h \
    scene/scene.h \
    mainwindow.h 

SOURCES = \
    transformer/transformer.cpp \
    visitor/objectvisitor.cpp \
   visitor/transformvisitor.cpp \
   visitor/drawvisitor.cpp \
   commands/basecommand.cpp \
   commands/cameracommand.cpp \
   commands/modelcommand.cpp \
   commands/modelscommand.cpp \
   commands/drawcommand.cpp \
    commands/loadcommand.cpp \
   drawer/qtdrawer.cpp \
   drawer/qtfactory.cpp \
   facade/facade.cpp \
   managers/creators/drawmanagercreator.cpp \
   managers/creators/loadmanagercreator.cpp \
   managers/creators/scenemanagercreator.cpp \
   managers/creators/transformmanagercreator.cpp \
   managers/draw/drawmanager.cpp \
   managers/load/loadmanager.cpp \
   managers/scene/scenemanager.cpp \
   managers/transform/transformmanager.cpp \
   matrix/errors/errors.cpp \
   matrix/matrix/matrix_base.cpp \
   objects/invisibleobject/camera.cpp \
   objects/visibleobject/carcassmodel/carcassmodel.cpp \
   objects/visibleobject/carcassmodel/imp/link.cpp \
   objects/visibleobject/carcassmodel/imp/modelstructure.cpp \
   objects/visibleobject/carcassmodel/imp/vertex.cpp \
   objects/visibleobject/basemodel.cpp \
   objects/composite.cpp \
   objects/object.cpp \
   builder/builders/camera/camerabuilder.cpp \
   builder/builders/model/modelbuilder.cpp \
   builder/builders/scene/scenebuilder.cpp \
   builder/directors/camera/filecamerabuilddirector.cpp \
   builder/directors/model/filemodelbuilddirector.cpp \
   loader/basecarcassmodelloader.cpp \
   loader/filecarcassmodelloader.cpp \
   builder/directors/scene/filescenebuilddirector.cpp \
   builder/moderators/camera/cameraloadmoderator.cpp \
   builder/moderators/creators/cameraloadmoderatorcreator.cpp \
   builder/moderators/creators/modelloadmoderatorcreator.cpp \
   builder/moderators/creators/sceneloadmoderatorcreator.cpp \
   builder/moderators/model/modelloadmoderator.cpp \
   builder/moderators/scene/sceneloadmoderator.cpp \
   builder/moderators/baseloadmoderator.cpp \
   scene/scene.cpp \
   main.cpp \
   mainwindow.cpp 

FORMS += \
    mainwindow.ui

INCLUDEPATH = \
    transformer \ 
    visitor \
    . \
    commands \
    drawer \
    exceptions \
    facade \
    managers \
    managers/creators \
    managers/draw \
    managers/load \
    managers/scene \
    managers/transform \
    matrix \
    matrix/errors \
    matrix/iterator \
    matrix/matrix \
    objects \
    objects/invisibleobject \
    objects/visibleobject \
    objects/visibleobject/carcassmodel \
    objects/visibleobject/carcassmodel/imp \
    builder/builders \
    builder/builders/camera \
    builder/builders/model \
    builder/builders/scene \
    builder/directors \
    builder/directors/camera \
    builder/directors/model \
    builder/directors/scene \
    loader \
    builder/moderators \
    builder/moderators/camera \
    builder/moderators/creators \
    builder/moderators/model \
    builder/moderators/scene \
    scene 

#DEFINES =

DISTFILES += \
    data/cone.txt \
    data/cube.txt \
    data/tesseract.txt

