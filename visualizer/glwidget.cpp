#include "glwidget.h"
#include "mainwindow.h"
#include "a2_dynamic_stack.hpp"
#include <QPainter>
#include <QtDebug>

GLWidget::GLWidget(QWidget *parent) : QGLWidget(parent), height(625), width(625), x(10), y(570), numElements(1), add(0), remove(0)
{
    data = new QString[64];     //used as labels
    rect = new QRect[64];      //max 64 elements supported by the visualizer
}

void GLWidget::paintEvent(QPaintEvent *){
    QPainter painter(this);

    //Set color for background and text
    QBrush brush(Qt::yellow, Qt::SolidPattern);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::black);

    //draw the base rectangle
    QRect base = QRect(0, 600, 626, 26);
    painter.fillRect(base, brush);
    painter.drawRect(base);

    //draw the header background
    QRect header = QRect(0, 0, 626, 70);
    painter.fillRect(header, brush);
    painter.drawRect(header);

    //show size of stack in header
    QString size = "Size: " + QString::number(stack.size());
    size = (stack.size() >= 64 ? "Size: MAX" : size);
    painter.drawText(header, Qt::AlignCenter, size);

    //when insert button is pressed
    if(add){
        int numIter = stack.size();
        int i = 0;
        //int recCounter = 0;

        brush.setColor(Qt::green);
        if(stack.size()>0)
            data[stack.size()-1] = QString::number(stack.peek());

        do {
            int temp = (numIter < 16 ? numIter:16);
            for (int row = 0; row < temp; row++){
                //creates rectangles containing values stored in stack
                rect[stack.size()-1] = QRect(x + (i*150), y-(row*30), 125, 30);
                painter.fillRect(rect[stack.size()-1], brush);
                painter.drawRect(rect[stack.size()-1]);
                painter.drawText(rect[stack.size()-1], Qt::AlignCenter, data[stack.size()-1]);
            }
            numIter -= 16;
            i++;
        } while (numIter > 0);      //runs while the stack lasts
    } else if (remove){
        painter.eraseRect(rect[stack.size()]);      //erases the top most rectangle when remove is true
    }
}

//when insert button is pressed
void GLWidget::addItem(QString input){
    if (stack.size()<=64){
        stack.push(input.toInt());  // adds value to stack
        add = true;
        update();       //updates visualizer
    }
}

void GLWidget::removeItem(){
    stack.pop();        //removes from stack
    remove = true;
    update();       //updates visualizer
}


