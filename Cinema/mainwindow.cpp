#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

#include "filme.h"
#include "sala.h"
#include "exibicao.h"

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
    ui->listWidget->clear();
    ui->listWidget->addItems(lista);
    ui->comboBox_2->clear();
}

void MainWindow::on_RendimentoButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

    QStringList lista = cinema->getnomesFilmesEmExibicao();
    ui->listWidget_5->clear();
    ui->listWidget_5->addItems(lista);
}

void MainWindow::on_CadastroFilmesButton_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_VoltarMenuButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_voltarMenuButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_voltarMenuButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_voltarMenuButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_cadastroExibicoesButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    QStringList lista = cinema->getnomesFilmesEmExibicao();
    ui->listWidget_3->clear();
    ui->listWidget_3->addItems(lista);

    ui->listWidget_4->clear();
    QDate date = ui->dateTimeEdit->date();
    QTime time = ui->dateTimeEdit->time();
    std::cout<<"Dia: "<< date.day()<< " mes: "<<date.month()<<" ano "<<date.year()<<std::endl;

    std::vector<Sala*> salas = cinema->verificaSalasDisponiveis(date,time);
    for(unsigned int i = 0; i < salas.size(); i++)
    {
        Sala* sala = salas[i];
        ui->listWidget_4->addItem(QString(sala->getName().c_str()));
    }
}

void MainWindow::on_cadastroSalasButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_cadastrarFilmeButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

    //Cadastro de filme
    std::string nome = ui->nomeFilme->text().toStdString();
    int ano = ui->anoFilme->text().toInt();
    int classificacao = ui->classificacaoFilme->text().toInt();
    std::string nacionalidade = ui->nacionalidadeFilme->text().toStdString();
    ui->nomeFilme->setText("");
    ui->anoFilme->setText("");
    ui->classificacaoFilme->setText("");
    ui->nacionalidadeFilme->setText("");
    cinema->registraFilme(nome,ano,classificacao,nacionalidade);
}

void MainWindow::on_listWidget_clicked(const QModelIndex &index)
{
    Filme filme = cinema->findFilme(ui->listWidget->item(index.row())->text().toStdString());
    std::vector<Exibicao> ex = cinema->getExibicoes(filme.getNome());

    ui->listWidget_2->clear();
    for(unsigned int i = 0; i < ex.size(); i++)
    {
        Exibicao exibicao = ex[i];
        ui->listWidget_2->addItem(exibicao.getData().toString("dd.MM.yyyy") + QString("  ") + exibicao.getHorario().toString() + QString("  ") + QString(exibicao.getSalaNome().c_str()) + QString("  Preco: R$") + QString::number(exibicao.getPreco()) + QString("  Audio: ") + QString(exibicao.getAudio().c_str()));
    }
}



void MainWindow::on_cadastroSalaButton_clicked()
{
    std::string nome = ui->nomeSala->text().toStdString();
    int nAssentos = ui->nAssentosSala->text().toInt();

    if(nome == "" || ui->nAssentosSala->text() == "")
    {
        QMessageBox::information(
            this,
            tr("Cadastro de Sala"),
            tr("Informação faltando. Complete tudo.") );
    }
    else
    {
        if(!cinema->verificaSeSalaExiste(nome))
        {
            Sala* sala = new Sala(nome,nAssentos);
            cinema->addSala(sala);
            ui->stackedWidget->setCurrentIndex(0);
            ui->nomeSala->setText("");
            ui->nAssentosSala->setText("");
        }
        else
        {
            QMessageBox::information(
                this,
                tr("Cadastro de Sala"),
                tr("Uma sala com esse ID ja existe.") );
        }
    }





}
void MainWindow::on_dateTimeEdit_dateTimeChanged(const QDateTime &dateTime)
{
    QDate date = dateTime.date();
    QTime time = dateTime.time();
    std::cout<<"Dia: "<< date.day()<< " mes: "<<date.month()<<" ano "<<date.year()<<std::endl;

    ui->listWidget_4->clear();
    std::vector<Sala*> salas = cinema->verificaSalasDisponiveis(date,time);
    for(unsigned int i = 0; i < salas.size(); i++)
    {
        Sala* sala = salas[i];
        ui->listWidget_4->addItem(QString(sala->getName().c_str()));
    }
}

