#ifndef SCENEVIEW_H
#define SCENEVIEW_H

#include <QWidget>

class SceneView : public QWidget
{
    Q_OBJECT
public:
    explicit SceneView(QWidget *parent = nullptr);

private:
    void paintEvent(QPaintEvent* event) override;

signals:

public slots:
};

#endif // SCENEVIEW_H
