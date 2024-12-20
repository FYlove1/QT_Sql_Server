#ifndef CUSTOMERINFODIALOG_H
#define CUSTOMERINFODIALOG_H

#include <QDialog>
#include <QString>
#include <QMap>

class QLineEdit;
class QComboBox;
class QPushButton;

// 定义客户信息结构体
struct CustomerInfo {
    int customerID;
    QString firstName;
    QString lastName;
    QString email;
    QString phoneNumber;
    QString address;
    QString driverLicenseNumber;
    QString membershipLevel;
};

class CustomerInfoDialog : public QDialog {
    Q_OBJECT

public:
    explicit CustomerInfoDialog(QWidget *parent = nullptr);
    ~CustomerInfoDialog() override;

    // 获取用户输入的客户信息
    CustomerInfo getCustomerInfo() const;
    QLineEdit *customerIDLineEdit;
    QLineEdit *firstNameLineEdit;
    QLineEdit *lastNameLineEdit;
    QLineEdit *emailLineEdit;
    QLineEdit *phoneNumberLineEdit;
    QLineEdit *addressLineEdit;
    QLineEdit *driverLicenseLineEdit;
    QComboBox *membershipLevelComboBox;
    // 用于存储用户输入的信息
    CustomerInfo currentCustomerInfo;
    private slots:
        void onAccepted();

private:


};

#endif // CUSTOMERINFODIALOG_H