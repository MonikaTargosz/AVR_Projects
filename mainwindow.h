#include <QMainWindow>

namespace Ui{
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private slots:
	
	void on_pushButtonOK_clicked();
	
	void myCustomSlot();

private:
	Ui::MainWindow *ui;
};

#endif //MAINWINDOW_H
