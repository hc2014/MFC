#include "FirstQt.h"
#include <QtWidgets/QApplication>
#include "QLabel.h";
#include "QPushButton.h";
#include "QSpinBox.h";
#include "qlayout.h";
#include "QTextCodec";
#include "FindDialog.h";
#include "Test.h"

int main(int argc, char *argv[])
{
	//QApplication app(argc, argv);

	union 布局
	{
		//QTextCodec *codec = QTextCodec::codecForName("GB2312");
	//QTextCodec::setCodecForLocale(codec);


	//QWidget *window = new QWidget;
	//window->setWindowTitle("Enter Your Age");
	//QSpinBox *spinBox = new QSpinBox;
	//QSlider *slider = new QSlider(Qt::Horizontal);
	//spinBox->setRange(0, 130);
	//slider->setRange(0, 130);
	//QObject::connect(spinBox, SIGNAL(valueChanged(int)),
	//	slider, SLOT(setValue(int)));
	//QObject::connect(slider, SIGNAL(valueChanged(int)),
	//	spinBox, SLOT(setValue(int)));

	//spinBox->setValue(35);


	//QGridLayout *layout = new QGridLayout;
	//layout->addWidget(spinBox,0,0);
	//layout->addWidget(slider,0,1);

	///*QLabel *lable = new QLabel("<h2>你好啊,<font color=red>我叫李雷</font></h2>");*/

	//QLabel *lable = new QLabel("你好啊");
	//	layout->addWidget(lable, 1, 1);

	//window->setLayout(layout);
	//window->show();
	};


	QApplication app(argc, argv);
	/* FindDialog *dialog = new FindDialog;*/

	TestDialog *dialog = new TestDialog;
	dialog->setupUi(dialog);
	dialog->show();

	return app.exec();
}
