#ifndef HIERARCHY_H
#define HIERARCHY_H

#include <QWidget>

namespace Ui {
class Hierarchy;
}

class Hierarchy : public QWidget
{
    Q_OBJECT

public:
    explicit Hierarchy(QWidget *parent = nullptr);
    ~Hierarchy();


signals:
    void entityChanged(int entityId);

private:
    Ui::Hierarchy *ui;
    int numEntities=0;

public slots:
    void onAddEntity();
    void onRemoveEntity();
    void onEntitySelected(int row);
};

#endif // HIERARCHY_H
