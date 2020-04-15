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
    void on_AddPerson_clicked();

    void on_AddPerson_2_clicked();

    void on_AddPerson_3_clicked();

    void on_SetName_clicked();

    void on_SetDate_clicked();

    void on_SetClassName_clicked();

    void on_SetWinner_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
