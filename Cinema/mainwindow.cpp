#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

#include "filme.h"
#include "sala.h"
#include "exibicao.h"
#include "situacaoassento.h"
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include<QFile>

void MainWindow::loadJson()
{

  QFile file("../Example.json");
  file.open(QIODevice::ReadOnly | QIODevice::Text);
  QByteArray jsonData = file.readAll();
  file.close();

  QJsonDocument document = QJsonDocument::fromJson(jsonData);
  QJsonObject object = document.object();

  QJsonValue valueFilme = object.value("Filmes");
  QJsonArray arrayFilmes = valueFilme.toArray();
  foreach (const QJsonValue & v, arrayFilmes)
  {
          std::string nome = v.toObject().value("Nome").toString().toStdString();
          int ano =  v.toObject().value("Ano").toString().toInt();
          int classificacao = v.toObject().value("Classificacao").toString().toInt();
          std::string nacionalidade = v.toObject().value("Nacionalidade").toString().toStdString();
          cinema->registraFilme(nome,ano,classificacao,nacionalidade);
  }

  QJsonValue valueSala = object.value("Salas");
  QJsonArray arraySalas = valueSala.toArray();
  foreach (const QJsonValue & v, arraySalas)
  {
          std::string nome = v.toObject().value("Nome").toString().toStdString();
          int nAss = v.toObject().value("NAssentos").toString().toInt();
          QJsonArray arrayExibicoes = v.toObject().value("Exibicoes").toArray();
          foreach (const QJsonValue & v, arrayExibicoes)
          {
              //Ler Exibicoes
              std::string audio = v.toObject().value("Audio").toString().toStdString();
              float preco = v.toObject().value("Preco").toString().toFloat();
              QDate date = QDate::fromString(v.toObject().value("Data").toString(),"dd.MM.yyyy");
              QTime time = QTime::fromString(v.toObject().value("Horario").toString());
              //Vendo o filme
              std::string filme = v.toObject().value("Filme").toString().toStdString();;
              Sala* sala = new Sala(nome,nAss);
              cinema->addExibicao(date,time,audio,sala,cinema->findFilme(filme),preco);

              QJsonArray arraySitu = v.toObject().value("Situacao Assento").toArray();
              foreach (const QJsonValue & v, arraySitu)
              {
                  bool status = v.toObject().value("Status").toBool();
                  bool tipo =  v.toObject().value("Tipo").toBool();
                  int numero = v.toObject().value("NAssento").toString().toInt();

                  Exibicao ex = cinema->findExibicao(date,time,nome);
                  ex.marcaAssento(numero,status,tipo);
              }
              //Falta colocar situacao dos assentos
          }
          Sala* sala = new Sala(nome,nAss);
          cinema->addSala(sala);
  }

}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cinema = new Cinema();

    loadJson();
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
    bool tipo = false;
    if(ui->tipoInteira->isChecked())
    {
        tipo = true;
    }
    ex.marcaAssento(assento,false,tipo);
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_listWidget_5_clicked(const QModelIndex &index)
{
    std::string s = ui->listWidget_5->currentItem()->text().toStdString();
    int publico = cinema->calculaPublicoFilme(s);
    float rendimento = cinema->calculaRendimentoFilme(s);
    ui->publicoLabel->setText(QString::number(publico) + QString(" pessoas"));
    ui->rendimentoLabel->setText(QString("R$") + QString::number(rendimento));
}

void MainWindow::on_voltarMenuButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}
QJsonObject MainWindow::salvaFilme(Filme filme)
{
    QJsonObject filmeObject;
    std::string nome = filme.getNome();
    int ano = filme.getAno();
    int classi = filme.getClassificacao();
    std::string nacionalidade = filme.getNacionalidade();
    filmeObject.insert("Nome", QJsonValue::fromVariant(nome.c_str()));
    filmeObject.insert("Ano", QJsonValue::fromVariant(QString::number(ano).toStdString().c_str()));
    filmeObject.insert("Nacionalidade", QJsonValue::fromVariant(nacionalidade.c_str()));
    filmeObject.insert("Classificacao", QJsonValue::fromVariant(classi));

    return filmeObject;
}

