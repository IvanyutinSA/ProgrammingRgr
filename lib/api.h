# ifndef API_H
# define API_H

#include <functional>
using namespace std;

class NonlinearAPI {
    public:
        void invoke(function<float(float)> f);
};
class IntegralAPI {
    public:
        void invoke(function<float(float)> f);
};

# endif
