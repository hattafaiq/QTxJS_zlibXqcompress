#include "data.h"
#include "setting.h"

extern struct d_global global;
struct init_setting_k tmp;

data::data(QObject *parent) : QObject(parent)
{
  threadku = new threader();
   // QFile input(QStandardPaths::writableLocation(QStandardPaths::DataLocation)+alamat);
   QFile input(alamat);
    if(input.exists())
    {
       cek_settings();
    }
    else
    {
       init_setting();
    }
    count_db = 1;
   // pernah_penuh = 0;
    flagsave=0;
    flagtimestart=0;
    counterCH=0;
    kirimclient = 0;
    //INIT_udp
    socket = new QUdpSocket(this);
    qDebug()<<"status awal "<<socket->state();
    socket->bind(QHostAddress::Any, 5008);
    qDebug()<<"status bind "<<socket->state();
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyReady()));
    qDebug()<<"status connect "<<socket->state();
    //INIT_websocket
    m_pWebSocketServer1 = new QWebSocketServer(QStringLiteral("OVM"),QWebSocketServer::NonSecureMode,this);
    m_pWebSocketServer1->listen(QHostAddress::Any, 2121);
    connect(m_pWebSocketServer1, SIGNAL(newConnection()),this, SLOT(onNewConnection()));
    connect(m_pWebSocketServer1, &QWebSocketServer::closed, this, &data::closed);
    init_time();
}

data::~data()
{
    m_pWebSocketServer1->close();
    qDeleteAll(Subcribe_wave1.begin(), Subcribe_wave1.end());//paket10
    delete threadku;
    free_memory();
}
void data::free_memory()
{
    int i;
    for (i = 0; i < JUM_KANAL; i++)
    {
        free(data_save[i]);
        free(data_get[i]);
        free(data_prekirim[i]);
    }
}
void data::cek_settings()
{
    //QString pth = QStandardPaths::writableLocation(QStandardPaths::DataLocation)+alamat;
    QString pth = alamat;
    qDebug()<<"alamat db :" << pth;
    QSettings settings(pth, QSettings::IniFormat);
    tmp.modulIP1k = settings.value("IP1").toString();
    tmp.modulIP2k = settings.value("IP2").toString();
    tmp.fmax = settings.value("Fmax").toInt() ;
    tmp.timerdbk = settings.value("TimeSaveDB").toInt();
    tmp.timereq = settings.value("TimeReq").toInt();
    tmp.dir_DB = settings.value("Dir_DB").toString();
}


void data::init_setting()
{
   // QString pth = QStandardPaths::writableLocation(QStandardPaths::DataLocation)+alamat;
     QString pth = alamat;
    qDebug()<<"alamat db :" << pth;
    QSettings settings(pth, QSettings::IniFormat);
    qDebug()<<"tulis";

  //  memset((char *) Temp, 0, sizeof (struct init_setting_k));
    tmp.dir_DB = QString::fromUtf8("/home/fh/Server_OVM/ovm_dbe");
    tmp.modulIP1k = QString::fromUtf8("192.168.0.101");
    tmp.modulIP2k = QString::fromUtf8("192.168.0.102");

    tmp.fmax= 1000;
    tmp.timerdbk =5;
    tmp.timereq = 2;
    settings.setValue("IP1",tmp.modulIP1k);
    settings.setValue("IP2",tmp.modulIP2k);
    settings.setValue("Dir_DB",tmp.dir_DB);
    settings.setValue("Fmax",tmp.fmax);
    settings.setValue("TimeSaveDB",tmp.timerdbk);
    settings.setValue("TimeReq",tmp.timereq);
}

void data::set_memory()
{
    int i;
    for (i=0; i<JUM_KANAL; i++)
    {
        data_save[i] = (float *) malloc(((sps_fmax4000*JUM_KANAL)*5) * sizeof(float));
        memset( (char *) data_save[i], 0, (((sps_fmax4000*JUM_KANAL)*5)*sizeof(float)));
        data_get[i] = (float *) malloc(((sps_fmax4000*JUM_KANAL)*5) * sizeof(float));
        memset( (char *) data_get[i], 0, ((sps_fmax4000*JUM_KANAL)*5) * sizeof(float));
        data_prekirim[i] = (float *) malloc(((sps_fmax4000*JUM_KANAL)*5) * sizeof(float));
        memset( (char *) data_prekirim[i], 0, ((sps_fmax4000*JUM_KANAL)*5) * sizeof(float));
    }
}


void data::init_time()
{ 
    modul_1_penuh=0;
    modul_2_penuh=0;
    timer = new QTimer(this);
    QObject::connect(timer,SIGNAL(timeout()),this, SLOT(readyReady()));
    timer->start(tmp.timereq*1100);
}

void data::req_UDP()
{
    QByteArray Data;
    Data.append("getdata");
    QHostAddress ip_modul_1, ip_modul_2;
    ip_modul_1.setAddress(tmp.modulIP1k);
    ip_modul_2.setAddress(tmp.modulIP2k);
    socket->writeDatagram(Data,ip_modul_1, 5006);
    socket->writeDatagram(Data,ip_modul_2, 5006);
}

