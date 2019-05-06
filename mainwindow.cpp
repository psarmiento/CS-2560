#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    // Clear the screen
    currentFile.clear();
    // Create a new text window
    ui->textEdit->setText(QString());
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(fileName);
    currentFile = fileName;
    if(!file.open(QIODevice::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "Warning", "Can NOT open file: " + file.errorString());
    }

    setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = in.readAll();      // String buffer reading all the text in file user wants to open
    ui->textEdit->setText(text);      // Display contents of file in the text field
    file.close();
}

void MainWindow::on_actionSave_triggered()
{
    // Open window to save the file
    QString fileName = QFileDialog::getSaveFileName(this, "Save the file");
    // Create the object to hold the file
    QFile file(fileName);

    // If something goes wrong with I/O notify user of problem
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "Warning", "Can NOT save file: " + file.errorString());
    }

   // Store current file
   currentFile = fileName;
   // Set window title to name of the file
   setWindowTitle(fileName);

   // When writing to out we are actually writing to file on line 65
   QTextStream out(&file);

   // Copy text in textEdit widget convert to plain text
   QString text = ui->textEdit->toPlainText();

   // Write to File then close file
   out << text;
   file.close();

}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}
