#include "qlogindialog.h"

QsshLoginDialog::QsshLoginDialog(QWidget *parent)
    : QDialog{parent}
{
    setWindowTitle("登录");
    setModal(true);
    this->resize(400,600);
    this->createLoginWidget();
}


void QsshLoginDialog::createLoginWidget(){
    loginLayout = new QVBoxLayout();
    this->setLayout(loginLayout);
    Login = new QTabWidget();
    sshPasswdLogin = new QWidget();
    sshPubKeyLogin = new QWidget();
    telnetLogin = new QWidget();
    loginLayout->addWidget(Login);
    Login->addTab(sshPasswdLogin, "口令登录");
    Login->addTab(sshPubKeyLogin, "公钥登录");
    Login->addTab(telnetLogin, "Telnet");

    this->passwdLogin();

}

/*******************口令登录界面****************************/
void QsshLoginDialog::passwdLogin(){
    passwdUserNameLabel = new QLabel("用户名：");
    passwdPwdLabel = new QLabel("密   码：");
    passwdIpAddressLabel = new QLabel("IP地址：");
    passwdPortLabel = new QLabel("端口号：");
    passwdUserName = new QLineEdit();
    passwdUserName->setFixedSize(150,30);
    passwdPwd = new QLineEdit();
    passwdPwd->setFixedSize(150,30);
    passwdIpAddress = new QLineEdit();
    passwdIpAddress->setFixedSize(150,30);
    passwdPort = new QSpinBox();
    passwdPort->setFixedSize(100,30);
    passwdPort->setMaximum(65535);
    passwdUserNameLayout = new QHBoxLayout();
    passwdPwdLayout = new QHBoxLayout();
    passwdIpAddressLayout = new QHBoxLayout();
    passwdPortLayout = new QHBoxLayout();
    passwdLayout = new QVBoxLayout();
    passwdConnectBtn = new QPushButton("登录");
    sshPasswdLogin->setLayout(passwdLayout);

    passwdLayout->addLayout(passwdUserNameLayout);
    passwdLayout->addLayout(passwdPwdLayout);
    passwdLayout->addLayout(passwdIpAddressLayout);
    passwdLayout->addLayout(passwdPortLayout);
    passwdLayout->addWidget(passwdConnectBtn, 0, Qt::AlignHCenter);
    passwdUserNameLayout->addWidget(passwdUserNameLabel);
    passwdUserNameLayout->addWidget(passwdUserName, 0, Qt::AlignLeft);
    passwdUserNameLayout->addStretch();
    passwdPwdLayout->addWidget(passwdPwdLabel);
    passwdPwdLayout->addWidget(passwdPwd, 0, Qt::AlignLeft);
    passwdPwdLayout->addStretch();
    passwdIpAddressLayout->addWidget(passwdIpAddressLabel);
    passwdIpAddressLayout->addWidget(passwdIpAddress, 0, Qt::AlignLeft);
    passwdIpAddressLayout->addStretch();
    passwdPortLayout->addWidget(passwdPortLabel, 0, Qt::AlignLeft);
    passwdPortLayout->addWidget(passwdPort, 0, Qt::AlignLeft);
    passwdPortLayout->addStretch();

}
