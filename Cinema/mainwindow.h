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


private slots:
    void on_CompraIngressosButton_clicked();

    void on_CadastroFilmesButton_clicked();

    void on_VoltarMenuButton_clicked();

    void on_cadastrarFilmeButton_clicked();

private:
    Ui::MainWindow *ui;
    Cinema *cinema;


};

#endif // MAINWINDOW_H
