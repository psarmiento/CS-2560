#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "BigNumberLib.h"

// num1 will hold the first number being entered
// and also the operation symbol
BigNumber num1, num2;
QString str1, str2;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit;
    // Set num 1 bool variable to false
    num1.numEntered(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 0 Clicked
void MainWindow::on_pushButton_clicked()
{
    // First check to see if num1 has been finished being inputted
    if(!num1.getBool()){
        num1.addDigit(0);
        str1 = QString::fromStdString(num1.print());
        ui->textEdit->setPlainText(str1);
    }

    else {
        num2.addDigit(0);
        str2 = QString::fromStdString(num2.print());
        ui->textEdit->setPlainText(str2);
    }
}

// 1 Clicked
void MainWindow::on_pushButton_2_clicked()
{
    if(!num1.getBool()){
        num1.addDigit(1);
        str1 = QString::fromStdString(num1.print());
        ui->textEdit->setPlainText(str1);
    }

    else{
        num2.addDigit(1);
        str2 = QString::fromStdString(num2.print());
        ui->textEdit->setPlainText(str2);
    }
}

// 2 Clicked
void MainWindow::on_pushButton_3_clicked()
{
    if(!num1.getBool()){
        num1.addDigit(2);
        str1 = QString::fromStdString(num1.print());
        ui->textEdit->setPlainText(str1);
    }

    else {
        num2.addDigit(2);
        str2 = QString::fromStdString(num2.print());
        ui->textEdit->setPlainText(str2);
    }
}

// 3 Clicked
void MainWindow::on_pushButton_4_clicked()
{
    if(!num1.getBool()){
        num1.addDigit(3);
        str1 = QString::fromStdString(num1.print());
        ui->textEdit->setPlainText(str1);
    }

    else {
        num2.addDigit(3);
        str2 = QString::fromStdString(num2.print());
        ui->textEdit->setPlainText(str2);
    }
}

// 4 Clicked
void MainWindow::on_pushButton_5_clicked()
{
    if(!num1.getBool()){
        num1.addDigit(4);
        str1 = QString::fromStdString(num1.print());
        ui->textEdit->setPlainText(str1);
    }

    else {
        num2.addDigit(4);
        str2 = QString::fromStdString(num2.print());
        ui->textEdit->setPlainText(str2);
    }
}

// 5 Clicked
void MainWindow::on_pushButton_8_clicked()
{
    if(!num1.getBool()){
        num1.addDigit(5);
        str1 = QString::fromStdString(num1.print());
        ui->textEdit->setPlainText(str1);
    }

    else {
        num2.addDigit(5);
        str2 = QString::fromStdString(num2.print());
        ui->textEdit->setPlainText(str2);
    }
}

// 6 Clicked
void MainWindow::on_pushButton_9_clicked()
{
    if(!num1.getBool()){
        num1.addDigit(6);
        str1 = QString::fromStdString(num1.print());
        ui->textEdit->setPlainText(str1);
    }

   /* else if(!num1.getBool() && num1.getSymbol() == ' '){
        num1.addDigit(6);
        str1 = QString::fromStdString(num1.print());
        ui->textEdit->setPlainText(str1);
    }
    */

    else {
        num2.addDigit(6);
        str2 = QString::fromStdString(num2.print());
        ui->textEdit->setPlainText(str2);
    }
}

// 7 Clicked
void MainWindow::on_pushButton_6_clicked()
{
    if(!num1.getBool()){
        num1.addDigit(7);
        str1 = QString::fromStdString(num1.print());
        ui->textEdit->setPlainText(str1);
    }

    else {
        num2.addDigit(7);
        str2 = QString::fromStdString(num2.print());
        ui->textEdit->setPlainText(str2);
    }
}

// 8 Clicked
void MainWindow::on_pushButton_10_clicked()
{
    if(!num1.getBool()){
        num1.addDigit(8);
        str1 = QString::fromStdString(num1.print());
        ui->textEdit->setPlainText(str1);
    }

    else {
        num2.addDigit(8);
        str2 = QString::fromStdString(num2.print());
        ui->textEdit->setPlainText(str2);
    }
}


// 9 Clicked
void MainWindow::on_pushButton_7_clicked()
{
    if(!num1.getBool()){
        num1.addDigit(9);
        str1 = QString::fromStdString(num1.print());
        ui->textEdit->setPlainText(str1);
    }

    else {
        num2.addDigit(9);
        str2 = QString::fromStdString(num2.print());
        ui->textEdit->setPlainText(str2);
    }
}

// + Clicked
void MainWindow::on_pushButton_11_clicked()
{
    num1.numEntered(true);
    ui->textEdit->clear();         // Set text edit to blank text
    num1.operatorEntered('+');
}

// = Clicked
void MainWindow::on_pushButton_13_clicked()
{
    ui->textEdit->clear();
    BigNumber result;

    if(num1.getSymbol() == '+'){
        result = num1 + num2;
        str1 = QString::fromStdString(result.print());
        ui->textEdit->setPlainText(str1);
    }

    else if(num1.getSymbol() == '-'){
        result = num1 - num2;
        str1 = QString::fromStdString(result.print());
        ui->textEdit->setPlainText(str1);
    }
}

// Clear button
// This button should clear all data for all objects
// Should be used right after entering '=' when peforming more operations
void MainWindow::on_pushButton_14_clicked()
{
    // Clear data for the objects
    num1.clear();
    num2.clear();
    num1.numEntered(false);
    ui->textEdit->clear();
}

// - Clicked
void MainWindow::on_pushButton_12_clicked()
{
    num1.numEntered(true);
    ui->textEdit->clear();         // Set text edit to blank text
    num1.operatorEntered('-');
}
