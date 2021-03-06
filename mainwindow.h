#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCamera>

namespace Ui {
class MainWindow;
}



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void set_camera(const QCameraInfo &cameraInfo);
private:
    Ui::MainWindow *ui;
    QCamera *camera;
};

#endif // MAINWINDOW_H
