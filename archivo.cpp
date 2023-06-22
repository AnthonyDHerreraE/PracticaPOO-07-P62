#include "archivo.h"

Archivo::Archivo()
{

    leerArchivo();
}

void Archivo::leerArchivo()
{
    QFile nombreArchivo;
    QTextStream io;
    nombreArchivo.setFileName("Clientes.csv");
    nombreArchivo.open(QIODevice::Text | QIODevice::ReadOnly);
    if(!nombreArchivo.isOpen()){
        QMessageBox::critical(0,tr("Error"),nombreArchivo.errorString());
        return;
    };
    io.setDevice(&nombreArchivo);

    while(!io.atEnd()){
        QString datosLinea=io.readLine();
        QStringList datos=datosLinea.split(";");

        Cliente* actual = new Cliente();
        actual->setNombre(datos[0]+" "+datos[1]);
        actual->setCedula(datos[2]);
        actual->setDireccion(datos[3]);
        actual->setCiudad(datos[4]);
        actual->setTelefono(datos[5]);
        actual->setCorreo(datos[6]);

        m_clientes.push_back(actual);
        m_lista.push_back(actual->nombre());

    }
        nombreArchivo.flush();
        nombreArchivo.close();


}

void Archivo::guardarArchivo()
{
    QFile nombreArchivo;
    QTextStream io;
    nombreArchivo.setFileName("Clientes.csv");
    nombreArchivo.open(QIODevice::Text | QIODevice::WriteOnly | QIODevice::Append);
    if(!nombreArchivo.isOpen()){
        qDebug()<<"Error...!"<<nombreArchivo.errorString()<<"\n";
        return;
    }
    io.setDevice(&nombreArchivo);

    foreach (Cliente *actual,m_clientes) {
        io<<actual->nombres()<<";"
        <<actual->apellidos()<<";"
        <<actual->cedula()<<";"
        <<actual->direccion()<<";"
        <<actual->ciudad()<<";"
        <<actual->telefono()<<";"
        <<actual->correo()<<"\n";
    }

    nombreArchivo.flush();
    nombreArchivo.close();
}

void Archivo::guardarCliente(Cliente &dato)
{
    m_clientes.push_back(&dato);
    guardarArchivo();
}


const QList<Cliente *> &Archivo::clientes()
{
    return m_clientes;
}

const QStringList &Archivo::lista()
{
    return m_lista;
}

