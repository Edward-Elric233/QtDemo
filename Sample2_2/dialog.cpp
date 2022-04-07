#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QObject::connect(ui->radioButtonBlack, &QRadioButton::clicked, this, &Dialog::setTextColor);
    QObject::connect(ui->radioButtonBlue, &QRadioButton::clicked, this, &Dialog::setTextColor);
    QObject::connect(ui->radioButtonRed, &QRadioButton::clicked, this, &Dialog::setTextColor);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_checkBoxUnderLine_clicked(bool checked)
{
    QFont font = ui->plainTextEdit->font();
    font.setUnderline(checked);
    ui->plainTextEdit->setFont(font);
}


void Dialog::on_checkBoxItalic_clicked(bool checked)
{
    QFont font = ui->plainTextEdit->font();
    font.setItalic(checked);
    ui->plainTextEdit->setFont(font);
}


void Dialog::on_checkBoxBold_clicked(bool checked)
{
    QFont font = ui->plainTextEdit->font();
    font.setBold(checked);
    ui->plainTextEdit->setFont(font);
}

void Dialog::setTextColor()
{
    QPalette plt = ui->plainTextEdit->palette();
    if (ui->radioButtonBlue->isChecked()) {
        plt.setColor(QPalette::Text, Qt::blue);
    } else if (ui->radioButtonRed->isChecked()) {
        plt.setColor(QPalette::Text, Qt::red);
    } else {
        plt.setColor(QPalette::Text, Qt::black);
    }
    ui->plainTextEdit->setPalette(plt);
}

