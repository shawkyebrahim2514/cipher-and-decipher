#include "inputwindow.h"
#include "ui_inputwindow.h"

inputWindow::inputWindow(QString QinputName,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inputWindow)
{
    ui->setupUi(this);
    ui->inputName->setText(QinputName);
}

inputWindow::~inputWindow()
{
    delete ui;
}

void inputWindow::on_doneBtn_clicked()
{
    text = ui->inputInfo->toPlainText().toStdString();
    text.erase(remove(text.begin(),text.end(),' '), text.end());
    hide();
}

