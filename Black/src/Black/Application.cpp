#include "Application.h"

#include "Black/Events/ApplicationEvent.h"
#include "Black/Log.h"

namespace Black
{
    void Application::run()
    {
        WindowResizeEvent e(1280, 720);
        BLACK_TRACE(e);
        while (true);
    }   
}
