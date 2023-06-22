#include "cliente.h"

Cliente::Cliente(QObject *parent)
    : QObject{parent}
{

}

const QString &Cliente::nombre() const
{
    return m_nombre;
}

void Cliente::setNombre(const QString &newNombre)
{
    m_nombre = newNombre;
    QStringList nombreCompleto = newNombre.split(" ");
    for(int i=0;i<2;i++){
        m_nombres += nombreCompleto.front() + " ";
        nombreCompleto.pop_front();
    }
    while(!nombreCompleto.isEmpty()){
        m_apellidos += nombreCompleto.front() + " ";
        nombreCompleto.pop_front();
    }
    m_nombres=m_nombres.trimmed();
    m_apellidos=m_apellidos.trimmed();
}


const QString &Cliente::cedula() const
{
    return m_cedula;
}

void Cliente::setCedula(const QString &newCedula)
{
    m_cedula = newCedula;
}

const QString &Cliente::direccion() const
{
    return m_direccion;
}

void Cliente::setDireccion(const QString &newDireccion)
{
    m_direccion = newDireccion;
}

const QString &Cliente::ciudad() const
{
    return m_ciudad;
}

void Cliente::setCiudad(const QString &newCiudad)
{
    m_ciudad = newCiudad;
}

const QString &Cliente::telefono() const
{
    return m_telefono;
}

void Cliente::setTelefono(const QString &newTelefono)
{
    m_telefono = newTelefono;
}

const QString &Cliente::correo() const
{
    return m_correo;
}

void Cliente::setCorreo(const QString &newCorreo)
{
    m_correo = newCorreo;
}

void Cliente::inDatos(QString &entradaDatos)
{
    QStringList datos = entradaDatos.split("\n");
    QStringList aux;

    if(datos.isEmpty())
        return;

    for(int i=0;i<datos.size();i++){
        if(datos[i].indexOf(":")!=-1){
        aux = datos[i].split(":");
        aux.pop_front();
        datos[i] = aux.front();
        aux.clear();
        }
    }
    aux.~QStringList();


    while(!datos.empty()){
        switch(filtro(datos.front())){
        case 1:
            setNombre(datos.front());
            datos.pop_front();
            break;
        case 2:
            setCedula(datos.front());
            datos.pop_front();
            break;
        case 3:
            setDireccion(datos.front());
            datos.pop_front();
            break;
        case 4:
            setCiudad(datos.front());
            datos.pop_front();
            break;
        case 5:
            setTelefono(datos.front());
            datos.pop_front();
            break;
        case 6:
            setCorreo(datos.front());
            datos.pop_front();
            break;
        default:
            datos.pop_front();
        }
    }
}

int Cliente::filtro(QString &dato)
{
    if(dato.isEmpty())
        return 0;
    // borra espacios al inicio y al final
    dato = dato.trimmed();

    QStringList aux = dato.split(" ");
    bool esNumero = false;

    if(aux.size()<=0)
        return 0;

    for(int i=0;i<aux.size();i++){
        if(aux[i].isEmpty()){
            return 0;
        }
    }

    if(aux.front()=="DATOS")
        return 0;
    aux.front().toInt(&esNumero);

    if(aux.size()>=3&&aux.size()<=5&&nombre()=="")
        return 1;

    if(aux.size()==1&&aux.front().length()==10&&esNumero&&cedula()=="")
        return 2;

    if(aux.front().length()>2&&direccion()=="")
        return 3;

    if(aux.front().length()>2&&ciudad()=="")
        return 4;

    if(aux.size()==1&&aux.front().length()>=7&&aux.front().length()<=10&&aux.front().length()!=8&&esNumero&&telefono()=="")
        return 5;

    if(aux.size()==1&&aux.front().indexOf("@")!=-1&&correo()=="")
        return 6;

    return 0;
}

void Cliente::reset()
{
    setNombre("");
    setCedula("");
    setDireccion("");
    setCiudad("");
    setTelefono("");
    setCorreo("");
}

QString Cliente::apellidos() const
{
    return m_apellidos;
}

void Cliente::setApellidos(const QString &newApellidos)
{
    m_apellidos = newApellidos;
    if(!nombre().isEmpty())
        setNombre(nombre()+apellidos());
    qDebug() <<nombre();
}

QString Cliente::nombres() const
{
    return m_nombres;
}

void Cliente::setNombres(const QString &newNombres)
{
    m_nombres = newNombres;
    if(!apellidos().isEmpty())
        setNombre(nombre()+apellidos());
    qDebug()<<nombre();
}