void MainWindow::on_CadastrarExibicaoButton_clicked()
{
    QDate date = ui->dateTimeEdit->date();
    QTime time = ui->dateTimeEdit->time();
    std::string audio = ui->comboBox->currentText().toStdString();
    float preco = ui->precoExibicao->text().toFloat();
    if(!ui->listWidget_3->currentItem() )
    {
        QMessageBox::information(
            this,
            tr("Cadastro de Exibicao"),
            tr("Escolha um filme.") );
    }
    else if (!ui->listWidget_4->currentItem())
    {
        QMessageBox::information(
            this,
            tr("Cadastro de Exibicao"),
            tr("Escolha uma sala.") );
    }
    else if(ui->precoExibicao->text() == "")
    {
        QMessageBox::information(
            this,
            tr("Cadastro de Exibicao"),
            tr("Diga um preco.") );
    }
    else
    {
        Filme filme = cinema->findFilme(ui->listWidget_3->currentItem()->text().toStdString());
        Sala* sala = cinema->findSala(ui->listWidget_4->currentItem()->text().toStdString());
        cinema->addExibicao(date,time,audio,sala,filme,preco);
        ui->stackedWidget->setCurrentIndex(0);
    }
}

void MainWindow::on_listWidget_activated(const QModelIndex &index)
{
//    Filme filme = cinema->findFilme(ui->listWidget->item(index.row())->text().toStdString());
//    std::vector<Exibicao> ex = cinema->getExibicoes(filme.getNome());

//    ui->listWidget_2->clear();
//    for(unsigned int i = 0; i < ex.size(); i++)
//    {
//        Exibicao exibicao = ex[i];
//        ui->listWidget_2->addItem(QString("Data: ") + exibicao.getData().toString() + QString(" Horario: ") + exibicao.getHorario().toString() + QString("Sala: ") + QString(exibicao.getSalaNome().c_str()) );
//    }

}

void MainWindow::on_listWidget_2_clicked(const QModelIndex &index)
{
    ui->comboBox_2->clear();
    QString s = ui->listWidget_2->item(index.row())->text();
    QStringList l = s.split("  ");
    QStringList l2 = l.at(0).split(".");
    QStringList l3 = l.at(1).split(":");

    QDate date(l2.at(2).toInt(),l2.at(1).toInt(),l2.at(0).toInt());
    QTime time(l3.at(0).toInt(),l3.at(1).toInt(),l3.at(2).toInt());
    std::string nome = l.at(2).toStdString();
    Exibicao ex = cinema->findExibicao(date,time,nome);

    std::vector<Assento*> assentosLivres = cinema->getAssentosLivres(ex);

    for(unsigned int i = 0; i < assentosLivres.size(); i++)
    {
        Assento* assento = assentosLivres[i];
        ui->comboBox_2->addItem(QString::number(assento->getNumero()));
    }
}

void MainWindow::on_CompraIngressoButton_clicked()
{
    QModelIndex index = ui->listWidget_2->currentIndex();
    QString s = ui->listWidget_2->item(index.row())->text();
    QStringList l = s.split("  ");
    QStringList l2 = l.at(0).split(".");
    QStringList l3 = l.at(1).split(":");

    QDate date(l2.at(2).toInt(),l2.at(1).toInt(),l2.at(0).toInt());
    QTime time(l3.at(0).toInt(),l3.at(1).toInt(),l3.at(2).toInt());
    std::string nome = l.at(2).toStdString();
    Exibicao ex = cinema->findExibicao(date,time,nome);
    int indice = ui->comboBox_2->currentIndex();
    int assento = ui->comboBox_2->itemText(indice).toInt();
    ex.marcaAssento(assento,false);
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_listWidget_5_clicked(const QModelIndex &index)
{
    std::string s = ui->listWidget_5->currentItem()->text().toStdString();
    int publico = cinema->calculaPublicoFilme(s);
    float rendimento = cinema->calculaRendimentoFilme(s);
    ui->publicoLabel->setText(QString("R$") +QString::number(publico));
    ui->rendimentoLabel->setText(QString::number(rendimento)+ QString(" pessoas"));
}

void MainWindow::on_voltarMenuButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}
