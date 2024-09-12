#include <Black.h>

class White : public Black::Application
{
public:
    White()
    {
        
    }

    ~White()
    {
        
    }

    
};


Black::Application* Black::CreateApplication()
{
    return new White();
}