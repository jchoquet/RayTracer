#ifndef VECTOR3F_H_
#define VECTOR3F_H_

/** \class Vector3f
 * \brief Vecteur 3D de flottants.
 */
class Vector3f {
public:
    /**
    * \brief Constructeur par défaut.
    * \details Initialise les 3 coordonnées à 0.
    */
	Vector3f();

	/**
    * \brief Constructeur.
    * \details Initialise les 3 coordonnées avec les valeurs passées en argument.
    * \param x Valeur initiale de la première composante.
    * \param y Valeur initiale de la seconde composante.
    * \param z Valeur initiale de la troisième composante.
    */
	Vector3f(float x, float y, float z);

	/**
    * \brief Destructeur.
    */
	~Vector3f();

    /**
    * \brief Accesseur pour la coordonnée x_.
    * \return Un \e float avec la valeur de la coordonnée x_.
    */
	float getX() const {
		return x_;
	}

	/**
    * \brief Mutateur pour la coordonnée x_.
    * \param x Nouvelle valeur de la coordonnée x_
    */
	void setX(float x) {
		x_ = x;
	}

    /**
    * \brief Accesseur pour la coordonnée y_.
    * \return Un \e float avec la valeur de la coordonnée y_.
    */
	float getY() const {
		return y_;
	}

    /**
    * \brief Mutateur pour la coordonnée y_.
    * \param y  Nouvelle valeur de la coordonnée y_.
    */
	void setY(float y) {
		y_ = y;
	}

    /**
    * \brief Accesseur pour la coordonnée z_.
    * \return Un \e float avec la valeur de la coordonnée z_.
    */
	float getZ() const {
		return z_;
	}

    /**
    * \brief Mutateur pour la coordonnée z_.
    * \param z Nouvelle valeur de la coordonnée z_.
    */
	void setZ(float z) {
		z_ = z;
	}

private:
	float x_; /*!< Première composante*/
	float y_; /*!< Deuxième composante*/
	float z_; /*!< Troisième composante*/
};

#endif /* VECTOR3F_H_ */
