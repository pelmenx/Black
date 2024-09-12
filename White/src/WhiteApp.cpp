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
int main()
{
    White* white = new White();
    white->run();
    delete white;
}