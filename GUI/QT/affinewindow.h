#ifndef AFFINEWINDOW_H
#define AFFINEWINDOW_H

#include <QDialog>

namespace Ui {
class affineWindow;
}

class affineWindow : public QDialog
{
    Q_OBJECT

public:
    int tmp_a,tmp_b,tmp_c;
    explicit affineWindow(QWidget *parent = nullptr);
    ~affineWindow();

private slots:
    void on_doneBtn_clicked();

private:
    Ui::affineWindow *ui;
};

#endif // AFFINEWINDOW_H
