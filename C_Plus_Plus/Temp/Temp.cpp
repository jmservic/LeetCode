#include <iostream>

template<class... Types, typename Func>
void BindTo(Func callback, Types... args)
{
    callback(args...);
};

int printProduct(int x, int y)
{
    std::cout << x * y << std::endl;
    return x * y;
}

int main(int argc, char ** args)
{
    BindTo(printProduct, 5, 4, 3);
}