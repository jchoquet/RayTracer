#include <cstdint>
#include <ostream>

#ifndef SRC_PIXEL_H_
#define SRC_PIXEL_H_

/** \class Pixel
 * \brief Classe permettant de un pixel coloré.
 * \details La couleur du pixel est définie grâce au système RGB avec le codage en octets (valeur entre 0 et 255).
 */
class Pixel {
public:
    /**
    * \brief Constructeur par défaut.
    * \details Initialise les 3 octets (rouge, vert, bleu) à 0.
    */
	Pixel();

	/**
    * \brief Constructeur.
    * \details Initialise les 3 nivaux de couleurs avec ceux passés en arguments.
    * \param r : Valeur initiale pour l'octet associé au rouge r_.
    * \param g : Valeur initiale pour l'octet associé au vert g_.
    * \param b : Valeur initiale pour l'octet associé au bleu b_.
    */
	Pixel(uint8_t r, uint8_t g, uint8_t b);

	/**
    * \brief Constructeur de copie.
    * \param pixel : Référence vers le Pixel à copier.
    */
	Pixel(const Pixel & pixel);

	/**
    * \brief Destructeur.
    */
	~Pixel();

    /**
    * \brief Accesseur pour le niveau de bleu b_.
    * \return Un \e uint8_t avec la valeur de l'octet associé au niveau de bleu b_.
    */
	uint8_t getB() const {
		return b_;
	}

	/**
    * \brief Mutateur pour le niveau de bleu b_.
    * \param b_ : nouvelle valeur pour l'octet associé au niveau de bleu b_.
    */
	void setB(uint8_t b) {
		b_ = b;
	}

	/**
    * \brief Accesseur pour le niveau de vert g_.
    * \return Un \e uint8_t avec la valeur de l'octet associé au niveau de vert v_.
    */
	uint8_t getG() const {
		return g_;
	}

	/**
    * \brief Mutateur pour le niveau de vert v_.
    * \param b_ : nouvelle valeur pour l'octet associé au niveau de vert v_.
    */
	void setG(uint8_t g) {
		g_ = g;
	}

	/**
    * \brief Accesseur pour le niveau de rouge r_.
    * \return Un \e uint8_t avec la valeur de l'octet associé au niveau de rouge r_.
    */
	uint8_t getR() const {
		return r_;
	}

	/**
    * \brief Mutateur pour le niveau de rouge r_.
    * \param b_ : nouvelle valeur pour l'octet associé au niveau de rouge r_.
    */
	void setR(uint8_t r) {
		r_ = r;
	}

	/**
    * \brief TODO
    * \param level : TODO
    */
	void luminosity(double level);

	/**
    * \brief Opérateur d'affectation.
    * \param pixel : Une référence constante vers le pixel que l'on souhaite copier.
    */
	Pixel & operator=(const Pixel & pixel);

	/**
    * \brief Opérateur de flux pour l'affichage.
    * \details Méthode amie permettant d'afficher un pixel sous le format [r,v,b].
    * \param st : Une référence vers le flux où l'on souhaite afficher le pixel.
    * \param pixel : Une référence constante vers le pixel à afficher.
    * \return Une référence vers un flux #ostream contenant l'affichage du pixel.
    */
	friend std::ostream & operator << (std::ostream & st, const Pixel & pixel);

private:
	uint8_t r_; /*!< Niveau de rouge du pixel*/
	uint8_t g_; /*!< Niveau de vert du pixel*/
	uint8_t b_; /*!< Niveau de bleu du pixel*/
};

#endif /* SRC_PIXEL_H_ */
