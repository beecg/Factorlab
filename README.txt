factorlab — bibliothèque de matrices et modèle factoriel (C++)

  CMakeList.txt                  Configuration de compilation CMake.
  include/factorlab/             En-têtes : Matrix.hpp, MatrixView.hpp,
                                 gemm.hpp, decompositions.hpp,
                                 factors.hpp, data.hpp.
  src/data.cpp                   Implémentation du chargement des données.
  tests/test_matrix.cpp          Tests de la classe Matrix.
  tests/test_decompositions.cpp  Tests des décompositions.
  tests/test_factors.cpp         Tests du modèle factoriel.
  bench/bench_gemm.cpp           Benchmark du produit matriciel (gemm).
  scripts/fetch_data.py          Récupération des données de prix.
  scripts/reference.py           Implémentation de référence en Python.
  data/prices.csv                Données de prix.
  build/                         Dossier de compilation (généré).

Énoncé du projet : ../../C++/02_projet1_factorlab.md.
