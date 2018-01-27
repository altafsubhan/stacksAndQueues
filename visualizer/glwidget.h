#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QMainWindow>
#include <QLineEdit>
#include "a2_dynamic_stack.hpp"

class GLWidget : public QGLWidget
{
    friend class DynamicStack;
    friend class MainWindow;

    Q_OBJECT
    DynamicStack stack;
    unsigned int height, width, x, y, numElements;
    QString* data;
    QRect* rect;
    QPainter painter;
    bool add, remove;

public:
    explicit GLWidget(QWidget *parent = 0);

    void paintEvent(QPaintEvent *);
    void setX(int newX);
    void setY(int newY);
    void addItem(QString input);
    void drawElement(QPainter & painter, QRect* rect, QBrush brush);
    void removeItem();

signals:

public slots:
};

#endif // GLWIDGET_H
