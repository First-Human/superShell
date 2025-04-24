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


class QsshLoginDialog : public QDialog
{
    Q_OBJECT
public:
    explicit QsshLoginDialog(QWidget *parent = nullptr);


private:
    QVBoxLayout *loginLayout;
    QTabWidget *Login;
    QWidget *sshPasswdLogin, *sshPubKeyLogin, *telnetLogin;

    QLabel *passwdUserNameLabel, *passwdIpAddressLabel, *passwdPortLabel, *passwdPwdLabel;
    QLineEdit *passwdUserName, *passwdIpAddress, *passwdPwd;
    QSpinBox *passwdPort;
    QHBoxLayout *passwdUserNameLayout, *passwdIpAddressLayout, *passwdPortLayout, *passwdPwdLayout;
    QVBoxLayout *passwdLayout;
    QPushButton *passwdConnectBtn;

    QLabel *pkeyUserNameLabel, *pkeyIpAddressLabel, *pkeyPortLabel, *pkeyPathLabel;
    QLineEdit *pkeyUserName, *pkeyIpAddress, *pkeyPath;
    QSpinBox *pkeyPort;
    QHBoxLayout *pkeyUserNameLayout, *pkeyIpAddressLayout, *pkeyPortLayout, *pkeyPathLayout;
    QVBoxLayout *pkeyLayout;
    QPushButton *pkeyConnectBtn;

    QLabel *telnetUserNameLabel, *telnetIpAddressLabel, *telnetPortLabel, *telnetPwdLabel;
    QLineEdit *telnetUserName, *telnetIpAddress, *telnetPwd;
    QSpinBox *telnetPort;
    QHBoxLayout *telnetUserNameLayout, *telnetIpAddressLayout, *telnetPortLayout, *telnetPwdLayout;
    QVBoxLayout *telnetLayout;
    QPushButton *telnetConnectBtn;


    void createLoginWidget();
    void passwdLogin();
    void pubKeyLogin();
    void telLogin();

signals:
};

#endif // QLOGINDIALOG_H
