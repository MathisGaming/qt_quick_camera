#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtWidgets>
#include <QCameraInfo>

Q_DECLARE_METATYPE(QCameraInfo)

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    set_camera(QCameraInfo::defaultCamera());
}

MainWindow::~MainWindow()
{
    if (ui)
    {
        delete ui;
    }
    
    if (camera)
    {
        delete camera;
    }
}


void MainWindow::set_camera(const QCameraInfo &cameraInfo)
{
    if (camera)
    {
        delete camera;
    }

    camera = new QCamera(cameraInfo);

    camera->setViewfinder(ui->CameraView);
    camera->start();
}