void data::showTime()
{
    QTime time = QTime::currentTime();
    time_text = time.toString("hh:mm:ss:z");
}


void data::readyReady()
{
data_kirim();
}//void

void data::data_kirim()
{
    QByteArray datagrama = "hallo dsakdhksjhdsakjdhaksjdhkjashdjksa"
                           "dsfdsfdsfdsffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
                           "sdfsdfsssssssssssssssssssssssssssssssssssssssssssssssssseeeeeeeeeeeeeeeeeeerrrrrrrrrrrrreeeeeeeeeeeee"
                           "rewrwrwe11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111"
                           "111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111"
                           "111111111111111111111111111111111111111111111111111111111111111111112222222222222222222222222222222"
                           "333333333333333333333333333333333333333333333333333333333333"
                           "44444444444444444444444444444444444444444444444444444444444444444444444444"
                           "5555555555555555555555555555555555555555555555555555555555555555555555555555"
                           "gggggggggggggggggggggggggggggggggggggggggggggggggghhhhhhhhhhhhhhhhh"
                           "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh"
                           "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhfffffffffffffffffffffffffffff"
                           "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff";
    qDebug()<<"size data byte array="<<datagrama.size();
    //seberapa efektif besaran datanya
    //misal berapa kilo
    QByteArray kirim_yuk = qCompress(datagrama,9);
    qDebug()<<"size data byte array kompres="<<kirim_yuk.size();
    kirim_yuk.remove(0,4);// note dia harus dipotong 4 didepan!!!!!
    qDebug()<<kirim_yuk;
    sendDataClient1(kirim_yuk);
    qDebug()<<QDateTime::currentMSecsSinceEpoch()<<"kirim";
}



void data::start_database()
{
    for(int i =0; i<JUM_KANAL; i++)//8
    {
        if(cnt_ch[i] < spektrum_points)
        {
            threadku->safe_to_save_ch[i] = 0;
            continue;
        }
        else
        {
            threadku->safe_to_save_ch[i] = 1;
        }
        memcpy(&data_get[i][0], &data_save[i][cnt_ch[i]-(spektrum_points)], spektrum_points * (sizeof(float)));
        QByteArray array0((char *) &data_get[i][0], spektrum_points * sizeof(float));
        threadku->bb1[i] = array0;
        threadku->ref_rpm = 6000;
        threadku->num = spektrum_points;
        threadku->fmax = tmp.fmax;

        threadku->start();

        array0.clear();
        }
        for(int i =0; i<JUM_KANAL; i++)//8
        {
            cnt_ch[i] =0;
        }
       qDebug()<<"data save ";
//       qDebug()<<"status socket"<<socket->state();

}

void data::refresh_plot()
{
    req_UDP();
    tim_count++;
}

void data::onNewConnection()
{
    C_NewCon = m_pWebSocketServer1->nextPendingConnection();
    connect(C_NewCon, &QWebSocket::binaryMessageReceived, this, &data::processMessage);
    connect(C_NewCon, &QWebSocket::disconnected, this, &data::socketDisconnected);
}

void data::processMessage(QByteArray message)
{
    QWebSocket *C_NewReq = qobject_cast<QWebSocket *>(sender());
       // qDebug()<<message;

    QByteArray ba1;;
    QByteArray unsub;
    QString unsub_wave1 ="unsub";
    pesan_topik ="fmax1000";
    ba1 += pesan_topik;
    unsub += unsub_wave1;

    if((C_NewReq)&&(message==ba1))
    {
        Subcribe_wave1.removeOne(C_NewReq);
        Subcribe_wave1 << C_NewReq;
        qDebug()<<"req wave 1 dari:"<<C_NewReq->peerAddress().toString();
    }
    if((C_NewReq)&&(message==unsub))
    {
        Subcribe_wave1.removeOne(C_NewReq);
        qDebug()<<"unsub scribe dari:"<<C_NewReq->peerAddress().toString();
    }

//    qDebug()<<"data masuk "<<data_prekirim[0][10]<<"  "<<data_prekirim[0][20];
//    qDebug()<<"last data check"<<last_data_check1 << " "<<last_data_check2;

}

void data::sendDataClient1(QByteArray isipesan)
{
    Q_FOREACH (pClientkirim, Subcribe_wave1)//paket10
    {
        QHostAddress join=pClientkirim->peerAddress();
        QString joinstr=join.toString();
        qDebug() << "kirim paket 1----ke : "<<joinstr;
        pClientkirim->sendBinaryMessage(isipesan);
    }
}


void data::socketDisconnected()
{
    pClient1 = qobject_cast<QWebSocket *>(sender());
    if (pClient1)
    {
        Subcribe_wave1.removeOne(pClient1);//paket10
        pClient1->deleteLater();
        QHostAddress join=pClient1->peerAddress();
        QString loststr=join.toString();
        qDebug()<<"client loss" << loststr;
    }
}
