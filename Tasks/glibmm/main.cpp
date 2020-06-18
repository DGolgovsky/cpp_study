/*
 * Developed by Dmitry Golgovsky <d.westcoast@aol.com>
 *
 * Test linux/gnome notification
 *
 */

#include <giomm-2.4/giomm.h>

int main(int argc, char **argv) {
	auto Application = Gio::Application::create("hello.world", Gio::APPLICATION_FLAGS_NONE);
	Application->register_application();

	auto Notification = Gio::Notification::create("Hello world");
	Notification->set_body("This is an example notification.");

	auto Icon = Gio::ThemedIcon::create("dialog-information");
	Notification->set_icon(Icon);

	Application->send_notification(Notification);

	return 0;
}
