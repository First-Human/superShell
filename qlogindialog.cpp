#include "qlogindialog.h"

QsshLoginDialog::QsshLoginDialog(QWidget *parent)
    : QDialog{parent}
{
    setWindowTitle("登录");
    setModal(true);
    this->setFixedSize(480, 650);
    this->createLoginWidget();
    connect(sshLoginType, QOverload<int>::of(&QComboBox::activated), this, &QsshLoginDialog::sshLoginTypeSlots);
}


void QsshLoginDialog::createLoginWidget(){
    loginLayout = new QVBoxLayout();
    this->setLayout(loginLayout);
    Login = new QTabWidget();
    sshLogin = new QWidget();
    telnetLogin = new QWidget();
    loginLayout->addWidget(Login);
    Login->addTab(sshLogin, "SSH登录");
    Login->addTab(telnetLogin, "Telnet");

    this->sshLoginWidget();

}

/*******************ssh登录界面****************************/
void QsshLoginDialog::sshLoginWidget(){
    loginParamGroupBox = new QGroupBox(sshLogin);
    loginParamGroupBox->setTitle("登陆参数");
    algCheckGroupBox = new QGroupBox(sshLogin);
    algCheckGroupBox->setTitle("算法选择");


    sshLoginTypeLabel = new QLabel("登陆方式：");
    sshUserNameLabel = new QLabel("用户名：");
    sshPasswdLabel = new QLabel("密   码：");
    sshPubkPathLabel = new QLabel("公钥路径：");
    sshIpAddressLabel = new QLabel("IP地址：");
    sshPortLabel = new QLabel("端口号：");
    sshLoginType = new QComboBox();
    sshLoginType->addItem("密码登录");
    sshLoginType->addItem("公钥登录");
    sshLoginType->setFixedSize(100,30);
    sshUserName = new QLineEdit();
    sshUserName->setFixedSize(150,30);
    sshPasswd = new QLineEdit();
    sshPasswd->setFixedSize(150,30);
    sshPubkPath = new QLineEdit();
    sshPubkPath->setFixedSize(350,30);
    sshPubkPath->setEnabled(false);
    sshIpAddress = new QLineEdit();
    sshIpAddress->setFixedSize(150,30);
    sshPort = new QSpinBox();
    sshPort->setValue(22);
    sshPort->setFixedSize(80,30);
    sshPort->setMaximum(65535);
    sshLoginTypeLayout = new QHBoxLayout();
    sshUserNamePasswdLayout = new QHBoxLayout();
    sshPubkPathLayout = new QHBoxLayout();
    sshIpAddressPortLayout = new QHBoxLayout();

    sshLayout = new QVBoxLayout();
    loginParamLayout = new QVBoxLayout();
    algParamLayout = new QVBoxLayout();
    sshConnectBtn = new QPushButton("登录");


    sshLogin->setLayout(sshLayout);
    sshLayout->addWidget(loginParamGroupBox);
    sshLayout->addWidget(algCheckGroupBox);
    sshLayout->addWidget(sshConnectBtn, 0, Qt::AlignHCenter);

    loginParamGroupBox->setLayout(loginParamLayout);

    loginParamLayout->addLayout(sshLoginTypeLayout);
    loginParamLayout->addLayout(sshIpAddressPortLayout);
    loginParamLayout->addLayout(sshUserNamePasswdLayout);
    loginParamLayout->addLayout(sshPubkPathLayout);


    sshLoginTypeLayout->addWidget(sshLoginTypeLabel);
    sshLoginTypeLayout->addWidget(sshLoginType, 0, Qt::AlignLeft);
    sshLoginTypeLayout->addStretch();
    sshUserNamePasswdLayout->addWidget(sshUserNameLabel);
    sshUserNamePasswdLayout->addWidget(sshUserName, 0, Qt::AlignLeft);
    sshUserNamePasswdLayout->addStretch();
    sshUserNamePasswdLayout->addWidget(sshPasswdLabel, 0, Qt::AlignRight);
    sshUserNamePasswdLayout->addWidget(sshPasswd, 0, Qt::AlignRight);
    sshPubkPathLayout->addWidget(sshPubkPathLabel);
    sshPubkPathLayout->addWidget(sshPubkPath, 0, Qt::AlignLeft);
    sshPubkPathLayout->addStretch();

    sshIpAddressPortLayout->addWidget(sshIpAddressLabel, 0, Qt::AlignLeft);
    sshIpAddressPortLayout->addWidget(sshIpAddress, 0, Qt::AlignLeft);
    sshIpAddressPortLayout->addStretch();
    sshIpAddressPortLayout->addWidget(sshPortLabel, 0, Qt::AlignRight);
    sshIpAddressPortLayout->addWidget(sshPort, 0, Qt::AlignRight);

    algCheckGroupBox->setLayout(algParamLayout);
    sshHostkeyAlgLayout = new QHBoxLayout();
    sshKexAlgLayout = new QHBoxLayout();
    sshCipherAlgLayout = new QHBoxLayout();
    sshMacAlgLayout = new QHBoxLayout();
    algParamLayout->addLayout(sshHostkeyAlgLayout);
    algParamLayout->addLayout(sshKexAlgLayout);
    algParamLayout->addLayout(sshCipherAlgLayout);
    algParamLayout->addLayout(sshMacAlgLayout);
    sshHostkeyAlgLabel = new QLabel("主机密钥算法：");
    sshKexAlgLabel = new QLabel("密钥协商算法：");
    sshCiherAlgLabel = new QLabel("对称加密算法：");
    sshMacAlgLabel = new QLabel("哈  希  算  法：");
    sshHostkeyAlgCheck = new QComboBox();
    sshHostkeyAlgCheck->setFixedSize(300,30);
    sshKexAlgCheck = new QComboBox();
    sshKexAlgCheck->setFixedSize(300,30);
    sshCipherAlgCheck = new QComboBox();
    sshCipherAlgCheck->setFixedSize(300,30);
    sshMacAlgCheck = new QComboBox();
    sshMacAlgCheck->setFixedSize(300,30);

    sshHostkeyAlgLayout->addWidget(sshHostkeyAlgLabel);
    sshHostkeyAlgLayout->addWidget(sshHostkeyAlgCheck, 0, Qt::AlignLeft);
    sshHostkeyAlgLayout->addStretch();

    sshKexAlgLayout->addWidget(sshKexAlgLabel);
    sshKexAlgLayout->addWidget(sshKexAlgCheck, 0, Qt::AlignLeft);
    sshKexAlgLayout->addStretch();

    sshCipherAlgLayout->addWidget(sshCiherAlgLabel);
    sshCipherAlgLayout->addWidget(sshCipherAlgCheck, 0, Qt::AlignLeft);
    sshCipherAlgLayout->addStretch();

    sshMacAlgLayout->addWidget(sshMacAlgLabel);
    sshMacAlgLayout->addWidget(sshMacAlgCheck, 0, Qt::AlignLeft);
    sshMacAlgLayout->addStretch();

}


void QsshLoginDialog::sshLoginTypeSlots(int index){
    if(index == 0){
        sshPasswd->setEnabled(true);
        sshPubkPath->setEnabled(false);
    }
    else{
        sshPasswd->setEnabled(false);
        sshPubkPath->setEnabled(true);
    }
}
