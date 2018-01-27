#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "glwidget.h"
#include <string>
#include "a2_dynamic_stack.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_stackBtn_clicked()
{
    //display stack
}

void MainWindow::on_insertBtn_released()
{
    //reads input from the user and checks for errors
    input = ui->inputField->text();
    input = (input == "" ? "0":input);
    if (input.at(0) != '-' && (input.at(0) < '0' || input.at(0) > '9'))
        input = "-1";
    for (int i = 1; i < input.length(); i++){
        if(input.at(i) < '0' || input.at(i) > '9')
            input = "-1";
    }

    ui->GLwidget->addItem(input);
}

void MainWindow::on_removeBtn_released()
{
    ui->GLwidget->removeItem();
}
