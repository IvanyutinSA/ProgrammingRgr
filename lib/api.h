# ifndef API_H
# define API_H

#include <functional>
#include <string>
using namespace std;

class NonlinearAPI {
    public:
        void invoke(function<float(float)> f);
};
class IntegralAPI {
    public:
        void invoke(function<float(float)> f);
};
class FunctionAPI {
    public:
        void invoke(function<float(float)> f, string action_name);
    private:
        void table(function<float(float)> f);
        void plot(function<float(float)> f);
};

# endif