QJsonObject MainWindow::salvaAssento(Assento* assento)
{
    QJsonObject assentoObj;
    //bool status = assento->getStatus();
    int numero = assento->getNumero();
    //assentoObj.insert("Status",QJsonValue::fromVariant(status));
    assentoObj.insert("Numero",QJsonValue::fromVariant(numero));

    return assentoObj;
}

QJsonObject MainWindow::salvaSituacaoAssento(SituacaoAssento* situ)
{
    QJsonObject situAssento;
    bool status = situ->getStatusAssentoEmExibicao();
    bool tipo = situ->getTipoAssento();
    situAssento.insert("Status",QJsonValue::fromVariant(status));
    situAssento.insert("TipoAssento", QJsonValue::fromVariant(tipo));
    //Não precisa de exibicao pq infos ja estão guardadas
    Assento* assento = situ->getAssento();
    //QJsonObject assentoObj = salvaAssento(assento);
    situAssento.insert("NAssento", QJsonValue::fromVariant(QString::number(assento->getNumero())));

    //situAssento.insert("Assento",assentoObj);

    return situAssento;
}

QJsonObject MainWindow::salvaExibicao(Exibicao exibicao)
{
    QJsonObject salaExibicao;

    QTime horario = exibicao.getHorario();

    std::string audio = exibicao.getAudio();

    QDate dia = exibicao.getData();

    Filme filme = exibicao.getFilme();

    float preco = exibicao.getPreco();

    salaExibicao.insert("Data",QJsonValue::fromVariant(dia.toString("dd.MM.yyyy")));
    salaExibicao.insert("Audio",QJsonValue::fromVariant(audio.c_str()));
    salaExibicao.insert("Horario",QJsonValue::fromVariant(horario.toString().toStdString().c_str()));
    salaExibicao.insert("Preco",QJsonValue::fromVariant(QString::number(preco).toStdString().c_str()));
    salaExibicao.insert("Filme",QJsonValue::fromVariant(filme.getNome().c_str()));

    std::vector<SituacaoAssento*> situs = exibicao.getSituacaoAssentos();
    QJsonArray situArray;
    //Salva sala
    for(unsigned int i = 0; i < situs.size(); i++)
    {
        SituacaoAssento* s = situs[i];
        QJsonObject situAssento = salvaSituacaoAssento(s);
        situArray.push_back(situAssento);
    }
    salaExibicao.insert("Situacao Assento",situArray);
    return salaExibicao;
}



void MainWindow::on_salvarButton_clicked()
{

    std::vector<Filme> filmes = cinema->getFilmesEmExibicao();
    QJsonObject recordObject;
    QJsonArray filmeObjectArray;
    QJsonObject filmeObject;
    QJsonArray salaObjectArray;
    QJsonObject salaObject;

    //Salva Filmes
    for(unsigned int i = 0; i < filmes.size(); i ++)
    {
        Filme filme = filmes[i];
        filmeObject = salvaFilme(filme);
        filmeObjectArray.push_back(filmeObject);


    }
    recordObject.insert("Filmes",filmeObjectArray);

    std::vector<Sala*> salas = cinema->getSalas();
    //Salva sala
    for(unsigned int i = 0; i < salas.size(); i++)
    {
        Sala* sala = salas[i];
        std::string nome = sala->getName();
        int nAss = sala->getNumAssentos();

        salaObject.insert("Nome", QJsonValue::fromVariant(nome.c_str()));
        salaObject.insert("NAssentos", QJsonValue::fromVariant(QString::number(nAss).toStdString().c_str()));

        QJsonArray ExibicoesSalaArray;
        QJsonObject salaExibicao;
        std::vector<Exibicao> ex = sala->getExibicoes();
        for(unsigned int i = 0; i < ex.size(); i ++)
        {
            Exibicao exibicao = ex[i];
            salaExibicao = salvaExibicao(exibicao);
            ExibicoesSalaArray.push_back(salaExibicao);
        }
        QJsonValue q(ExibicoesSalaArray);
        salaObject.insert("Exibicoes",q);
        salaObjectArray.push_back(salaObject);


    }
    recordObject.insert("Salas",salaObjectArray);

    QJsonDocument doc(recordObject);

    QFile jsonFile("../Example.json");
    jsonFile.open(QFile::WriteOnly);
    jsonFile.write(doc.toJson());

}
