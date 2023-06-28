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
    QRegularExpression regExp(arg1.toUpper());
    ui->lstClientes->clear();
    ui->lstClientes->addItems(lista().filter(regExp));
    ui->lblTotal->setText(QString("%1").arg(ui->lstClientes->count()));
}

void TxtSave::setDatos(Archivo &newDatos)
{
    m_datos = &newDatos;
    setLista(m_datos->lista());
    setClientes(m_datos->clientes());

    ui->lstClientes->clear();
    ui->lstClientes->addItems(lista());
    ui->lblTotal->setText(QString("%1").arg(ui->lstClientes->count()));
}

const QList<Cliente *> &TxtSave::clientes() const
{
    return m_clientes;
}

const QStringList &TxtSave::lista() const
{
    return m_lista;
}

void TxtSave::setClientes(const QList<Cliente *> &newClientes)
{
    m_clientes = newClientes;
}

void TxtSave::setLista(const QStringList &newLista)
{
    m_lista = newLista;
    //ui->listWidget->addItems(lista());
}


void TxtSave::on_lstClientes_currentTextChanged(const QString &currentText)
{
    foreach (Cliente *actual,m_clientes) {
        if(actual->nombre()==currentText){
            ui->lblNombres->setText(actual->nombres());
            ui->lblApellidos->setText(actual->apellidos());
            ui->lblCedula->setText(actual->cedula());
            ui->lblDireccion->setText(actual->direccion());
            ui->lblCiudad->setText(actual->ciudad());
            ui->lblTelefono->setText(actual->telefono());
            ui->lblCorreo->setText(actual->correo());
        }
    }
}

