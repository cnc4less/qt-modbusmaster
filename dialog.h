#ifndef DIALOG_H
#define DIALOG_H

#include "switchbutton.h"
#include <QHBoxLayout>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QComboBox>
#include <QGroupBox>
#include <QDialog>
#include <QList>
#include <QLabel>
#include <QMessageBox>
#include <QSerialPort>
#include <QSerialPortInfo>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

protected:
    void translate();
    bool port_open();
    bool port_close();

private:
    bool	port_status;
    QVBoxLayout *v_layout;
    QHBoxLayout *h_layout;

    QGroupBox 	*port_setting_group_box;
    QHBoxLayout *port_setting_layout;
    QLabel		*port_label;
    QComboBox *port_combox;
    QLabel 		*baud_label;
    QComboBox *baud_combox;
    QPushButton *button_open_close;

    QGroupBox 	*do_setting_group_box;
    QList<SwitchButton *> switch_button_list;
    QGridLayout *do_setting_layout;

signals:
    void setDoStatus(int, bool);

public slots:
    void onButtonClicked();

};

#endif // DIALOG_H
