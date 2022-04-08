# 可视化UI设计

## 项目介绍

实现了一个可以通过点击按钮来控制文本框字体和颜色的对话框。

字体通过复选框进行选择，颜色通过单选框进行选择

<img src="./2022-04-07 16-43-33屏幕截图.png" style="zoom:67%;" />

## 经验总结

- 通过实现这个简单的项目，了解了如何进行简单的可视化UI设计。

- 明白了ui文件是通过XML的形式进行组织，然后再将其转换成对应的头文件，我们通过引用对应的头文件实现对组件的控制。

- 通过调用`QMetaObject::connectSlotByName()`我们可以不直接调用`QObject::connect`而是通过函数名实现槽函数和信号的连接。

- 学习了如何设置文本框字体的颜色：

```cpp
QPalette plt = ui->plainTextEdit->palette();
plt.setColor(QPalette::Text, Qt::black);
ui->plainTextEdit->setPalette(plt);
```

