#ifndef RENTED_CONFIRM_AND_TIME_SET_DIALOG_H
#define RENTED_CONFIRM_AND_TIME_SET_DIALOG_H

#include <QDialog>
#include <QStringList>
#include <QPair>
#include <QSpinBox>
class Rented_Confirm_And_Time_Set_Dialog : public QDialog {
    Q_OBJECT

public:
    explicit Rented_Confirm_And_Time_Set_Dialog(const QStringList &rowData, QWidget *parent = nullptr);
    ~Rented_Confirm_And_Time_Set_Dialog();

    // 返回用户输入的租赁时长（月和日）
    QPair<int, int> getSelectedDuration() const;

    // 获取选中的行数据
    QStringList getRowData() const;

private:
    QStringList m_rowData;
    QStringList m_labels;
    QSpinBox *m_monthSpin;  // 月选择器
    QSpinBox *m_daySpin;    // 日选择器
};

#endif // RENTED_CONFIRM_AND_TIME_SET_DIALOG_HD_TIME_SET_DIALOG_H