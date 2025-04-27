#ifndef QLOGINDIALOG_H
#define QLOGINDIALOG_H

#include <QObject>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpinBox>
#include <QComboBox>
#include <QGroupBox>


class QsshLoginDialog : public QDialog
{
    Q_OBJECT
public:
    explicit QsshLoginDialog(QWidget *parent = nullptr);


private:
    QVBoxLayout *loginLayout;
    QTabWidget *Login;
    QWidget *sshLogin, *telnetLogin;

    QLabel *sshUserNameLabel, *sshIpAddressLabel, *sshPortLabel, *sshPasswdLabel, *sshPubkPathLabel, *sshLoginTypeLabel;
    QLineEdit *sshUserName, *sshIpAddress, *sshPasswd, *sshPubkPath;
    QLabel *sshHostkeyAlgLabel, *sshKexAlgLabel, *sshCiherAlgLabel, *sshMacAlgLabel;
    QComboBox *sshLoginType, *sshHostkeyAlgCheck, *sshKexAlgCheck, *sshCipherAlgCheck, *sshMacAlgCheck;
    QSpinBox *sshPort;
    QHBoxLayout *sshLoginTypeLayout, *sshUserNamePasswdLayout, *sshIpAddressPortLayout, *sshPubkPathLayout;
    QHBoxLayout *sshHostkeyAlgLayout, *sshKexAlgLayout, *sshCipherAlgLayout, *sshMacAlgLayout;
    QVBoxLayout *sshLayout, *loginParamLayout, *algParamLayout;
    QPushButton *sshConnectBtn;
    QGroupBox *loginParamGroupBox, *algCheckGroupBox;



    QLabel *telnetUserNameLabel, *telnetIpAddressLabel, *telnetPortLabel, *telnetPwdLabel;
    QLineEdit *telnetUserName, *telnetIpAddress, *telnetPwd;
    QSpinBox *telnetPort;
    QHBoxLayout *telnetUserNameLayout, *telnetIpAddressLayout, *telnetPortLayout, *telnetPwdLayout;
    QVBoxLayout *telnetLayout;
    QPushButton *telnetConnectBtn;


    void createLoginWidget();
    void sshLoginWidget();
    void telLoginWidget();

signals:

public slots:
    void sshLoginTypeSlots(int index);



};

#endif // QLOGINDIALOG_H
