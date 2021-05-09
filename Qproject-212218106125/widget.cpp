#include "widget.h"
#include "QTextEdit"
#include "QColorDialog"
#include "QLabel"
#include "QDebug"
#include "QPushButton"
#include "QFont"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //Heading
    QFont labelFont("Times",18,QFont::Bold);
        QLabel *mLabel=new QLabel("My text",this);
        mLabel->setFont(labelFont);
        mLabel->move(100,25);
        QPalette label;
        label.setColor(QPalette::Window,Qt::gray);
        label.setColor(QPalette::WindowText,Qt::blue);
        mLabel->setAutoFillBackground(true);
        mLabel->setPalette(label);


        //Text edit
        QTextEdit *text=new QTextEdit(this);
        text->move(75,80);
        text->setMinimumSize(400,100);
        connect(text,&QTextEdit::textChanged,[=](){
        qDebug()<<"Text Changed"; });


        //CutButton
        QPushButton *cut=new QPushButton("Cut",this);
        cut->setMinimumSize(50,25);
        cut->move(75,300);
        connect(cut,&QPushButton::clicked,[=](){
        text->cut(); });


        //copyButton
        QPushButton *copy=new QPushButton("Copy",this);
        copy->setMinimumSize(50,25);
        copy->move(215,300);
        connect(copy,&QPushButton::clicked,[=](){
        text->copy(); });


        //PasteButton
        QPushButton *paste=new QPushButton("Paste",this);
        paste->setMinimumSize(50,25);
        paste->move(355,300);
        connect(paste,&QPushButton::clicked,[=](){
        text->paste(); });


        //UndoButton
        QPushButton *undo=new QPushButton("Undo",this);
        undo->setMinimumSize(50,25);
        undo->move(75,350);
        connect(undo,&QPushButton::clicked,[=](){
        text->undo(); });


        //RedoButton
        QPushButton *redo=new QPushButton("Redo",this);
        redo->setMinimumSize(50,25);
        redo->move(355,350);
        connect(redo,&QPushButton::clicked,[=](){
        text->redo(); });


        //HTML Button
        QPushButton *html=new QPushButton("HTML",this);
        html->setMinimumSize(100,25);
        html->move(215,350);
        connect(html,&QPushButton::clicked,[=](){
        text->setHtml("<h1>Title</h1><p>Three districts:</br> <ul><li>X</li><li>Y</li><li>Z</li></ul></p>");  });

    }


Widget::~Widget()
{
}

