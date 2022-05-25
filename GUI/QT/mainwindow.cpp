#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "affinewindow.h"
#include "inputwindow.h"
#include "allCiphers.h"

int affine_a, affine_b, affine_c;
std::string keyword_PolybiusSquareCipher, keyword_SimpleSubstitutionCipher, keyword_VignereCipher;
int key_RailFenceCipher, number_of_shifts_CaesarCipher;
char secret_key_XorCipher;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_affine_clicked()
{
    affineWindow screen;
    screen.setModal(true);
    screen.exec();
    ui->cipherName->setText("affine");
    affine_a = screen.tmp_a;
    affine_b = screen.tmp_b;
    affine_c = screen.tmp_c;
    /*std::string text = ui->textInput->toPlainText().toStdString();
    std::transform(text.begin(),text.end(),text.begin(), ::toupper);
    affine_cipher(stoi(screen.tmp_a),stoi(screen.tmp_b),text);
    ui->textOutput->setPlainText(QString::fromStdString(text));*/
}


void MainWindow::on_atbash_clicked()
{
    ui->cipherName->setText("atbash");
}


void MainWindow::on_baconian_clicked()
{
    ui->cipherName->setText("baconian");
}


void MainWindow::on_morceCode_clicked()
{
    ui->cipherName->setText("morceCode");
}


void MainWindow::on_polybiusSquare_clicked()
{
    inputWindow screen("Enter key\n(five number)");
    screen.setModal(true);
    screen.exec();
    keyword_PolybiusSquareCipher = screen.text;
    ui->cipherName->setText("polybiusSquare");
}


void MainWindow::on_RailFence_clicked()
{
    inputWindow screen("number of rails");
    screen.setModal(true);
    screen.exec();
    key_RailFenceCipher = stoi(screen.text);
    ui->cipherName->setText("railfence");
}


void MainWindow::on_simpleSubstitution_clicked()
{
    inputWindow screen("Enter key of 5\nunique letters");
    screen.setModal(true);
    screen.exec();
    keyword_SimpleSubstitutionCipher = screen.text;
    ui->cipherName->setText("simpleSubstitution");
}


void MainWindow::on_vignere_clicked()
{
    inputWindow screen("Enter keyword\n restricted to 8 chars");
    screen.setModal(true);
    screen.exec();
    keyword_VignereCipher = screen.text;
    ui->cipherName->setText("vignere");
}


void MainWindow::on_xorCipher_clicked()
{
    inputWindow screen("xor");
    screen.setModal(true);
    screen.exec();
    secret_key_XorCipher = screen.text[0];
    ui->cipherName->setText("xor");
}


void MainWindow::on_caesar_clicked()
{
    inputWindow screen("Enter secret letter.");
    screen.setModal(true);
    screen.exec();
    number_of_shifts_CaesarCipher = stoi(screen.text);
    ui->cipherName->setText("caesar");
}


void MainWindow::on_cipherBtn_clicked()
{
    std::string cipherName = ui->cipherName->text().toStdString();
    std::string text = ui->textInput->toPlainText().toStdString();
    std::transform(text.begin(),text.end(),text.begin(), ::toupper);
    if(cipherName == "affine"){
        affine_cipher(affine_a,affine_b,text);
    }else if(cipherName == "atbash"){
        atbash(text);
    }else if(cipherName == "baconian"){
        baconianCipher(text);
    }else if(cipherName == "morceCode"){
        morceCodeCipher(text);

    }else if(cipherName == "polybiusSquare"){
        polybiusSquareCipher(text,keyword_PolybiusSquareCipher);

    }else if(cipherName == "railfence"){
        railFenceCipher(text,key_RailFenceCipher);

    }else if(cipherName == "simpleSubstitution"){
        simpleSubstitutionCipher(text,keyword_SimpleSubstitutionCipher);

    }else if(cipherName == "vignere"){
        vignereCipher(text, keyword_VignereCipher);

    }else if(cipherName == "xor"){
        xorCipher(text,secret_key_XorCipher);

    }else{
        caesarCipher(text,number_of_shifts_CaesarCipher);
    }
    ui->textOutput->setPlainText(QString::fromStdString(text));
}


void MainWindow::on_decipherBtn_clicked()
{
    std::string cipherName = ui->cipherName->text().toStdString();
    std::string text = ui->textInput->toPlainText().toStdString();
    std::transform(text.begin(),text.end(),text.begin(), ::toupper);
    if(cipherName == "affine"){
        affine_decipher(affine_b,affine_c,text);
    }else if(cipherName == "atbash"){
        atbash(text);
    }else if(cipherName == "baconian"){
        baconianDecipher(text);
    }else if(cipherName == "morceCode"){
        morceCodeDecipher(text);
    }else if(cipherName == "polybiusSquare"){
        polybiusSquareDecipher(text,keyword_PolybiusSquareCipher);

    }else if(cipherName == "railfence"){
        railFenceDecipher(text,key_RailFenceCipher);

    }else if(cipherName == "simpleSubstitution"){
        simpleSubstitutionDecipher(text,keyword_SimpleSubstitutionCipher);

    }else if(cipherName == "vignere"){
        vignereDecipher(text, keyword_VignereCipher);

    }else if(cipherName == "xor"){
        xorDecipher(text,secret_key_XorCipher);
    }else{
        caesarDecipher(text,number_of_shifts_CaesarCipher);
    }
    ui->textOutput->setPlainText(QString::fromStdString(text));
}


