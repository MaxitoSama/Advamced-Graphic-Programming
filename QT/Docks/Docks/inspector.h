#ifndef INSPECTOR_H
#define INSPECTOR_H

#include <QWidget>

namespace Ui {
class Transform;
class Mesh;
}


class Inspector : public QWidget
{
    Q_OBJECT

public:
    explicit Inspector(QWidget *parent = nullptr);
    ~Inspector();

private:
    Ui::Transform *uiTransform;
    Ui::Mesh *uiMesh;

    QWidget* transformWidget;
    QWidget* meshWidget;

public slots:
    void onEntitySelected(int entityId);

};

#endif // INSPECTOR_H
