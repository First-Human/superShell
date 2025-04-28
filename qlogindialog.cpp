#include "qlogindialog.h"

QsshLoginDialog::QsshLoginDialog(int loginSessionType, QWidget *parent)
    : QDialog{parent}
{
    setWindowTitle("登录");
    setModal(true);
    sessionType = loginSessionType;
    this->setFixedSize(480, 650);
    this->createLoginWidget();
    connect(sshLoginType, QOverload<int>::of(&QComboBox::activated), this, &QsshLoginDialog::sshLoginTypeSlots);
    connect(sshResetBtn, &QPushButton::clicked, this, &QsshLoginDialog::sshLoginResetSlots);
    connect(sshCancelBtn, &QPushButton::clicked, this, &QDialog::close);
    connect(sshPubkPathBtn, &QPushButton::clicked, this, &QsshLoginDialog::sshCheckPubkPath);
    connect(sshConnectBtn, &QPushButton::clicked, this, &QsshLoginDialog::sshLoginSlots);
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
    loginParamGroupBox->setTitle("登录参数");
    algCheckGroupBox = new QGroupBox(sshLogin);
    algCheckGroupBox->setTitle("算法选择");


    sshLoginTypeLabel = new QLabel("登陆方式：");
    sshSeionTypeLabel = new QLabel("会话类型：");
    sshUserNameLabel = new QLabel("用户名：");
    sshPasswdLabel = new QLabel("密   码：");
    sshPubkPathLabel = new QLabel("公钥路径：");
    sshIpAddressLabel = new QLabel("IP地址：");
    sshPortLabel = new QLabel("端口号：");
    sshLoginType = new QComboBox();
    sshLoginType->addItem("密码登录");
    sshLoginType->addItem("公钥登录");
    sshLoginType->setFixedSize(100,30);
    sshSeionType = new QComboBox();
    sshSeionType->addItem("命令会话");
    sshSeionType->addItem("文件会话");
    sshSeionType->setFixedSize(100,30);
    sshSeionType->setCurrentIndex(sessionType);

    sshUserName = new QLineEdit();
    sshUserName->setFixedSize(150,30);
    sshPasswd = new QLineEdit();
    sshPasswd->setFixedSize(150,30);
    sshPubkPath = new QLineEdit();
    sshPubkPath->setFixedSize(300,30);
    sshPubkPath->setEnabled(false);
    sshPubkPathBtn = new QPushButton("浏览");
    sshPubkPathBtn->setFixedSize(50,30);
    sshPubkPathBtn->setEnabled(false);

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
    sshBtnLayout = new QHBoxLayout();
    sshConnectBtn = new QPushButton("登录");
    sshConnectBtn->setFixedHeight(30);
    sshResetBtn = new QPushButton("重置");
    sshResetBtn->setFixedHeight(30);
    sshCancelBtn = new QPushButton("取消");
    sshCancelBtn->setFixedHeight(30);
    sshBtnLayout->addWidget(sshConnectBtn);
    sshBtnLayout->addWidget(sshResetBtn);
    sshBtnLayout->addWidget(sshCancelBtn);


    sshLogin->setLayout(sshLayout);
    sshLayout->addWidget(loginParamGroupBox);
    sshLayout->addWidget(algCheckGroupBox);
    sshLayout->addLayout(sshBtnLayout);

    loginParamGroupBox->setLayout(loginParamLayout);

    loginParamLayout->addLayout(sshLoginTypeLayout);
    loginParamLayout->addLayout(sshIpAddressPortLayout);
    loginParamLayout->addLayout(sshUserNamePasswdLayout);
    loginParamLayout->addLayout(sshPubkPathLayout);


    sshLoginTypeLayout->addWidget(sshLoginTypeLabel);
    sshLoginTypeLayout->addWidget(sshLoginType, 0, Qt::AlignLeft);
    sshLoginTypeLayout->addStretch();
    sshLoginTypeLayout->addWidget(sshSeionTypeLabel);
    sshLoginTypeLayout->addWidget(sshSeionType, 0, Qt::AlignRight);

    sshUserNamePasswdLayout->addWidget(sshUserNameLabel);
    sshUserNamePasswdLayout->addWidget(sshUserName, 0, Qt::AlignLeft);
    sshUserNamePasswdLayout->addStretch();
    sshUserNamePasswdLayout->addWidget(sshPasswdLabel, 0, Qt::AlignRight);
    sshUserNamePasswdLayout->addWidget(sshPasswd, 0, Qt::AlignRight);
    sshPubkPathLayout->addWidget(sshPubkPathLabel);
    sshPubkPathLayout->addWidget(sshPubkPath, 0, Qt::AlignLeft);
    sshPubkPathLayout->addWidget(sshPubkPathBtn, 0, Qt::AlignLeft);

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
    sshHostkeyAlgCheck->addItem("auto");
    sshHostkeyAlgCheck->addItem("rsa");
    sshHostkeyAlgCheck->setFixedSize(300,30);
    sshKexAlgCheck = new QComboBox();
    sshKexAlgCheck->addItem("auto");
    sshKexAlgCheck->addItem("rsa-sha1");
    sshKexAlgCheck->setFixedSize(300,30);
    sshCipherAlgCheck = new QComboBox();
    sshCipherAlgCheck->addItem("auto");
    sshCipherAlgCheck->addItem("aes");
    sshCipherAlgCheck->setFixedSize(300,30);
    sshMacAlgCheck = new QComboBox();
    sshMacAlgCheck->addItem("auto");
    sshMacAlgCheck->addItem("sha1");
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
        sshPubkPathBtn->setEnabled(false);
    }
    else{
        sshPasswd->setEnabled(false);
        sshPubkPath->setEnabled(true);
        sshPubkPathBtn->setEnabled(true);
    }
}

void QsshLoginDialog::sshLoginResetSlots(){
    sshUserName->setText("");
    sshIpAddress->setText("");
    sshPasswd->setText("");
    sshPubkPath->setText("");
    sshPort->setValue(22);
    sshLoginType->setCurrentIndex(0);
    sshSeionType->setCurrentIndex(0);
    sshHostkeyAlgCheck->setCurrentIndex(0);
    sshKexAlgCheck->setCurrentIndex(0);
    sshCipherAlgCheck->setCurrentIndex(0);
    sshMacAlgCheck->setCurrentIndex(0);
    sshPasswd->setEnabled(true);
    sshPubkPath->setEnabled(false);
    sshPubkPathBtn->setEnabled(false);
    sshSeionType->setCurrentIndex(sessionType);

}

void QsshLoginDialog::sshLoginSlots(){
    /*连接ssh
    ***如果连接成功则返回accept
    ***如果连接失败则报错
    */
    accept();
}

void QsshLoginDialog::sshCheckPubkPath(){
    QString file = QFileDialog::getOpenFileName(
        this,                       // 父窗口
        tr("选择文件"),             // 对话框标题
        QDir::homePath(),           // 默认打开的目录
        tr("密钥文件 (*.pub);;所有文件 (*)") // 文件过滤器
        );
    sshPubkPath->setText(file);
}


