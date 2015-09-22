#include "Screen.h"

using namespace std;


// define Window_mgr
void Window_mgr::clear(ScreenIndex i)
{
	Screen &s = screens[i];
	s.contents = string(s.height * s.width, ' ');
}