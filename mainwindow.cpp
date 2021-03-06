#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "universiade.h"
#include <QTabBar>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->tabWidget->tabBar()->hide();
    //ui->tabWidget->tabBar()->cu

}



int Universiade::day = 0;
int Universiade::mounth = 0;
int Universiade::year = 0;
string Universiade::name = "";




MainWindow::~MainWindow()
{
    delete ui;
}


MoreBetter Jump;
SmallerBetter Swimming;
SmallerBetter Run;

void MainWindow::on_AddPerson_clicked()
{
    //ui->tableWidget->clear();

    Jump.AddElement(ui->NameEdit->text().toStdString(),ui->SurnameEdit->text().toStdString(),ui->ResultEdit->text().toInt(),ui->Universities->currentText().toStdString());

    int size = Jump.Size();

    ui->tableWidget->setRowCount(size);
    int i = 0;

    Jump.Sort();
    Person *tmp = Jump.GetStart();
    while(tmp) {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::fromStdString(tmp->name)));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::fromStdString(tmp->surname)));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::number(tmp->result)));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::fromStdString(tmp->nameOfUniversity)));
        i++;
        tmp = tmp->next;
    }



}

void MainWindow::on_AddPerson_2_clicked()
{
    //ui->tableWidget_2->clear();

    Swimming.AddElement(ui->NameEdit_2->text().toStdString(),ui->SurnameEdit_2->text().toStdString(),ui->ResultEdit_2->text().toInt(),ui->Universities_2->currentText().toStdString());

    int size = Swimming.Size();

    ui->tableWidget_2->setRowCount(size);
    int i = 0;

    Swimming.Sort();
    Person *tmp = Swimming.GetStart();
    while(tmp) {
        ui->tableWidget_2->setItem(i,0,new QTableWidgetItem(QString::fromStdString(tmp->name)));
        ui->tableWidget_2->setItem(i,1,new QTableWidgetItem(QString::fromStdString(tmp->surname)));
        ui->tableWidget_2->setItem(i,2,new QTableWidgetItem(QString::number(tmp->result)));
        ui->tableWidget_2->setItem(i,3,new QTableWidgetItem(QString::fromStdString(tmp->nameOfUniversity)));
        i++;
        tmp = tmp->next;
    }
}

void MainWindow::on_AddPerson_3_clicked()
{
    //ui->tableWidget_3->clear();

    Run.AddElement(ui->NameEdit_3->text().toStdString(),ui->SurnameEdit_3->text().toStdString(),ui->ResultEdit_3->text().toInt(),ui->Universities_3->currentText().toStdString());

    int size = Run.Size();

    ui->tableWidget_3->setRowCount(size);
    int i = 0;

    Run.Sort();
    Person *tmp = Run.GetStart();
    while(tmp) {
        ui->tableWidget_3->setItem(i,0,new QTableWidgetItem(QString::fromStdString(tmp->name)));
        ui->tableWidget_3->setItem(i,1,new QTableWidgetItem(QString::fromStdString(tmp->surname)));
        ui->tableWidget_3->setItem(i,2,new QTableWidgetItem(QString::number(tmp->result)));
        ui->tableWidget_3->setItem(i,3,new QTableWidgetItem(QString::fromStdString(tmp->nameOfUniversity)));
        i++;
        tmp = tmp->next;
    }

}

void MainWindow::on_SetName_clicked()
{
    ui->NameOFUniversityEdit->setEnabled(false);
    //ui->SetName->setHidden(true);

    Jump.setName(ui->NameOFUniversityEdit->text().toStdString());
}

void MainWindow::on_SetDate_clicked()
{
    ui->spinBox->setEnabled(false);
    ui->spinBox_2->setEnabled(false);
    ui->spinBox_3->setEnabled(false);
    //ui->SetDate->setHidden(true);


    Jump.setDate(ui->spinBox->text().toInt(),ui->spinBox_2->text().toInt(),ui->spinBox_3->text().toInt());
}

void MainWindow::on_SetClassName_clicked()
{
    ui->JumpsClass->setText(QString::fromStdString(Jump.print()));
    ui->SwimmingClass->setText(QString::fromStdString(Swimming.print()));
    ui->RunClass->setText(QString::fromStdString(Run.print()));
}

void MainWindow::on_SetWinner_clicked()
{
    int NULP =0;
    int LNU =0;
    Jump.SetLeader();
    Swimming.SetLeader();
    Run.SetLeader();
    if(Jump.GetStart()->nameOfUniversity == "NULP"){NULP++;}
    if(Swimming.GetStart()->nameOfUniversity == "NULP"){NULP++;}
    if(Run.GetStart()->nameOfUniversity == "NULP"){NULP++;}
    if(Jump.GetStart()->nameOfUniversity == "LNU"){LNU++;}
    if(Swimming.GetStart()->nameOfUniversity == "LNU"){LNU++;}
    if(Run.GetStart()->nameOfUniversity == "LNU"){LNU++;}
    ui->NULP->setNum(NULP);
    ui->LNU->setNum(LNU);

}
