#ifndef MATERIAL_H_
#define MATERIAL_H_

/** \class Material
 * \brief Classe permettant de définir des matériaux à partir de sa couler et son coefficient de luminosité.
 * \details La couleur est uniforme et est définie avec le système RGB. Le coefficient de luminosité est compris entre 0 (objet mat)
 * et 1 (miroir).
 */
class Material {
public:
    /**
    * \brief Constructeur par défaut.
    * \details Créé un matériau noir mat. Les 3 composantes de couleurs et le coefficient de luminosité sont initialisés à 0.
    */
	Material();

	/**
    * \brief Constructeur.
    * \details Initialise les composantes de couleurs et le coefficient de luminosité avec les valeurs passées en argument.
    * \param r : Valeur initiale de la composante rouge r_ de la couleur.
    * \param g : Valeur initiale de la composante verte g_ de la couleur.
    * \param b : Valeur initiale de la composante bleue b_ de la couleur.
    * \param shininess : Valeur initiale du coefficient de luminosité shininess_.
    */
	Material(float r, float g, float b, float shininess);

	/**
    * \brief Destructeur.
    */
	~Material();

	/**
    * \brief Accesseur pour la composante de couleur bleue b_.
    * \return Un \e float contenant la valeur de la composante b_.
    */
	float getB() const {
		return b_;
	}

	/**
    * \brief Mutateur pour la composante de couleur bleue b_.
    * \param b : nouvelle valeur pour la composante b_.
    */
	void setB(float b) {
		b_ = b;
	}

	/**
    * \brief Accesseur pour la composante de couleur verte g_.
    * \return Un \e float contenant la valeur de la composante g_.
    */
	float getG() const {
		return g_;
	}

	/**
    * \brief Mutateur pour la composante de couleur verte g_.
    * \param g : nouvelle valeur pour la composante g_.
    */
	void setG(float g) {
		g_ = g;
	}

	/**
    * \brief Accesseur pour la composante de couleur rouge r_.
    * \return Un \e float contenant la valeur de la composante r_.
    */
	float getR() const {
		return r_;
	}

	/**
    * \brief Mutateur pour la composante de couleur rouge r_.
    * \param r : nouvelle valeur pour la composante r_.
    */
	void setR(float r) {
		r_ = r;
	}

	/**
    * \brief Accesseur pour le coefficient de luminosité shininess_.
    * \return Un \e float contenant la valeur du coefficient shininess_.
    */
	float getShininess() const {
		return shininess_;
	}

	/**
    * \brief Mutateur pour le coefficient de luminosité shininess_.
    * \param shininess : nouvelle valeur pour le coefficient shininess_.
    */
	void setShininess(float shininess) {
		shininess_ = shininess;
	}

private:
	float r_; /*!< Flottant représentant la composante rouge de la couleur*/
	float g_; /*!< Flottant représentant la composante verte de la couleur*/
	float b_; /*!< Flottant représentant la composante bleue de la couleur*/
	float shininess_; /*!< Flottant contenant la luminosité du matériau*/
};

#endif /* MATERIAL_H_ */
