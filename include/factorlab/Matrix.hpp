class Matrix{
public:
    Matrix(std::size_t lignes, std::size_t colonnes);
    Matrix(std::size_t lignes, std::size_t colonnes, double v);
    Matrix(std::initializer_list<std::initializer_list<double>>);

    ~Matrix();
    Matrix(const Matrix& autre);
    Matrix& operator=(const Matrix& autre);
    Matrix(Matrix&& autre) noexcept;
    Matrix& operator=(Matrix&& autre) noexcept;

    static Matrix identite(std::size_t n);
    static Matrix depuisColonnes(const std::vector<std::vector<double>>&);

    std::size_t lignes()   const noexcept;
    std::size_t colonnes() const noexcept;

    double&       operator()(std::size_t i, std::size_t j);
    const double& operator()(std::size_t i, std::size_t j) const;
    double&       at(size_t i, size_t j);

    const double* donnees() const noexcept;

    Matrix transpose() const;

private:
    std::size_t lignes_, colonnes_;
    double*     data_;
};

std::ostream& operator<<(std::ostream& os, const Matrix& m);