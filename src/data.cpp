#include "include/factorlab/Matrix.hpp"
#include <stdexcept>


Matrix::Matrix(std::size_t lignes, std::size_t colonnes) : lignes_(lignes), colonnes_(colonnes),
                                                       data_((lignes * colonnes > 0) ? new double[lignes * colonnes]{} : nullptr){}
Matrix::Matrix(std::size_t lignes, std::size_t colonnes, double v) : lignes_(lignes), colonnes_(colonnes),
                                                                 data_((lignes * colonnes > 0) ? new double[lignes * colonnes] : nullptr){
                                                                    if (data_ != nullptr){
                                                                        std::fill(data_, data_+lignes*colonnes, v);
                                                                    }}
Matrix::Matrix(std::initializer_list<std::initializer_list<double>> init){
        lignes_=init.size();
        if (lignes_==0){
            colonnes_=0;
            data_=nullptr;
            return;
        }
        colonnes_ = init.begin()->size();
        if (colonnes_==0){
            data_=nullptr;
            return;
        }
        
        for (const auto& row : init){
            if (row.size()!=colonnes_){
                throw std::invalid_argument("Toutes les lignes ne sont pas de même dimension.");
            }
        }

        data_ = new double[lignes_*colonnes_];
        std::size_t colonne = 0;
        for (const auto& row : init){
            std::copy(row.begin(), row.end(), data_ + colonne);
            colonne += colonnes_;
        }

    }

Matrix::~Matrix(){delete[] data_;}
Matrix::Matrix(const Matrix& autre) : lignes_(autre.lignes_), colonnes_(autre.colonnes_){
    if (colonnes_*lignes_==0){
        data_ = nullptr;
    }
    else{
        
    }
 }
    Matrix& operator=(const Matrix& autre);
    Matrix(Matrix&& autre) noexcept;
    Matrix& operator=(Matrix&& autre) noexcept;

    
Matrix Matrix::identite(std::size_t n){Matrix inter(n, n); for(std::size_t i = 0; i<n;i++){inter(i, i)=1;} return inter;}

Matrix Matrix::depuisColonnes(const std::vector<std::vector<double>>& cols) {
    if (cols.empty()) {
        return Matrix(0, 0);
    }

    std::size_t colonnes = cols.size();
    std::size_t lignes = cols[0].size();

    for (std::size_t j = 0; j < colonnes; ++j) {
        if (cols[j].size() != lignes) {
            throw std::invalid_argument("Toutes les colonnes ne sont pas de même dimension.");
        }
    }

    Matrix resultat(lignes, colonnes);

    for (std::size_t j = 0; j < colonnes; ++j) {
        for (std::size_t i = 0; i < lignes; ++i) {
            resultat(i, j) = cols[j][i]; 
        }
    }

    return resultat;
}

std::size_t Matrix::lignes() const noexcept {return lignes_;}
std::size_t Matrix::colonnes() const noexcept {return colonnes_;}

double&       Matrix::operator()(std::size_t i, std::size_t j){
    assert(i<lignes_ && j < colonnes_);
    return data_[i*colonnes_ + j];
    }
const double& Matrix::operator()(std::size_t i, std::size_t j) const {
    assert(i<lignes_ && j < colonnes_);
    return data_[i*colonnes_ + j];
    }
double&       Matrix::at(std::size_t i, std::size_t j) {
    if (i >= lignes_ || j >= colonnes_) {
        throw std::out_of_range("Indices de matrice hors limites");
    }
    return data_[i * colonnes_ + j];
}

const double* Matrix::donnees() const noexcept {return data_;}

Matrix Matrix::transpose() const{
    std::size_t colonnes_t = lignes_;
    std::size_t lignes_t   = colonnes_;

    Matrix trans(lignes_t, colonnes_t);

    for (std::size_t ligne = 0; ligne<lignes_t; ligne++){
        for (std::size_t colonne = 0; colonne<colonnes_t; colonne++){
            trans(ligne, colonne) = (*this)(colonne, ligne);
        }
    }

    return trans;
}

std::ostream& operator<<(std::ostream& os, const Matrix& m){
    for (std::size_t ligne=0; ligne<m.lignes(); ligne++){
        os << '[ ';
        for (std::size_t colonne=0; colonne<m.colonnes(); colonne++){
            os << m(ligne, colonne) <<(colonne+1 < m.colonnes() ? " ": "");
        }
        os << ']\n';
    }
    return os;
}
