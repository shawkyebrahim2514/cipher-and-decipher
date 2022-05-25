#ifndef INPUTWINDOW_H
#define INPUTWINDOW_H

#include <QDialog>

namespace Ui {
class inputWindow;
}

class inputWindow : public QDialog
{
    Q_OBJECT

public:
    std::string text;
    explicit inputWindow(QString QinputName,QWidget *parent = nullptr);
    ~inputWindow();

private slots:
    void on_doneBtn_clicked();

private:
    Ui::inputWindow *ui;
};

#endif // INPUTWINDOW_H
