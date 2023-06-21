#include "txtsave.h"
#include "ui_txtsave.h"

TxtSave::TxtSave(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TxtSave)
{
    ui->setupUi(this);
}

TxtSave::~TxtSave()
{
    delete ui;
}

void TxtSave::on_lineEdit_textChanged(const QString &arg1)
{
    QRegularExpression regExp(arg1);
    ui->listWidget->clear();
    ui->listWidget->addItems(m_lista.filter(regExp));
    ui->lblTotal->setText(QString("%1").arg(ui->listWidget->count()));
}


void TxtSave::on_listWidget_currentTextChanged(const QString &currentText)
{
    QMessageBox::information(0,"Aviso",currentText);//ui->listWidget->currentItem()->text());
}

