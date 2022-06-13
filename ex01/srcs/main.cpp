#include "Zombie.hpp"

#define NB_TERRY 13
#define NB_JOHN 3

int main(void) {
    Zombie  *z1 = zombieHorde(NB_TERRY, "Terry");
    for (int i = 0; i < NB_TERRY; i++)
		z1[i].announce();
    delete [] z1;
    Zombie  *z2 = zombieHorde(NB_JOHN, "John");
    for (int i = 0; i < NB_JOHN; i++)
        z2[i].announce();
    delete [] z2;
    return (0);
}