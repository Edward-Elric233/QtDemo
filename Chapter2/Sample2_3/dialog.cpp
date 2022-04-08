#include "dialog.h"

#include <QHBoxLayout>
#include <QVBoxLayout>

void Dialog::initLayout()
{
    QHBoxLayout *fontLayout = new QHBoxLayout;
    fontLayout->addWidget(checkBoxUnderLine);
    fontLayout->addWidget(checkBoxItalic);
    fontLayout->addWidget(checkBoxBold);

    QHBoxLayout *colorLayout = new QHBoxLayout;
    colorLayout ->addWidget(radioButtonBlack);
    colorLayout ->addWidget(radioButtonBlue);
    colorLayout ->addWidget(radioButtonRed);

    QFont font = plainTextEdit->font();
    font.setPointSize(20);
    plainTextEdit->setFont(font);
    plainTextEdit->setPlainText("Hello world!\nThis is Edward.");

    QHBoxLayout *btnLayout = new QHBoxLayout;
    //Add SpaceItem
    btnLayout->addStretch();
    btnLayout ->addWidget(pushButtonOk);
    btnLayout ->addWidget(pushButtonCancle);
    btnLayout->addStretch();
    btnLayout ->addWidget(pushButtonClose);


    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addLayout(fontLayout);
    vLayout->addLayout(colorLayout);
    vLayout->addWidget(plainTextEdit);
    vLayout->addLayout(btnLayout);

    setLayout(vLayout);
}

void Dialog::initEvent()
{
    QObject::connect(pushButtonOk, &QPushButton::clicked, this, &Dialog::accept);
    QObject::connect(pushButtonCancle, &QPushButton::clicked, this, &Dialog::reject);
    QObject::connect(pushButtonClose, &QPushButton::clicked, this, &Dialog::close);

    QObject::connect(checkBoxUnderLine, &QPushButton::clicked, this, &Dialog::on_checkBoxUnderLine);
    QObject::connect(checkBoxItalic, &QPushButton::clicked, this, &Dialog::on_checkBoxItalic);
    QObject::connect(checkBoxBold, &QPushButton::clicked, this, &Dialog::on_checkBoxBold);

    QObject::connect(radioButtonBlack, &QPushButton::clicked, this, &Dialog::on_radioButton);
    QObject::connect(radioButtonBlue, &QPushButton::clicked, this, &Dialog::on_radioButton);
    QObject::connect(radioButtonRed, &QPushButton::clicked, this, &Dialog::on_radioButton);
}

void Dialog::on_checkBoxUnderLine(bool checked)
{
    QFont font = plainTextEdit->font();
    font.setUnderline(checked);
    plainTextEdit->setFont(font);
}

void Dialog::on_checkBoxItalic(bool checked)
{
    QFont font = plainTextEdit->font();
    font.setItalic(checked);
    plainTextEdit->setFont(font);
}

void Dialog::on_checkBoxBold(bool checked)
{
    QFont font = plainTextEdit->font();
    font.setBold(checked);
    plainTextEdit->setFont(font);
}

void Dialog::on_radioButton(bool clicked)
{
    QPalette plt = plainTextEdit->palette();
    if (radioButtonBlue->isChecked()) {
        plt.setColor(QPalette::Text, Qt::blue);
    } else if (radioButtonRed->isChecked()) {
        plt.setColor(QPalette::Text, Qt::red);
    } else {
        plt.setColor(QPalette::Text, Qt::black);
    }
    plainTextEdit->setPalette(plt);
}

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    //将字符串放到tr中以后生成翻译文件
    , checkBoxUnderLine(new QCheckBox(tr("Underline"), this))
    , checkBoxItalic(new QCheckBox(tr("Italic"), this))
    , checkBoxBold(new QCheckBox(tr("Bold"), this))
    , radioButtonBlack(new QRadioButton(tr("Black"), this))
    , radioButtonBlue(new QRadioButton(tr("Blue"), this))
    , radioButtonRed(new QRadioButton(tr("Red"), this))
    , plainTextEdit(new QPlainTextEdit(this))
    , pushButtonOk(new QPushButton(tr("Ok"), this))
    , pushButtonCancle(new QPushButton(tr("Cancle"), this))
    , pushButtonClose(new QPushButton(tr("Close"), this))
{
    initLayout();
    initEvent();
}

Dialog::~Dialog()
{
}

