#pragma once

#include "stdafx.h"
#include "Emu/Memory/vm.h"
#include "Emu/Cell/Modules/cellMsgDialog.h"
#include "Emu/System.h"
#include "Emu/Memory/Memory.h"
#include "Emu/Cell/lv2/sys_time.h"

#include <QPushButton>
#include <QStaticText>
#include <QDialog>
#include <QInputDialog>
#include <QFormLayout>
#include <QProgressBar>
#include <QLabel>
#include <QButtonGroup>
#include <QLineEdit>
#include <QKeyEvent>

#ifdef _WIN32
#include <QWinTaskbarProgress>
#include <QWinTaskbarButton>
#include <QWinTHumbnailToolbar>
#include <QWinTHumbnailToolbutton>
#endif

class custom_dialog;

class msg_dialog_frame : public QObject, public MsgDialogBase
{
	Q_OBJECT

#ifdef _WIN32
	QWinTaskbarButton* m_tb_button = nullptr;
	QWinTaskbarProgress* m_tb_progress = nullptr;
#endif
	custom_dialog* m_dialog =nullptr;
	QLabel* m_text = nullptr;
	QLabel* m_text1 = nullptr;
	QLabel* m_text2 = nullptr;
	QPushButton* m_button_ok = nullptr;
	QPushButton* m_button_yes = nullptr;
	QPushButton* m_button_no = nullptr;
	QProgressBar* m_gauge1 = nullptr;
	QProgressBar* m_gauge2 = nullptr;

	custom_dialog* osk_dialog = nullptr;
	char16_t* osk_text_return;

	const int m_gauge_max = 100;

public:
	msg_dialog_frame(QWindow* taskbarTarget);
	~msg_dialog_frame();
	virtual void Create(const std::string& msg) override;
	virtual void CreateOsk(const std::string& msg, char16_t* osk_text) override;
	virtual void ProgressBarSetMsg(u32 progressBarIndex, const std::string& msg) override;
	virtual void ProgressBarReset(u32 progressBarIndex) override;
	virtual void ProgressBarInc(u32 progressBarIndex, u32 delta) override;
private:
	QWindow* m_taskbarTarget;	// Window which will be targeted by custom taskbars.
};

class custom_dialog : public QDialog
{
	Q_OBJECT

	bool m_disable_cancel;
public:
	explicit custom_dialog(bool disableCancel, QWidget* parent = 0)
		: QDialog(parent), m_disable_cancel(disableCancel)
	{
		setWindowIcon(QIcon(":/rpcs3.ico"));

		if (m_disable_cancel)
		{
			setWindowFlags(windowFlags() & ~Qt::WindowCloseButtonHint);
		}
	}
private:
	void keyPressEvent(QKeyEvent* event)
	{
		// this won't work with Alt+F4, the window still closes
		if (m_disable_cancel && event->key() == Qt::Key_Escape)
		{
			event->ignore();
		}
		else
		{
			QDialog::keyPressEvent(event);
		}
	}
	void closeEvent(QCloseEvent* event)
	{
		// spontaneous: don't close on external system level events like Alt+F4
		if (m_disable_cancel && event->spontaneous())
		{
			event->ignore();
		}
		else
		{
			QDialog::closeEvent(event);
		}
	}
};
