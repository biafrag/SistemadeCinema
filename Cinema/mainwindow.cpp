#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cinema = new Cinema();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_CompraIngressosButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    QStringList lista = cinema->getnomesFilmesEmExibicao();
    ui->listWidget->addItems(lista);
}

void MainWindow::on_CadastroFilmesButton_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_VoltarMenuButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_cadastrarFilmeButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

    //Cadastro de filme
    std::string nome = ui->nomeFilme->text().toStdString();

    cinema->registraFilme(nome);
}
