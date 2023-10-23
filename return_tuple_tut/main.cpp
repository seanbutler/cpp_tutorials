#include <iostream>
#include <tuple>

std::tuple<double, double, double, std::string> init_entity(std::string name) {
    return std::make_tuple(0.0, 0.0, 0.0, name);
}

int main() {
    auto [x, y, z, name] = init_entity("avatar");
    std::cout << name << " at (" << x << ", " << y << ", " << z << ")" <<std::endl;
    return 0;
}