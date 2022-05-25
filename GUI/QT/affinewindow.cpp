#include "affinewindow.h"
#include "ui_affinewindow.h"

affineWindow::affineWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::affineWindow)
{
    ui->setupUi(this);
}

affineWindow::~affineWindow()
{
    delete ui;
}

void affineWindow::on_doneBtn_clicked()
{
    tmp_a = stoi(ui->aNumber->toPlainText().toStdString());
    tmp_b = stoi(ui->bNumber->toPlainText().toStdString());
    tmp_c = stoi(ui->cNumber->toPlainText().toStdString());
    hide();
}

