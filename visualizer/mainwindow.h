#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "a2_dynamic_stack.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    friend class DynamicStack;
    friend class GLWidget;
    Q_OBJECT
    QString input;

private:
    Ui::MainWindow *ui;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_stackBtn_clicked();
    void on_insertBtn_released();
    void on_removeBtn_released();
};

#endif // MAINWINDOW_H
