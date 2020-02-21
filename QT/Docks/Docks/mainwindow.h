#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
//class Transform;
class Mesh;
}

class Inspector;
class Hierarchy;
class SceneView;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *uiMainWindow;
    Inspector *inspector;
    Hierarchy *hierarchy;
    SceneView* sceneView;

public slots:
    void SaveFile();
    void LoadFile();
};

#endif // MAINWINDOW_H
