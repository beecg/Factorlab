#include "factorlab/Matrix.hpp"
#include <iostream>

static int echecs = 0;

#define VERIFIE(cond) \
    do { \
        if (!(cond)) { \
            std::cerr << "ECHEC " << __FILE__ << ":" << __LINE__ \
                      << " " #cond "\n"; \
            ++echecs; \
        } \
    } while (false)

int main() {
    // C'est ici que tu écriras tes tests pour l'Étape 1.
    // Exemple bidon pour vérifier que le framework fonctionne :
    // VERIFIE(2 + 2 == 4);

    if (echecs == 0) {
        std::cout << "TOUS LES TESTS PASSENT\n";
        return 0;
    } else {
        std::cerr << echecs << " TEST(S) ECHOUE(NT)\n";
        return 1;
    }
}