#include "rented_confirm_and_time_set_dialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QDialogButtonBox>
#include <QDebug>

Rented_Confirm_And_Time_Set_Dialog::Rented_Confirm_And_Time_Set_Dialog(const QStringList &rowData, QWidget *parent)
    : QDialog(parent), m_rowData(rowData), m_labels({"车辆ID", "品牌", "型号", "年份", "车牌号", "颜色", "座位数", "类型", "状态", "日租金"}) {
    // 设置对话框标题
    setWindowTitle("确认租赁并设置时长");

    // 创建主布局
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // 显示选中行的详细信息
    for (int i = 0; i < m_rowData.size(); ++i) {
        QHBoxLayout *rowLayout = new QHBoxLayout();
        QLabel *label = new QLabel(m_labels[i] + ":");
        QLineEdit *lineEdit = new QLineEdit(m_rowData[i]);
        lineEdit->setReadOnly(true);  // 只读，防止用户修改
        rowLayout->addWidget(label);
        rowLayout->addWidget(lineEdit);
        mainLayout->addLayout(rowLayout);
    }

    // 添加时长选择器
    QHBoxLayout *durationLayout = new QHBoxLayout();
    QLabel *monthLabel = new QLabel("租赁月数：");
    m_monthSpin = new QSpinBox();
    m_monthSpin->setMinimum(0);
    m_monthSpin->setMaximum(12);  // 最多可以选择12个月
    QLabel *dayLabel = new QLabel("租赁天数：");
    m_daySpin = new QSpinBox();
    m_daySpin->setMinimum(0);
    m_daySpin->setMaximum(31);  // 最多可以选择31天
    durationLayout->addWidget(monthLabel);
    durationLayout->addWidget(m_monthSpin);
    durationLayout->addWidget(dayLabel);
    durationLayout->addWidget(m_daySpin);
    mainLayout->addLayout(durationLayout);

    // 添加按钮框
    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
    mainLayout->addWidget(buttonBox);
}

Rented_Confirm_And_Time_Set_Dialog::~Rented_Confirm_And_Time_Set_Dialog() {
    // 不需要显式删除控件，Qt 会自动处理
}

// 返回用户输入的租赁时长（月和日）
QPair<int, int> Rented_Confirm_And_Time_Set_Dialog::getSelectedDuration() const {
    return qMakePair(m_monthSpin->value(), m_daySpin->value());
}

// 获取选中的行数据
QStringList Rented_Confirm_And_Time_Set_Dialog::getRowData() const {
    return m_rowData;
}