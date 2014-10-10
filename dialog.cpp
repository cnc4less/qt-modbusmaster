#include "dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent)
{
    this->setFixedSize(320, 220);
    port_status = false;

    port_setting_group_box = new QGroupBox;
    port_label = new QLabel;
    port_combox = new QComboBox;
    baud_label = new QLabel;
    baud_combox = new QComboBox;
    button_open_close = new QPushButton;
    this->connect(button_open_close, SIGNAL(clicked()), this, SLOT(onButtonClicked()));

    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        port_combox->addItem(info.portName());
    }

    port_setting_layout = new QHBoxLayout(port_setting_group_box);

    v_layout = new QVBoxLayout;
    v_layout->addWidget(port_label);
    v_layout->addWidget(port_combox);
    v_layout->addStretch();
    port_setting_layout->addLayout(v_layout);

    v_layout = new QVBoxLayout;
    v_layout->addWidget(baud_label);
    v_layout->addWidget(baud_combox);
    v_layout->addStretch();
    port_setting_layout->addLayout(v_layout);

    port_setting_layout->addWidget(button_open_close, 0, Qt::AlignBottom);

    switch_button_list.clear();

    do_setting_group_box = new QGroupBox;
    do_setting_layout = new QGridLayout(do_setting_group_box);
    do_setting_layout->setSpacing(8);
    for (int i = 0; i < 8; i++) {
        v_layout = new QVBoxLayout;

        QLabel *label = new QLabel;
        label->setText(tr("Output") + QString::number(i + 1));

        SwitchButton *switch_button = new SwitchButton;
        switch_button_list.append(switch_button);

        int row = i / 4;
        int col = i % 4;

        v_layout->addWidget(label);
        v_layout->addWidget(switch_button);

        do_setting_layout->addLayout(v_layout, row, col);
    }

    v_layout = new QVBoxLayout(this);
    v_layout->addWidget(port_setting_group_box);
    v_layout->addWidget(do_setting_group_box);

    this->translate();
}

Dialog::~Dialog()
{
}

void Dialog::translate()
{
    port_label->setText(tr("Port ID"));
    baud_label->setText(tr("Baud Rate"));
    port_setting_group_box->setTitle(tr("Serial Port Setting"));
    do_setting_group_box->setTitle(tr("Digital Output Setting"));
    button_open_close->setText(tr("Open"));
}

void Dialog::onButtonClicked()
{
    if (port_status) {
        if (port_close()) {
            port_status = false;
            button_open_close->setText(tr("Open"));
        } else {
            QMessageBox::critical(this, tr("Fail To Close Port!"), tr("OK"));
        }
    } else {
        if (port_open()){
            port_status = true;
            button_open_close->setText(tr("Close"));
        } else {
            QMessageBox::critical(this, tr("Fail To Open Port!"), tr("OK"));
        }
    }
}

bool Dialog::port_open()
{
    return true;
}

bool Dialog::port_close()
{
    return true;
}
