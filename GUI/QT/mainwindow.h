#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_affine_clicked();

    void on_atbash_clicked();

    void on_baconian_clicked();

    void on_morceCode_clicked();

    void on_polybiusSquare_clicked();

    void on_RailFence_clicked();

    void on_simpleSubstitution_clicked();

    void on_vignere_clicked();

    void on_xorCipher_clicked();

    void on_cipherBtn_clicked();

    void on_decipherBtn_clicked();

    void on_caesar_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
