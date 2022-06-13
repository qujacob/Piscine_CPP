#include "Zombie.hpp"

int main(void) {
    Zombie  z("Gilbert");
    z.announce();
    randomChump("Terry");
    Zombie  *z1 = newZombie("John");
    z1->announce();
    randomChump("Terry2");
    Zombie  *z2 = newZombie("John2");
    randomChump("Terry3");
    z2->announce();
    delete z1;
    delete z2;
    return (0);
}
