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
#include <QFileDialog>


class QsshLoginDialog : public QDialog
{
    Q_OBJECT
public:
    QsshLoginDialog(int loginSessionType, QWidget *parent = nullptr);


private:
    int sessionType;
    QVBoxLayout *loginLayout;
    QTabWidget *Login;
    QWidget *sshLogin, *telnetLogin;

    QLabel *sshUserNameLabel, *sshIpAddressLabel, *sshPortLabel, *sshPasswdLabel, *sshPubkPathLabel, *sshLoginTypeLabel, *sshSeionTypeLabel;
    QLineEdit *sshUserName, *sshIpAddress, *sshPasswd, *sshPubkPath;
    QLabel *sshHostkeyAlgLabel, *sshKexAlgLabel, *sshCiherAlgLabel, *sshMacAlgLabel;
    QComboBox *sshLoginType, *sshSeionType, *sshHostkeyAlgCheck, *sshKexAlgCheck, *sshCipherAlgCheck, *sshMacAlgCheck;
    QSpinBox *sshPort;
    QHBoxLayout *sshLoginTypeLayout, *sshUserNamePasswdLayout, *sshIpAddressPortLayout, *sshPubkPathLayout;
    QHBoxLayout *sshHostkeyAlgLayout, *sshKexAlgLayout, *sshCipherAlgLayout, *sshMacAlgLayout;
    QVBoxLayout *sshLayout, *loginParamLayout, *algParamLayout;
    QHBoxLayout *sshBtnLayout;
    QPushButton *sshConnectBtn, *sshResetBtn, *sshCancelBtn, *sshPubkPathBtn;
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
    void emitQDialogSignals();

public slots:
    void sshLoginTypeSlots(int index);
    void sshLoginResetSlots();
    void sshCheckPubkPath();
    void sshLoginSlots();



};

#endif // QLOGINDIALOG_H
