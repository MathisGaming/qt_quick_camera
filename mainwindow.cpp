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

    //QActionGroup *videoDevicesGroup = new QActionGroup(this);
    //videoDevicesGroup->setExclusive(true);

    set_camera(QCameraInfo::defaultCamera());
}

MainWindow::~MainWindow()
{
    delete ui;
    delete camera;
}


void MainWindow::set_camera(const QCameraInfo &cameraInfo)
{
    delete camera;

    camera = new QCamera(cameraInfo);

    camera->setViewfinder(ui->CameraView);
    camera->start();
}

void MainWindow::start_camera()
{
    camera->start();
}

void MainWindow::stop_camera()
{
    camera->stop();
}
