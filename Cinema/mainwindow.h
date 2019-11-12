#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "cinema.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
void loadJson();
QJsonObject salvaFilme(Filme filme);
QJsonObject salvaExibicao(Exibicao exibicao);
QJsonObject salvaSituacaoAssento(SituacaoAssento* situ);
QJsonObject salvaAssento(Assento* assento);

private slots:
    void on_CompraIngressosButton_clicked();

    void on_CadastroFilmesButton_clicked();

    void on_VoltarMenuButton_clicked();

    void on_cadastrarFilmeButton_clicked();

    void on_listWidget_clicked(const QModelIndex &index);


    void on_cadastroExibicoesButton_clicked();

    void on_cadastroSalasButton_clicked();

    void on_voltarMenuButton_clicked();

    void on_cadastroSalaButton_clicked();


    void on_dateTimeEdit_dateTimeChanged(const QDateTime &dateTime);

    void on_voltarMenuButton_2_clicked();

    void on_voltarMenuButton_3_clicked();

    void on_CadastrarExibicaoButton_clicked();

    void on_listWidget_activated(const QModelIndex &index);

    void on_listWidget_2_clicked(const QModelIndex &index);

    void on_CompraIngressoButton_clicked();

    void on_RendimentoButton_clicked();

    void on_listWidget_5_clicked(const QModelIndex &index);

    void on_voltarMenuButton_4_clicked();

    void on_salvarButton_clicked();

private:
    Ui::MainWindow *ui;
    Cinema *cinema;


};

#endif // MAINWINDOW_H
