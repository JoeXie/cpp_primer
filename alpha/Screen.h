/*************************
this file define class Screen and Window_mgr,
use Window_mgr to control Screen.
*************************/
#include <string>
#include <vector>

class Screen;  // forward declaration, will be difined later.

/**********************
class Window_mgr
**********************/
class Window_mgr
{
public:
	//constructor
	Window_mgr();
	//members
	using ScreenIndex = std::vector<Screen>::size_type;
	void clear(ScreenIndex i);

private:
	std::vector<Screen> screens;
};

/************************
class Screen
*************************/
class Screen
{
	friend void Window_mgr::clear(ScreenIndex i);
	//friend Window_mgr;

public:
	typedef std::string::size_type pos;
	//construtors
	Screen() = default;
	Screen(pos ht, pos wd) :
		height(ht), width(wd), contents(ht*wd, ' ') {}
	Screen(pos ht, pos wd, char c) :
		height(ht), width(wd), contents(ht*wd, c) {}
	//members
	char get() const
	{
		return contents[cursor];
	}
	inline char get(pos ht, pos wd) const;
	Screen &move(pos r, pos c);
	Screen &set(char ch);
	Screen &set(pos r, pos col, char ch);
	Screen &display(std::ostream &os)
	{
		do_display(os);
		return *this;
	}
	const Screen &display(std::ostream &os) const
	{
		do_display(os);
		return *this;
	}
	pos size() const;

private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
	void do_display(std::ostream &os) const
	{
		os << contents;
	}

};

/*****************************
define Window_mgr
******************************/
inline Window_mgr::Window_mgr() : screens({ Screen(24, 80, ' ') })
{ }

/******************************
define Screen
*******************************/
inline Screen& Screen::move(pos r, pos c)
{
	pos row = r * width;
	cursor = row + c;
	return *this;
}

inline char Screen::get(pos r, pos c) const
{
	pos row = r * width;
	return contents[row + c];
}

inline Screen &Screen::set(char ch)
{
	contents[cursor] = ch;
	return *this;
}

inline Screen &Screen::set(pos r, pos col, char ch)
{
	contents[r*width + col] = ch;
	return *this;
}

inline Screen::pos Screen::size() const
{
	return height * width;
}